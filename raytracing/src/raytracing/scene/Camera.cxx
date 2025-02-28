#include <raytracing/scene/Camera.h>

namespace raytracing {
namespace scene {

Camera::Camera(
    const Eigen::Vector3d &center,
    double focal_length,
    int image_height,
    int image_width
)
    : camera_center(center)
    , focal_length(focal_length)
    , image_height(image_height)
    , image_width(image_width)
{

    // Calculates where the viewpoint is within the scene.
    double viewpoint_height = 2.0;
    double viewpoint_width = viewpoint_height * ((double) image_width) / image_height;

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

    // Create Rays from the camera center through each pixel within the
    // viewport.
    _rays = CameraRays(image_height, image_width);
    for(int i = 0; i < image_height; ++i) {
        for(int j = 0; j < image_width; ++j) {
            Eigen::Vector3d pixel_center = pixel_00 + (j * pixel_delta_u) + (i * pixel_delta_v);
            Eigen::Vector3d ray_direction = pixel_center - camera_center;
            _rays(i, j) = math::Ray(camera_center, ray_direction);
        }
    }

}

}
}
