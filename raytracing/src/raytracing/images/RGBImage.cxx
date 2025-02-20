#include <raytracing/images/RBGImage.h>

namespace raytracing {
namespace images {

RGBImage::RGBImage(unsigned int image_width, unsigned int image_height)
    : _image_height(image_height)
    , _image_width(image_width)
    , _image(Image::Zero(image_height, image_width))
{}


void RGBImage::toPPM(std::ostream &stream) {
    stream << "P3" << std::endl;
    stream << _image_width << " " << _image_height << std::endl;
    stream << 255 << std::endl;
    for(int i = 0; i < _image_height; ++i) {
        for(int j = 0; j < _image_width; ++j) {
            stream << (unsigned int) _image(i, j).r << " "
                   << (unsigned int) _image(i, j).g << " "
                   << (unsigned int) _image(i, j).b << " ";
        }
        stream << std::endl;
    }
}

unsigned int RGBImage::height() const {
    return _image_height;
}
    
Image& RGBImage::image() {
    return _image;
}

unsigned int RGBImage::width() const {
    return _image_width;
}

}
}