#pragma once

#include <Eigen/Core>

namespace raytracing {
namespace math {

/**
    Multiplies the two vectors together component-wise.

    @param left Any vector
    @param right Any Vector
    @returns A new vector that is the product of left and right.
**/
Eigen::Vector3d componentMultiply(
    const Eigen::Vector3d left,
    const Eigen::Vector3d right
);

/**
    Reflects vector v using surface normal n.

    @param v Any vector
    @param n Any unit vector
**/
Eigen::Vector3d reflect(const Eigen::Vector3d &v, const Eigen::Vector3d &n);

/**
    Determines if a vector is near zero.

    @param v Any vector
    @param tol The tolerance
**/
bool nearZero(const Eigen::Vector3d &v, double tol);

}
}