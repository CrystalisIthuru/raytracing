#pragma once

#include <raytracing/images/Pixel.h>
#include <raytracing/materials/Material.h>

namespace raytracing {
namespace materials {

class Lambertian : public Material {

    /** Fractional Reflectance **/
    Eigen::Vector3d albedo;

public:

    /**
        @param albedo The fractional reflectance.
    **/
    Lambertian(const Eigen::Vector3d &albedo);

    bool scatter(
        const math::Ray &ray, const shapes::HitRecord &record,
        Eigen::Vector3d &attenuation, math::Ray &scattered
    ) const override;

};

}
}