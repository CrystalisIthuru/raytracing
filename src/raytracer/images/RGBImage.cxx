#include <raytracer/images/RBGImage.h>

namespace raytracer {
namespace images {

RGBImage::RGBImage(unsigned int image_width, unsigned int image_height)
    : _image_height(image_height)
    , _image_width(image_width)
    , _image(new Pixel[image_height * image_width])
{}
    
RGBImage::~RGBImage() {
    delete _image;
}

Pixel& RGBImage::operator()(int i, int j) const {
    return _image[i * _image_width + j];
}

void RGBImage::toPPM(std::ostream &stream) {
    stream << "P3" << std::endl;
    stream << _image_width << " " << _image_height << std::endl;
    stream << 255 << std::endl;
    for(int i = 0; i < _image_height; ++i) {
        for(int j = 0; j < _image_width; ++j) {
            stream << (int) (*this)(i, j).r << " " << (int) (*this)(i, j).g << " " << (int) (*this)(i, j).b << " ";
        }
        stream << std::endl;
    }
}

unsigned int RGBImage::height() const {
    return _image_height;
}

unsigned int RGBImage::width() const {
    return _image_width;
}

}
}