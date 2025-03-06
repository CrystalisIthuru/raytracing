#include <raytracing/math/VectorHelpers.h>
#include <cmath>

namespace raytracing {
namespace math {

Eigen::Vector3d componentMultiply(
    const Eigen::Vector3d left,
    const Eigen::Vector3d right
) {
    return Eigen::Vector3d(
        left(0) * right(0),
        left(1) * right(1),
        left(2) * right(2)
    );
}

Eigen::Vector3d reflect(const Eigen::Vector3d &v, const Eigen::Vector3d &n) {
    return v -  2 * v.dot(n) * n;
}

bool nearZero(const Eigen::Vector3d &v, double tol) {
    return (std::fabs(v(0)) < tol) && (std::fabs(v(1)) < 0) && (std::fabs(v(2)) < 0);
}

}
}
