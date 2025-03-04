#include <raytracing/shapes/Sphere.h>

namespace raytracing {
namespace shapes {

Sphere::Sphere(const Eigen::Vector3d &center, double radius)
    : _center(center)
    , _radius(radius)
{}

const Eigen::Vector3d& Sphere::center() const {
    return _center;
}

bool Sphere::hit(const math::Ray &ray) const {
    Eigen::Vector3d oc = _center - ray.origin();
    auto a = ray.direction().dot(ray.direction());
    auto b = -2.0 * ray.direction().dot(oc);
    auto c = oc.dot(oc) - std::pow(_radius, 2.0);
    double discriminant = b * b - 4 * a * c;
    return discriminant >= 0;
}

double Sphere::radius() const {
    return _radius;
}


}
}