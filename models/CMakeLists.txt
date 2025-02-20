
# --- PPM Hello World --------------------------------------------
add_executable(ppm_helloworld
    src/ppm_helloworld.cxx
)
target_link_libraries(ppm_helloworld
    raytracing
)