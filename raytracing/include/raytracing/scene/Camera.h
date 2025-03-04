#pragma once

#include <Eigen/Core>
#include <raytracing/math/Ray.h>

namespace raytracing {
namespace scene {

typedef Eigen::Matrix<math::Ray, Eigen::Dynamic, Eigen::Dynamic> CameraRays;

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

    /** The location of the top-left pixel in the viewpoint. **/
    Eigen::Vector3d pixel_00;

    /** The horizontal distance between pixels in the viewpoint. **/
    Eigen::Vector3d pixel_delta_u;

    /** The vertical distance between pixels in the viewpoint. **/
    Eigen::Vector3d pixel_delta_v;

    /**
        A matrix of rays going through the viewpoint into a scene.
        Ray (0, 0) is the top left corner of the viewpoint.
    **/
    CameraRays _rays;

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
        @return All rays through the viewport.
    **/
    const CameraRays& rays() const {
        return _rays;
    }

};

}
}