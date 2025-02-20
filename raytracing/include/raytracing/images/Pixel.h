#pragma once

#include <stdint.h>

namespace raytracing {
namespace images {

struct Pixel {

    uint8_t r, g, b;

    Pixel();
    Pixel(unsigned int hex);
    Pixel(uint8_t r, uint8_t g, uint8_t b);

};

}
}
