/* Proves the build, test registration and CI wiring work. */
#include "test.h"

int main(void) {
    CHECK(1 + 1 == 2);
    CHECK_NEAR(0.1 + 0.2, 0.3, 1e-12);
    return test_report();
}