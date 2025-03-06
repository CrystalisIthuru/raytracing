#include <raytracing/materials/Metal.h>
#include <raytracing/math/VectorHelpers.h>
#include <raytracing/math/Random.h>

namespace raytracing {
namespace materials {

Metal::Metal(const Eigen::Vector3d &albedo, double fuzz)
    : albedo(albedo)
    , fuzz(fuzz)
{}


bool Metal::scatter(
    const math::Ray &ray, const shapes::HitRecord &record,
    Eigen::Vector3d &attenuation, math::Ray &scattered
) const {

    Eigen::Vector3d reflected = math::reflect(ray.direction(), record.n) + (fuzz * math::Random::uniform_unit_vector());
    scattered = math::Ray(record.p, reflected);
    attenuation = albedo;
    return true;

}

}
}