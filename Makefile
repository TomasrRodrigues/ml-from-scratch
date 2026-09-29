# Thin wrapper around CMake presets. `make` runs the sanitizer build and its tests.
.PHONY: all test asan release clang check format format-check clean

all: test

# configure, build and test: Debug + ASan/UBSan
test:
	cmake --preset asan
	cmake --build --preset asan
	ctest --preset asan

# the same, in Release
release:
	cmake --preset release
	cmake --build --preset release
	ctest --preset release

# the same, with clang++ (the compiler CI uses)
clang:
	cmake --preset clang-asan
	cmake --build --preset clang-asan
	ctest --preset clang-asan

# everything CI checks, locally
check: test release clang

# rewrite sources in the repo style
format:
	find core -type f \( -name '*.hpp' -o -name '*.cpp' \) | xargs clang-format -i

# fail if anything is misformatted
format-check:
	find core -type f \( -name '*.hpp' -o -name '*.cpp' \) | xargs clang-format --dry-run --Werror

clean:
	rm -rf build