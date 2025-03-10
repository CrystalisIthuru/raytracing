#pragma once

#include <Eigen/Core>
#include <raytracing/math/Ray.h>
#include <raytracing/shapes/Hittable.h>

namespace raytracing {
namespace shapes {

class Sphere : public Hittable {

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
        shape.

        @param ray Any ray
        @param tvalid An interval of where to consider valid ray intersection values.
        @param record A HitRecord to fill with information about the hit
        @returns True if the ray hits the surface, false otherwise.
    **/
    virtual bool hit(
        const math::Ray &ray,
        const math::Interval &tvalid,
        HitRecord &record
    ) const;

    /**
        @returns The radius of the sphere.
    **/
    double radius() const;

};

}
}