#pragma once

#include <raytracing/images/Pixel.h>
#include <raytracing/materials/Material.h>

namespace raytracing {
namespace materials {

class Metal : public Material {

    Eigen::Vector3d albedo;
    double fuzz;

public:

    Metal(const Eigen::Vector3d &albdeo, double fuzz);

    bool scatter(
        const math::Ray &ray, const shapes::HitRecord &record,
        Eigen::Vector3d &attenuation, math::Ray &scattered
    ) const override;


};

}
}