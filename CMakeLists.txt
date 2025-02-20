cmake_minimum_required(VERSION 3.20)

# -----------------------------------------------------------------------
# Global Settings -------------------------------------------------------
# -----------------------------------------------------------------------

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()

# -----------------------------------------------------------------------
# Project Settings ------------------------------------------------------
# -----------------------------------------------------------------------

project(raytracers)

find_package(Eigen3 REQUIRED NO_MODULE)
find_package(GTest REQUIRED)

#--- Raytracer Library --------------------------------------------------
add_library(raytracer STATIC
    src/raytracer/images/Pixel.cxx
    src/raytracer/images/RGBImage.cxx
)
target_link_libraries(raytracer
    Eigen3::Eigen
)
target_include_directories(raytracer PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)

#--- Test Executable ----------------------------------------------------
add_executable(test_raytracer
    test/images/Test_RGBImage.cxx
)
target_link_libraries(test_raytracer
    raytracer
    GTest::GTest
    GTest::Main
)

#--- Check Executable ---------------------------------------------------
add_executable(check src/main.cxx)
target_link_libraries(check raytracer)