#include <raytracing/math/Ray.h>

namespace raytracing {
namespace math {

Ray::Ray()
    : _origin(Eigen::Vector3d::Zero())
    , _direction(Eigen::Vector3d::Zero())
{}

Ray::Ray(const Eigen::Vector3d &origin, const Eigen::Vector3d &direction)
    : _origin(origin)
    , _direction(direction)
{}
    
Eigen::Vector3d Ray::at(double t) const {
    return _origin + t * _direction;
}

const Eigen::Vector3d& Ray::origin() const {
    return _origin;
}

const Eigen::Vector3d& Ray::direction() const {
    return _direction;
}
    
Eigen::Vector3d Ray::unit_direction() const {
    return _direction / _direction.norm();
}

}
}
