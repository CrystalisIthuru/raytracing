#pragma once

#include <raytracing/math/Interval.h>
#include <raytracing/math/Ray.h>
#include <raytracing/shapes/HitRecord.h>

namespace raytracing {
namespace shapes {

/** A shape that a ray can hit. **/
class Surface {
public:

    /**
        Determines whether the provided ray will intersect the
        shape.

        @param ray Any ray
        @param tvalid An interval of where to consider valid ray intersection values.
        @param record A HitRecord to fill with information about the hit
        @returns True if the ray hits the surface, false otherwise.
    **/
    virtual bool hit(
        const math::Ray &ray,
        const math::Interval &tvalid,
        HitRecord &record
    ) const = 0;

};

}
}