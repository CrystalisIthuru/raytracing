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

project(raytracers Fortran)

#--- Raytracer Library --------------------------------------------------
add_library(raytracer STATIC
    src/raytracer/images/RGBImage.f90
)

#--- Fortran Executable -------------------------------------------------
add_executable(check
    src/main.f90
)
target_link_libraries(check raytracer)