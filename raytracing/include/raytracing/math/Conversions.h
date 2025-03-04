#pragma once

#include <math.h>

namespace raytracing {
namespace math {

inline double radians(double deg) {
    return (deg * M_PI) / 180.0;
}

}
}