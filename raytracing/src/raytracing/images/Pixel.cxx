#include <raytracing/images/Pixel.h>

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

}
}
