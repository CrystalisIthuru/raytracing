#pragma once

#include <raytracing/images/Pixel.h>
#include <Eigen/Core>

namespace raytracing {
namespace images {

typedef Eigen::Matrix<Pixel, Eigen::Dynamic, Eigen::Dynamic> Image;

class RGBImage {

    unsigned int _image_height;
    unsigned int _image_width;
    Image _image;

public:

    RGBImage(unsigned int image_width, unsigned int image_height);

    /**
        Writes the image as a PPM images to the stream.

        @param stream The output stream
    **/
    void toPPM(std::ostream &stream);

    // Getters
    Image& image();
    unsigned int height() const;
    unsigned int width() const;

};

}
}
