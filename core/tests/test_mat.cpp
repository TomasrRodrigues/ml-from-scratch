// Every expected value here was computed by hand, not by running the code.
#include "matrix.hpp"
#include "test.hpp"

using mlcore::Matrix;

int main() {
    // Construction and access
    Matrix a(2, 3, {1, 2, 3, 4, 5, 6});
    CHECK(a.rows() == 2);
    CHECK(a.cols() == 3);
    CHECK_NEAR(a(0, 0), 1.0, 0.0);
    CHECK_NEAR(a(1, 2), 6.0, 0.0);

    Matrix zeros(2, 2);
    CHECK_NEAR(zeros(0, 0), 0.0, 0.0);
    CHECK_NEAR(zeros(1, 1), 0.0, 0.0);

    zeros(0, 1) = 7.0;
    CHECK_NEAR(zeros(0, 1), 7.0, 0.0);

    // matmul: (2x3) * (3x2) = (2x2)
    //   [1 2 3]   [ 7  8]   [ 58  64]
    //   [4 5 6] * [ 9 10] = [139 154]
    //             [11 12]
    /*
    Matrix b(3, 2, {7, 8, 9, 10, 11, 12});
    Matrix ab = mlcore::matmul(a, b);
    CHECK(ab.rows() == 2);
    CHECK(ab.cols() == 2);
    CHECK_NEAR(ab(0, 0), 58.0, 1e-12);
    CHECK_NEAR(ab(0, 1), 64.0, 1e-12);
    CHECK_NEAR(ab(1, 0), 139.0, 1e-12);
    CHECK_NEAR(ab(1, 1), 154.0, 1e-12);
    */

    // Non-square transpose: (2x3) -> (3x2)
    /*
    Matrix at = mlcore::transpose(a);
    CHECK(at.rows() == 3);
    CHECK(at.cols() == 2);
    CHECK_NEAR(at(0, 0), 1.0, 0.0);
    CHECK_NEAR(at(2, 0), 3.0, 0.0);
    CHECK_NEAR(at(2, 1), 6.0, 0.0);

    // transpose(transpose(A)) == A
    Matrix att = mlcore::transpose(at);
    for (std::size_t i = 0; i < a.rows(); ++i) {
        for (std::size_t j = 0; j < a.cols(); ++j) {
            CHECK_NEAR(att(i, j), a(i, j), 0.0);
        }
    }

    // subtract and scale
    Matrix c(2, 3, {6, 5, 4, 3, 2, 1});
    Matrix d = mlcore::subtract(a, c);
    CHECK_NEAR(d(0, 0), -5.0, 1e-12);
    CHECK_NEAR(d(1, 2), 5.0, 1e-12);

    Matrix e = mlcore::scale(a, 0.5);
    CHECK_NEAR(e(0, 0), 0.5, 1e-12);
    CHECK_NEAR(e(1, 2), 3.0, 1e-12);

    // (AB)^T == B^T A^T, on non-square matrices
    Matrix lhs = mlcore::transpose(mlcore::matmul(a, b));
    Matrix rhs = mlcore::matmul(mlcore::transpose(b), mlcore::transpose(a));
    for (std::size_t i = 0; i < lhs.rows(); ++i) {
        for (std::size_t j = 0; j < lhs.cols(); ++j) {
            CHECK_NEAR(lhs(i, j), rhs(i, j), 1e-12);
        }
    }
    */
    return mlcore::test::report();
}