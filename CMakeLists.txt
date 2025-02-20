cmake_minimum_required(VERSION 3.20)

# -----------------------------------------------------------------------
# Global Settings -------------------------------------------------------
# -----------------------------------------------------------------------

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Debug)
endif()
set(DEBUG_POSTFIX "d")

set(CMAKE_CXX_STANDARD 17)

# -----------------------------------------------------------------------
# Project Settings ------------------------------------------------------
# -----------------------------------------------------------------------

project(raytracing)

add_subdirectory(raytracing)
add_subdirectory(models)