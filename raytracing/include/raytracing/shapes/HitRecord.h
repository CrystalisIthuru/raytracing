#pragma once

#include <Eigen/Core>

namespace raytracing {
namespace shapes {

struct HitRecord {
    
    /** The point where the ray intersects the surface. **/
    Eigen::Vector3d p;

    /** The normal of `p` on the surface. **/
    Eigen::Vector3d n;

    /**
        The distance 't' from the ray origin when the ray
        intesects the surface.
    **/
    double t;

};

}
}