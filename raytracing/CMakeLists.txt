
project(raytracing)

find_package(Eigen3 3.3.4 NO_MODULE)
if(NOT Eigen3_FOUND)
    include(FetchContent)
    set(FETCHCONTENT_QUIET OFF)
    FetchContent_Declare(Eigen
        GIT_REPOSITORY https://gitlab.com/libeigen/eigen.git
        GIT_TAG 3.4.0
    )
    FetchContent_MakeAvailable(Eigen)
endif()

#--- Raytracer Library --------------------------------------------------
add_library(raytracing STATIC
    src/raytracing/images/Pixel.cxx
    src/raytracing/images/RGBImage.cxx
    src/raytracing/materials/Lambertian.cxx
    src/raytracing/materials/Material.cxx
    src/raytracing/materials/Metal.cxx
    src/raytracing/math/Interval.cxx
    src/raytracing/math/Random.cxx
    src/raytracing/math/Ray.cxx
    src/raytracing/math/VectorHelpers.cxx
    src/raytracing/scene/Camera.cxx
    src/raytracing/shapes/Sphere.cxx
    src/raytracing/shapes/SurfaceList.cxx
)
target_link_libraries(raytracing
    Eigen3::Eigen
    pthread
)
target_include_directories(raytracing PUBLIC
    ${CMAKE_CURRENT_SOURCE_DIR}/include
)
install(TARGETS raytracing DESTINATION lib)