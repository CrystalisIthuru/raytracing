#include <filesystem>
#include <fstream>
#include <iostream>

#include <Eigen/Core>

#include <raytracing/images/RBGImage.h>
#include <raytracing/math/Interval.h>
#include <raytracing/math/Random.h>
#include <raytracing/math/Ray.h>
#include <raytracing/scene/Camera.h>
#include <raytracing/shapes/HittableList.h>
#include <raytracing/shapes/Sphere.h>

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
    camera.set_samples_antialiasing(10);

    raytracing::shapes::HittableList world({
        std::make_shared<raytracing::shapes::Sphere>(Eigen::Vector3d(0.0, 0.0, -1.0), 0.5),
        std::make_shared<raytracing::shapes::Sphere>(Eigen::Vector3d(0, -100.5, -1.0), 100)
    });

    raytracing::images::RGBImage image = camera.render(
        world,
        [] (const raytracing::shapes::Hittable &world, const raytracing::math::Ray &ray) -> raytracing::images::Pixel {

            raytracing::shapes::HitRecord record;
            raytracing::math::Interval tvalid(0.0, raytracing::math::infinity);
            if(world.hit(ray, tvalid, record)) {
                return raytracing::images::Pixel(0.5 * (record.n + Eigen::Vector3d::Ones()));
            } else {

                // Determine the pixel color value by blending white to a
                // sky blue color.
                Eigen::Vector3d white; white << 1.0, 1.0, 1.0;
                Eigen::Vector3d blue; blue << 0.5, 0.7, 1.0;
                Eigen::Vector3d unit_direction = ray.unit_direction();
                double a = 0.5 * (unit_direction(1) + 1.0);
                return raytracing::images::Pixel((1.0 - a) * white + a * blue);

            }
        }
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