
# --- PPM Hello World --------------------------------------------
add_executable(ppm_helloworld
    src/ppm_helloworld.cxx
)
target_link_libraries(ppm_helloworld
    raytracing
)

# --- 4.2 Sending Rays Into A Scene -------------------------------
add_executable(4.2_SendingRaysIntoTheScene
    src/4.2_SendingRaysIntoTheScene.cxx
)
target_link_libraries(4.2_SendingRaysIntoTheScene
    raytracing
)

# --- 5 Adding a Sphere -------------------------------------------
add_executable(5_AddingASphere
    src/5_AddingASphere.cxx
)
target_link_libraries(5_AddingASphere
    raytracing
)