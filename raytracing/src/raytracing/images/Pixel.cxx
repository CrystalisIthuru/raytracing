#include <raytracing/images/Pixel.h>
#include <raytracing/math/Interval.h>

namespace raytracing {
namespace images {
    
Pixel::Pixel() : r(0), g(0), b(0) {}

Pixel::Pixel(unsigned int hex)
    : r((hex & 0xFF0000) >> 16)
    , g((hex & 0x00FF00) >> 8)
    , b(hex & 0x0000FF)
{}

Pixel::Pixel(uint8_t r, uint8_t g, uint8_t b)
    : r(r)
    , g(g)
    , b(b)
{}
    
Pixel::Pixel(const Eigen::Vector3d &v) {

    const static math::Interval intensity(0.0, 0.999);
    r = int(256 * intensity.clamp(v(0)));
    g = int(256 * intensity.clamp(v(1)));
    b = int(256 * intensity.clamp(v(2)));
}

std::ostream& operator<<(std::ostream &stream, const Pixel &pixel) {
    stream << "<Pixel " << (int) pixel.r << " " << (int) pixel.g << " " << (int) pixel.b << ">";
    return stream;
}

}
}
