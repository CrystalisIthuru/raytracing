#pragma once

#include <Eigen/Core>
#include <raytracing/math/Ray.h>

namespace raytracing {
namespace shapes {

class Sphere {

    Eigen::Vector3d _center;
    double _radius;

public:

    /**
        @param center The centerpoint of the sphere.
        @param radius The radius of the sphere.
    **/
    Sphere(const Eigen::Vector3d &center, double radius);

    /**
        @returns The centerpoint of the sphere.
    **/
    const Eigen::Vector3d& center() const;

    /**
        Determines whether the provided ray will intersect the
        sphere.

        @param ray Any ray
        @returns True if the ray intersects the sphere at any
            point.
    **/
    bool hit(const math::Ray &ray) const;

    /**
        @returns The radius of the sphere.
    **/
    double radius() const;

};

}
}