#pragma once

#include <vector>
#include <cassert>

namespace mlcore {

class Matrix {
    public:
        Matrix(std::size_t rows, std::size_t cols): rows_(rows), cols_(cols), data_(rows * cols, 0.0) {}
        Matrix(std::size_t rows, std::size_t cols, std::vector<double> values)
            : rows_(rows), cols_(cols), data_(std::move(values)) {
            assert(data_.size() == rows * cols && "value count must equal rows * cols");
        }

        std::size_t rows() const {
            return rows_;
        }

        std::size_t cols() const {
            return cols_;
        }

        double &operator()(std::size_t i, std::size_t j){
            assert(i < rows_ && j < cols_ && "index out of bounds");
            return data_[i * cols_ + j];
        }

        double operator()(std::size_t i, std::size_t j) const {
            assert(i < rows_ && j < cols_ && "index out of range");
            return data_[i * cols_ + j];
        }

    private:
        std::size_t rows_;
        std::size_t cols_;
        std::vector<double> data_;
};


}