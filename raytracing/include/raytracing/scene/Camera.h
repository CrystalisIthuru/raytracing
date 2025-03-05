#pragma once
#include <functional>
#include <memory>

#include <Eigen/Core>

#include <raytracing/images/RBGImage.h>
#include <raytracing/math/Ray.h>
#include <raytracing/shapes/Hittable.h>

namespace raytracing {
namespace scene {

typedef Eigen::Matrix<math::Ray, Eigen::Dynamic, Eigen::Dynamic> CameraRays;
typedef std::function<images::Pixel(const shapes::Hittable &work, const math::Ray &ray)> ColorFunc;

/** A camera with a viewpoint. **/
class Camera {

    /** The camera's center position within the scene. **/
    Eigen::Vector3d camera_center;

    /** The focal length of the camera used to place the viewport. **/
    double focal_length;

    /** The horizontal FOV of the camera. **/
    double fov;

    /** The actual image height [pixels]. **/
    int image_height;

    /** The actual image width [pixels]. **/
    int image_width;

    /** The number of samples to take for anti-aliasing. **/
    int samples_antialiasing = 1;

    /**
        The position of the top-left pixel in the viewport within
        scene.
    **/
    Eigen::Vector3d pixel_00;

    /** The horizontal distance between pixels in the viewport. **/
    Eigen::Vector3d pixel_delta_u;

    /** The vertical distance between pixels in the viewport. **/
    Eigen::Vector3d pixel_delta_v;

    /**
        Retrieves the ray from the camera center through pixel (i, j)
        in the veiwport.
    **/
    math::Ray getRay(int i, int j) const;

public:

    /**
        @param center The centerpoint for the camera
        @param focal_length The distance infront of the camera the
            viewpoint will be placed.
        @param fov The horizontal field of view [degrees]
        @param image_height The image height [pixels]
        @param image_width  The image width [pixels]
    **/
    Camera(
        const Eigen::Vector3d &center,
        double focal_length,
        double fov,
        int image_height,
        int image_width
    );

    /**
        Sets the number of samples taken during the render step for
        anti-aliasing
    **/
    void set_samples_antialiasing(int samples);

    /**
        Renders the image the camera can see of the world.

        @param world A list of hittables to render.
        @param colorer A function that takes a hittable and ray and returns what color
            that pixel should be.
        @returns A pointer to an RGB image or nullptr on failure.
    **/
    images::RGBImage render(const shapes::Hittable &world, const ColorFunc &colorer) const;

};

}
}