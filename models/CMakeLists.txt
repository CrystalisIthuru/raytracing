
# --- PPM Hello World --------------------------------------------
add_executable(ppm_helloworld
    src/ppm_helloworld.cxx
)
target_link_libraries(ppm_helloworld
    raytracing
)

# --- Rays Background ---------------------------------------------
add_executable(4.2_SendingRaysIntoTheScene
    src/4.2_SendingRaysIntoTheScene.cxx
)
target_link_libraries(4.2_SendingRaysIntoTheScene
    raytracing
)