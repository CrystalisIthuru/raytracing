#include <filesystem>
#include <fstream>

#include <Eigen/Core>

#include <raytracing/images/RBGImage.h>
#include <raytracing/math/Ray.h>
#include <raytracing/scene/Camera.h>

int main(int argc, char **argv) {

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

    // Render
    raytracing::images::RGBImage image(image_width, image_height);
    for(int i = 0; i < image.height(); ++i) {
        for(int j = 0; j < image.width(); ++j) {

            // Determine the pixel color value by blending white to a
            // sky blue color.
            Eigen::Vector3d white; white << 1.0, 1.0, 1.0;
            Eigen::Vector3d blue; blue << 0.5, 0.7, 1.0;
            Eigen::Vector3d unit_direction = camera.rays()(i, j).unit_direction();
            double a = 0.5 * (unit_direction(1) + 1.0);
            image.image()(i, j) = raytracing::images::Pixel((1.0 - a) * white + a * blue);
        }
    }

    if(!std::filesystem::is_directory("images")) {
        std::filesystem::create_directory("images");
    }
    std::fstream output;
    output.open("images/4.2_SendingRaysIntoTheScene.ppm", std::ios_base::out);
    image.toPPM(output);
    output.close();

    return 0;
}