#include <fstream>
#include <iostream>
#include <filesystem>

#include <raytracing/images/RBGImage.h>

int main(int argc, char **argv) {

    if(!std::filesystem::is_directory("images")) {
        std::filesystem::create_directory("images");
    }

    // 2.1 - The PPM Image Format Example
    raytracing::images::RGBImage simple(3, 2);
    simple.image() << 0xFF0000, 0x00FF00, 0x0000FF,
                      0xFFFF00, 0xFFFFFF, 0x000000; 

    std::fstream simple_ppm;
    simple_ppm.open("images/simple.ppm", std::ios_base::out);
    simple.toPPM(simple_ppm);
    simple_ppm.close();

    raytracing::images::RGBImage gradient(256, 256);
    for(int j = 0; j < gradient.height(); ++j) {
        for(int i = 0; i < gradient.width(); ++i) {
            double r = (double) i / (gradient.width() - 1);
            double g = (double) j / (gradient.height() - 1);
            double b = 0.0;

            gradient.image()(j, i).r = (int) 255.999 * r;
            gradient.image()(j, i).g = (int) 255.999 * g;
            gradient.image()(j, i).b = (int) 255.999 * b;
        }
    }

    std::fstream gradient_ppm;
    gradient_ppm.open("images/gradient.ppm", std::ios_base::out);
    gradient.toPPM(gradient_ppm);
    gradient_ppm.close();

    return 0;
}