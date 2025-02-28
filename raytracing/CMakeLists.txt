
project(raytracing)

find_package(Eigen3 REQUIRED NO_MODULE)
find_package(GTest REQUIRED)

#--- Raytracer Library --------------------------------------------------
add_library(raytracing STATIC
    src/raytracing/images/Pixel.cxx
    src/raytracing/images/RGBImage.cxx
    src/raytracing/math/Ray.cxx
    src/raytracing/scene/Camera.cxx
)
target_link_libraries(raytracing
    Eigen3::Eigen
)
target_include_directories(raytracing PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
install(TARGETS raytracing DESTINATION lib)

#--- Test Executable ----------------------------------------------------
add_executable(test_raytracing
    test/images/Test_RGBImage.cxx
    test/math/Test_Ray.cxx
)
target_link_libraries(test_raytracing
    raytracing
    GTest::GTest
    GTest::Main
)