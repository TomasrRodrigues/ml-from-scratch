// Minimal test helpers. Each test file is its own executable:
//   CHECK(cond)            fails if cond is false
//   CHECK_NEAR(a, b, tol)  fails if |a - b| > tol (also fails on NaN)
//   return mlcore::test::report();  at the end of main()
#pragma once

#include <cmath>
#include <cstdio>
#include <cstdlib>

namespace mlcore::test {

inline int failures = 0; // C++17 inline variable: one instance per program

inline void check(bool ok, const char *expr, const char *file, int line) {
    if (!ok) {
        std::fprintf(stderr, "%s:%d: CHECK failed: %s\n", file, line, expr);
        ++failures;
    }
}

// Function arguments are evaluated exactly once. !(x <= tol) is true for NaN.
inline void check_near(double a, double b, double tol, const char *expr_a, const char *expr_b,
                       const char *file, int line) {
    double diff = std::fabs(a - b);
    if (!(diff <= tol)) {
        std::fprintf(stderr,
                     "%s:%d: CHECK_NEAR failed: %s = %.17g, %s = %.17g, |diff| = %.3g > %.3g\n",
                     file, line, expr_a, a, expr_b, b, diff, tol);
        ++failures;
    }
}

inline int report() {
    if (failures > 0) {
        std::fprintf(stderr, "%d check(s) failed\n", failures);
        return EXIT_FAILURE;
    }
    std::printf("all checks passed\n");
    return EXIT_SUCCESS;
}

} // namespace mlcore::test

// Macros only for what functions cannot do: capture expression text, file and line.
#define CHECK(cond) ::mlcore::test::check(static_cast<bool>(cond), #cond, __FILE__, __LINE__)
#define CHECK_NEAR(a, b, tol)                                                                      \
    ::mlcore::test::check_near((a), (b), (tol), #a, #b, __FILE__, __LINE__)