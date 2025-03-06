#include <raytracing/materials/Material.h>

namespace raytracing {
namespace materials {

bool Material::scatter(
        const math::Ray &ray, const shapes::HitRecord &record,
        Eigen::Vector3d &attenuation, math::Ray &scattered
) const {
    return false;
}

}
}