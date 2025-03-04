
# --- PPM Hello World --------------------------------------------
add_executable(ppm_helloworld
    src/ppm_helloworld.cxx
)
target_link_libraries(ppm_helloworld
    raytracing
)

# --- Sphere ------------------------------------------------------
add_executable(sphere
    src/sphere.cxx
)
target_link_libraries(sphere
    raytracing
)