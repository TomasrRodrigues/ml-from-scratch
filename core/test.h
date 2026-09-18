/* Minimal test macros. Each test file is its own executable:
 *   CHECK(cond)            fails if cond is false
 *   CHECK_NEAR(a, b, tol)  fails if |a - b| > tol (also fails on NaN)
 *   return test_report();  at the end of main(): nonzero exit if anything failed
 */
#ifndef CORE_TEST_H
#define CORE_TEST_H

#include <math.h>
#include <stdio.h>
#include <stdlib.h>

static int test_failures = 0;

#define CHECK(cond)                                                                                \
    do {                                                                                           \
        if (!(cond)) {                                                                             \
            fprintf(stderr, "%s:%d: CHECK failed: %s\n", __FILE__, __LINE__, #cond);               \
            test_failures++;                                                                       \
        }                                                                                          \
    } while (0)

/* Each argument is evaluated exactly once. !(x <= tol) is true for NaN. */
#define CHECK_NEAR(a, b, tol)                                                                      \
    do {                                                                                           \
        double check_a = (a);                                                                      \
        double check_b = (b);                                                                      \
        double check_tol = (tol);                                                                  \
        if (!(fabs(check_a - check_b) <= check_tol)) {                                             \
            fprintf(stderr,                                                                        \
                    "%s:%d: CHECK_NEAR failed: %s = %.17g, %s = %.17g, "                           \
                    "|diff| = %.3g > %.3g\n",                                                      \
                    __FILE__, __LINE__, #a, check_a, #b, check_b, fabs(check_a - check_b),         \
                    check_tol);                                                                    \
            test_failures++;                                                                       \
        }                                                                                          \
    } while (0)

static inline int test_report(void) {
    if (test_failures > 0) {
        fprintf(stderr, "%d check(s) failed\n", test_failures);
        return EXIT_FAILURE;
    }
    printf("all checks passed\n");
    return EXIT_SUCCESS;
}

#endif /* CORE_TEST_H */
