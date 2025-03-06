#pragma once

#include <raytracing/images/Pixel.h>
#include <raytracing/math/Ray.h>
#include <raytracing/shapes/HitRecord.h>

namespace raytracing {
namespace materials {

class Material {
public:

    virtual bool scatter(
        const math::Ray &ray, const shapes::HitRecord &record,
        Eigen::Vector3d &attenuation, math::Ray &scattered
    ) const;

};

}
}