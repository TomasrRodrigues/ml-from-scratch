# ml-from-scratch

[![CI](https://github.com/TomasrRodrigues/ml-from-scratch/actions/workflows/ci.yml/badge.svg)](https://github.com/TomasrRodrigues/ml-from-scratch/actions/workflows/ci.yml)

CS229 algorithms implemented from scratch in C11, each derived on paper, gradient-checked, and validated against scikit-learn.

**Status:** in progress (build and test infrastructure only; no results yet).

## Planned projects

| Project | Algorithm | Status |
|---|---|---|
| `a02-logistic-softmax` | Logistic and softmax regression with Newton's method | planned |
| `a04-svm-smo` | Kernel SVM trained with SMO | planned |
| `a06-cart` | Decision tree (CART) | planned |
| `a07-random-forest` | Random forest | planned |
| `a09-neural-net` | Fully connected neural network with backpropagation | planned |
| `a10-kmeans-gmm` | k-means and Gaussian mixture model via EM | planned |

## Build and test

Requires CMake ≥ 3.20 and GCC or Clang on Linux (WSL2 works).

```bash
cmake -B build && cmake --build build -j && ctest --test-dir build --output-on-failure
```

With AddressSanitizer and UndefinedBehaviorSanitizer:

```bash
cmake -B build-asan -DSANITIZE=ON && cmake --build build-asan -j && ctest --test-dir build-asan --output-on-failure
```

## Acknowledgements

Based on Stanford CS229 (Autumn 2018, Andrew Ng) and its lecture notes.