#include <raytracing/materials/Lambertian.h>
#include <raytracing/math/Random.h>
#include <raytracing/math/VectorHelpers.h>

namespace raytracing {
namespace materials {

Lambertian::Lambertian(const Eigen::Vector3d &albedo)
    : albedo(albedo)
{}

bool Lambertian::scatter(
    const math::Ray &ray, const shapes::HitRecord &record,
    Eigen::Vector3d &attenuation, math::Ray &scattered
) const {

    Eigen::Vector3d scatter_direction = record.n + math::Random::uniform_unit_vector();

    // Catch degenerate scatter direction
    if(math::nearZero(scatter_direction, 1.0e-8)) {
        scatter_direction = record.n;
    }

    scattered = math::Ray(record.p, scatter_direction);
    attenuation = albedo;
    return true;

}

}
}