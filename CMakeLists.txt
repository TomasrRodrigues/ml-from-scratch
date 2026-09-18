cmake_minimum_required(VERSION 3.20)
project(ml_from_scratch LANGUAGES C)

# Strict C11: -std=c11, not -std=gnu11
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED ON)
set(CMAKE_C_EXTENSIONS OFF)

# compile_commands.json for editors / clang-tidy
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

if(NOT CMAKE_BUILD_TYPE AND NOT CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_BUILD_TYPE Debug CACHE STRING "Build type" FORCE)
endif()

option(SANITIZE "Build with AddressSanitizer + UndefinedBehaviorSanitizer" OFF)
option(WARNINGS_AS_ERRORS "Treat compiler warnings as errors" OFF)

# Every target of ours links this; flags never leak to third-party code.
add_library(project_options INTERFACE)
target_compile_options(project_options INTERFACE
    -Wall -Wextra -Wpedantic -Wshadow
    $<$<BOOL:${WARNINGS_AS_ERRORS}>:-Werror>)

if(SANITIZE)
    # -fno-sanitize-recover=all: a UBSan report aborts, so the test fails.
    target_compile_options(project_options INTERFACE
        -fsanitize=address,undefined -fno-omit-frame-pointer -fno-sanitize-recover=all)
    target_link_options(project_options INTERFACE -fsanitize=address,undefined)
endif()

enable_testing()   # must precede add_subdirectory so ctest sees the tests

add_subdirectory(core)