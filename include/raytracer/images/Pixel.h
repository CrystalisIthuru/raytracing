#pragma once

#include <stdint.h>

namespace raytracer {
namespace images {

struct Pixel {

    uint8_t r, g, b;

    Pixel();
    Pixel(uint8_t r, uint8_t g, uint8_t b);

};

}
}
