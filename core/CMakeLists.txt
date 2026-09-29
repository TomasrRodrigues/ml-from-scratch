# Header-only for now. When mat.cpp exists, this becomes:
#   add_library(core STATIC mat.cpp rng.cpp ...) with a PUBLIC include dir
#   and PRIVATE project_options.
add_library(core INTERFACE)
target_include_directories(core INTERFACE ${CMAKE_CURRENT_SOURCE_DIR})

add_executable(test_smoke tests/test_smoke.cpp)
target_link_libraries(test_smoke PRIVATE core project_options)
add_test(NAME core.smoke COMMAND test_smoke)