#pragma once

#include <raytracer/images/Pixel.h>
#include <Eigen/Core>

namespace raytracer {
namespace images {

class RGBImage {

    unsigned int _image_height;
    unsigned int _image_width;
    Pixel *_image; // An n x m array of pixels

public:

    RGBImage(unsigned int image_width, unsigned int image_height);
    ~RGBImage();

    /**
        Accesses the Pixel in the ith row and the jth column. The 0, 0
        pixel is in the top left corner.
    **/
    Pixel& operator()(int i, int j) const;

    /**
        Writes the image as a PPM images to the stream.

        @param stream The output stream
    **/
    void toPPM(std::ostream &stream);

    // Getters
    unsigned int height() const;
    unsigned int width() const;

};

}
}
