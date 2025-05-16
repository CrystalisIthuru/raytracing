#include <iostream>
#include <thread>
#include <mutex>
#include <deque>

#include <raytracing/math/Conversions.h>
#include <raytracing/math/Random.h>
#include <raytracing/scene/Camera.h>

namespace raytracing {
namespace scene {

Camera::Camera(
    const Eigen::Vector3d &center,
    double focal_length,
    double fov,
    int image_height,
    int image_width
)
    : camera_center(center)
    , focal_length(focal_length)
    , fov(fov)
    , image_height(image_height)
    , image_width(image_width)
{

    // Calculate the viewpoint width from the FOV.
    double theta = math::radians(fov);
    double viewpoint_width = 2 * focal_length * std::tan(theta / 2.0);

    // Calculates the viewpoint height within the same aspect
    // ratio as the output image.
    double viewpoint_height = viewpoint_width * ((double) image_height) / image_width;

    Eigen::Vector3d viewpoint_u, viewpoint_v;
    viewpoint_u << viewpoint_width, 0.0, 0.0;
    viewpoint_v << 0.0, -viewpoint_height, 0.0;

    pixel_delta_u = viewpoint_u / image_width;
    pixel_delta_v = viewpoint_v / image_height;

    // Calculate where the top-left corner of the viewpoint within the scene
    Eigen::Vector3d focal_length_vector; focal_length_vector << 0.0, 0.0, focal_length;
    Eigen::Vector3d viewpoint_upper_left = camera_center - focal_length_vector - viewpoint_u / 2.0 - viewpoint_v / 2.0;

    // Calculate the upper left pixel within the viewpoint.
    pixel_00 = viewpoint_upper_left + 0.5 * (pixel_delta_u + pixel_delta_v);

}

math::Ray Camera::getRay(int i, int j) const {

    Eigen::Vector3d offset;
    if(samples_antialiasing == 1) {
        offset = Eigen::Vector3d::Zero();
    } else {
        offset << math::Random::uniform(-0.5, 0.5),
                  math::Random::uniform(-0.5, 0.5),
                  0.0;
    }

    Eigen::Vector3d pixel_center = pixel_00 + ((j + offset(1)) * pixel_delta_u) + ((i + offset(0)) * pixel_delta_v);
    Eigen::Vector3d ray_direction = pixel_center - camera_center;
    return math::Ray(camera_center, ray_direction);
}
    
void Camera::set_ray_childen_max_depth(unsigned int max) {
    ray_children_max_depth = max;
}

void Camera::set_samples_antialiasing(unsigned int samples) {
    samples_antialiasing = samples;
}

images::RGBImage Camera::render(const shapes::Surface &world, const ColorFunc &colorer) const {

    std::vector<std::shared_ptr<std::thread>> threads;
    
    images::RGBImage image(image_width, image_height);
    std::recursive_mutex image_mutex;

    std::deque<std::tuple<int, int>> locs;
    std::recursive_mutex locs_mutex;
    for(int i = 0; i < image.height(); ++i) {
        for(int j = 0; j < image.width(); ++j) {
            locs.push_back(std::make_tuple(i, j));
        }
    }

    for(int i = 0; i < 20; ++i) {
        std::shared_ptr<std::thread> thread = std::make_shared<std::thread>(
            [this, &image_mutex, &image, &locs_mutex, &locs, &world, colorer] () {

                while(true) {

                    // Retrive the next pixel location to process.
                    int i, j;
                    {
                        std::lock_guard<std::recursive_mutex> lock(locs_mutex);
                        if(locs.size() == 0) return;
                        std::tuple<int, int> loc = locs.front();
                        locs.pop_front();
                        i = std::get<0>(loc);
                        j = std::get<1>(loc);
                    }

                    std::cout << "Pixel: " << i << " " << j << std::endl;
                    
                    // Pixel only allows for values between 0 and 255. While sampling
                    // we need to accumulate all the intensity values and then scale
                    // them back down for anti-aliasing
                    Eigen::Vector3d color = Eigen::Vector3d::Zero();
                    for(int k = 0; k < samples_antialiasing; ++k) {
                        color += colorer(world, getRay(i, j), 0, ray_children_max_depth);
                    }
                    {
                        std::lock_guard<std::recursive_mutex> lock(image_mutex);
                        image.image()(i, j) = images::Pixel(color / samples_antialiasing);
                    }

                }
            }
        );
        threads.push_back(thread);
    }

    for(std::shared_ptr<std::thread> thread : threads) {
        thread->join();
    }

    return image;

}


}
}
