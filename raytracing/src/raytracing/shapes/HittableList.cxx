#include <raytracing/math/Constants.h>
#include <raytracing/shapes/HittableList.h>

namespace raytracing {
namespace shapes {

HittableList::HittableList() {}

HittableList::HittableList(const std::vector<std::shared_ptr<Hittable>> &objects)
    : objects(objects)
{}

void HittableList::add(std::shared_ptr<Hittable> object) {
    objects.push_back(object);
}

void HittableList::clear() {
    objects = std::vector<std::shared_ptr<Hittable>>();
}

bool HittableList::hit(
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