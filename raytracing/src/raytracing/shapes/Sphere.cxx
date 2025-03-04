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

bool Sphere::hit(
    const math::Ray &ray, const math::Interval &tvalid, HitRecord &record
) const {

    Eigen::Vector3d oc = _center - ray.origin();
    auto a = ray.direction().norm() * ray.direction().norm();
    auto h = ray.direction().dot(oc);
    auto c = oc.norm() * oc.norm() - _radius * _radius;
    double discriminant = h * h - a * c;

    if(discriminant < 0) {
        return false;
    };
    
    // Find the nearest root in the acceptable range.
    double sqrtd = std::sqrt(discriminant);
    double root = (h - sqrtd) / a;
    if(!tvalid.contains(root)) {
        root = (h + sqrtd) / a;
        if(!tvalid.contains(root)) {
            return false;
        }
    }

    record.t = root;
    record.p = ray.at(record.t);
    record.n = (record.p - _center) / _radius;

    return true;
    
}

double Sphere::radius() const {
    return _radius;
}


}
}