#include <fstream>
#include <iostream>
#include <raytracer/images/RBGImage.h>

int main(int argc, char **argv) {

    // 2.1 - The PPM Image Format Example
    raytracer::images::RGBImage simple(3, 2);
    simple(0, 0).r = 255;
    simple(0, 1).g = 255;
    simple(0, 2).b = 255;
    simple(1, 0).r = 255;
    simple(1, 0).g = 255;
    simple(1, 1).r = 255;
    simple(1, 1).g = 255;
    simple(1, 1).b = 255;

    std::fstream simple_ppm;
    simple_ppm.open("simple.ppm", std::ios_base::out);
    simple.toPPM(simple_ppm);
    simple_ppm.close();

    raytracer::images::RGBImage gradient(256, 256);
    for(int j = 0; j < gradient.height(); ++j) {
        for(int i = 0; i < gradient.width(); ++i) {
            double r = (double) i / (gradient.width() - 1);
            double g = (double) j / (gradient.height() - 1);
            double b = 0.0;

            gradient(j, i).r = (int) 255.999 * r;
            gradient(j, i).g = (int) 255.999 * g;
            gradient(j, i).b = (int) 255.999 * b;
        }
    }

    std::fstream gradient_ppm;
    gradient_ppm.open("gradient.ppm", std::ios_base::out);
    gradient.toPPM(gradient_ppm);
    gradient_ppm.close();

    return 0;
}