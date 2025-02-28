#include <gtest/gtest.h>
#include <raytracing/math/Ray.h>
#include <Eigen/Core>

using namespace raytracing::math;

TEST(Test_Ray, at) {

    Eigen::Vector3d origin = Eigen::Vector3d::Zero();
    Eigen::Vector3d direction;
    direction << 1.0, 1.0, 1.0;
    
    Eigen::Vector3d expected;
    expected << 0.5, 0.5, 0.5;

    Ray ray(origin, direction);
    EXPECT_EQ(expected, ray.at(0.5));

    expected << -0.5, -0.5, -0.5;
    EXPECT_EQ(expected, ray.at(-0.5));

}