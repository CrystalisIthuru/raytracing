#pragma once

#include <raytracing/math/Constants.h>

namespace raytracing {
namespace math {

/** A closed interval. **/
class Interval {

    double _min;
    double _max;

public:

    static const Interval empty;
    static const Interval universe;

    Interval(double min, double max);

    /**
        @param x A real number
        @returns Whether a number is within the interval.
    **/
    bool contains(double x) const;

    /**
        @returns The lower bound of the interval.
    **/
    double min() const;

    /**
        @returns The upper bound of the interval.
    **/
    double max() const;

};

}
}