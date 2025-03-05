#pragma once

#include <Eigen/Core>
#include <ostream>
#include <stdint.h>

namespace raytracing {
namespace images {

struct Pixel {

    uint8_t r, g, b;

    /** Initializes a black pixel. **/
    Pixel();

    /** Initializes a pixel by it's hex value. **/
    Pixel(unsigned int hex);

    /** Initializes a pixel by it's components. **/
    Pixel(uint8_t r, uint8_t g, uint8_t b);

    /**
        Initializes a pixel from a color vector where the components
        range from [0.0, 1.0]
    **/
    Pixel(const Eigen::Vector3d &v);

};

std::ostream& operator<<(std::ostream &stream, const Pixel &pixel);

}
}
