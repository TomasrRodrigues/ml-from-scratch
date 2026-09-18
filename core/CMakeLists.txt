# Header-only for now. On Oct 10, when mat.c exists, this becomes:
#   add_library(core STATIC mat.c rng.c ...) with PUBLIC include dir and m,
#   PRIVATE project_options.
add_library(core INTERFACE)
target_include_directories(core INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})
target_link_libraries(core INTERFACE m)   # libm, needed for math.h on Linux

add_executable(test_smoke tests/test_smoke.c)
target_link_libraries(test_smoke PRIVATE core project_options)
add_test(NAME core.smoke COMMAND test_smoke)