#include <filesystem>
#include <fstream>
#include <iostream>

#include <Eigen/Core>

#include <raytracing/images/RBGImage.h>
#include <raytracing/materials/Lambertian.h>
#include <raytracing/materials/Metal.h>
#include <raytracing/math/Interval.h>
#include <raytracing/math/Random.h>
#include <raytracing/math/Ray.h>
#include <raytracing/math/VectorHelpers.h>
#include <raytracing/scene/Camera.h>
#include <raytracing/shapes/Sphere.h>
#include <raytracing/shapes/SurfaceList.h>

static double gamma2_correct(double x) {
    if(x > 0) {
        return std::sqrt(x);
    } else {
        return 0.0;
    }
}

static Eigen::Vector3d sphere_colorer(
    const raytracing::shapes::Surface &world,
    const raytracing::math::Ray &ray,
    unsigned int depth,
    unsigned int max_depth
) {

    if(depth >= max_depth) {
        return Eigen::Vector3d::Zero();
    }

    raytracing::shapes::HitRecord record;
    raytracing::math::Interval tvalid(0.001, raytracing::math::infinity);
    if(world.hit(ray, tvalid, record)) {
        
        raytracing::math::Ray scattered;
        Eigen::Vector3d attenuation;
        Eigen::Vector3d color;

        if(record.mat->scatter(ray, record, attenuation, scattered)) {
            Eigen::Vector3d next_color = sphere_colorer(world, scattered, depth + 1, max_depth);
            color = raytracing::math::componentMultiply(attenuation, next_color);
        } else {
            color = Eigen::Vector3d::Zero();
        }
        
        // Perform gamma2 correction on final resulting pixel
        if(depth == 0) {
            Eigen::Vector3d gamma(
                gamma2_correct(color(0)),
                gamma2_correct(color(1)),
                gamma2_correct(color(2))
            );
            return gamma;
        } else {
            return color;
        }
    } else {

        // Determine the pixel color value by blending white to a
        // sky blue color.
        Eigen::Vector3d white; white << 1.0, 1.0, 1.0;
        Eigen::Vector3d blue; blue << 0.5, 0.7, 1.0;
        Eigen::Vector3d unit_direction = ray.unit_direction();
        double a = 0.5 * (unit_direction(1) + 1.0);
        return (1.0 - a) * white + a * blue;

    }
}

int main(int argc, char **argv) {

    raytracing::math::Random::setSeed(1234);

    const double aspect_ratio = 16.0 / 9.0;
    const int image_width = 400;

    // Calculate the image height, and ensure that it's at least 1.
    int image_height = (int) (image_width / aspect_ratio);
    image_height = image_height < 1 ? 1 : image_height;

    // Camera
    raytracing::scene::Camera camera(
        Eigen::Vector3d::Zero(),
        1.0,
        120.0,
        image_height,
        image_width
    );
    camera.set_samples_antialiasing(100);
    camera.set_ray_childen_max_depth(50);

    auto material_ground = std::make_shared<raytracing::materials::Lambertian>(Eigen::Vector3d({0.8, 0.8, 0.0}));
    auto material_center = std::make_shared<raytracing::materials::Lambertian>(Eigen::Vector3d({0.1, 0.2, 0.5}));
    auto material_left   = std::make_shared<raytracing::materials::Metal>(Eigen::Vector3d({0.8, 0.8, 0.8}), 0.3);
    auto material_right  = std::make_shared<raytracing::materials::Metal>(Eigen::Vector3d({0.8, 0.6, 0.2}), 1.0);

    raytracing::shapes::SurfaceList world({
        std::make_shared<raytracing::shapes::Sphere>(Eigen::Vector3d(0, -100.5, -1.0), 100, material_ground),
        std::make_shared<raytracing::shapes::Sphere>(Eigen::Vector3d(0.0, 0.0, -1.2), 0.5, material_center),
        std::make_shared<raytracing::shapes::Sphere>(Eigen::Vector3d(-1.0, 0.0, -1.0), 0.5, material_left),
        std::make_shared<raytracing::shapes::Sphere>(Eigen::Vector3d(1.0, 0.0, -1.0), 0.5, material_right),
    });

    raytracing::images::RGBImage image = camera.render(
        world,
        sphere_colorer
    );

    if(!std::filesystem::is_directory("images")) {
        std::filesystem::create_directory("images");
    }
    std::fstream output;
    output.open("images/sphere.ppm", std::ios_base::out);
    image.toPPM(output);
    output.close();

    return 0;
}