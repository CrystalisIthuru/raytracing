#include <raytracer/images/Pixel.h>

namespace raytracer {
namespace images {

Pixel::Pixel() : r(0), g(0), b(0) {}

Pixel::Pixel(uint8_t r, uint8_t g, uint8_t b)
    : r(r)
    , g(g)
    , b(b)
{}

}
}
