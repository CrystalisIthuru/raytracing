#pragma once

#include <memory>
#include <vector>

#include <raytracing/shapes/Surface.h>

namespace raytracing {
namespace shapes {


class SurfaceList : public Surface {

    std::vector<std::shared_ptr<Surface>> objects;

public:

    SurfaceList();
    SurfaceList(const std::vector<std::shared_ptr<Surface>> &objects);

    /**
        Adds a hittable to the list.

        @param object A pointer to a hittable
    **/
    void add(std::shared_ptr<Surface> object);

    /** Removes all hittables from the list **/
    void clear();

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
    ) const;


};


}
}