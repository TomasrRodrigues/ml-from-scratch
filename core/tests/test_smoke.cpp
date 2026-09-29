// Proves the build, test registration and CI wiring work.
#include "test.hpp"

int main() {
    CHECK(1 + 1 == 2);
    CHECK_NEAR(0.1 + 0.2, 0.3, 1e-12);
    return mlcore::test::report();
}