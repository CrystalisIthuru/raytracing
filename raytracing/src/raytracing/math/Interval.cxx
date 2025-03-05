#include <raytracing/math/Interval.h>

namespace raytracing {
namespace math {

const Interval empty(infinity, -infinity);
const Interval universe(-infinity, infinity);

Interval::Interval(double min, double max)
    : _min(min)
    , _max(max)
{}

double Interval::clamp(double x) const {
    if(x < _min) return _min;
    if(x > _max) return _max;
    return x;
}

bool Interval::contains(double x) const {
    return _min <= x && x <= _max;
}

double Interval::min() const {
    return _min;
}

double Interval::max() const {
    return _max;
}

}
}