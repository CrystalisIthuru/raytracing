#include <gtest/gtest.h>
#include <raytracing/images/RBGImage.h>
#include <string>

using namespace raytracing::images;

TEST(Test_RGBImage, toPPM) {

    RGBImage image(3, 2);
    image.image()(0, 0).r = 255;
    image.image()(0, 1).g = 255;
    image.image()(0, 2).b = 255;
    image.image()(1, 0).r = 255;
    image.image()(1, 0).g = 255;
    image.image()(1, 1).r = 255;
    image.image()(1, 1).g = 255;
    image.image()(1, 1).b = 255;

    std::string expected = R"(P3
3 2
255
255 0 0 0 255 0 0 0 255 
255 255 0 255 255 255 0 0 0 
)";

    std::ostringstream oss;
    image.toPPM(oss);
    EXPECT_EQ(expected, oss.str());

}