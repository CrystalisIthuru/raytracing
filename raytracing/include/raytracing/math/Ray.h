#pragma once

#include <Eigen/Core>

namespace raytracing {
namespace math {

class Ray {

    Eigen::Vector3d _origin;
    Eigen::Vector3d _direction;

public:

    Ray();
    Ray(const Eigen::Vector3d &origin, const Eigen::Vector3d &direction);

    /**
        @param t Units along the ray.
        @returns The position `t` units along the ray.
    **/
    Eigen::Vector3d at(double t) const;

    /**
        @returns The ray's origin position
    **/
    const Eigen::Vector3d& origin() const;

    /**
        @returns The ray's direction
    **/
    const Eigen::Vector3d& direction() const;

    /**
        @returns The ray's direction as a unit vector.
    **/
    Eigen::Vector3d unit_direction() const;

};

}
}
