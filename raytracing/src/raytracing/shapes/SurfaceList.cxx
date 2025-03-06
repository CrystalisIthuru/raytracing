#include <raytracing/math/Constants.h>
#include <raytracing/shapes/SurfaceList.h>

namespace raytracing {
namespace shapes {

SurfaceList::SurfaceList() {}

SurfaceList::SurfaceList(const std::vector<std::shared_ptr<Surface>> &objects)
    : objects(objects)
{}

void SurfaceList::add(std::shared_ptr<Surface> object) {
    objects.push_back(object);
}

void SurfaceList::clear() {
    objects = std::vector<std::shared_ptr<Surface>>();
}

bool SurfaceList::hit(
    const math::Ray &ray, const math::Interval &tvalid, HitRecord &record
) const {

    record.t = math::infinity;
    bool has_hit = false;
    for(auto object : objects) {
        HitRecord temp;
        if(object->hit(ray, tvalid, temp) && temp.t < record.t) {
            record = temp;
            has_hit = true;
        }
    }
    return has_hit;

}

}
}