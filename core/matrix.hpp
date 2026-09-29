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


Matrix matmul(mlcore::Matrix a, mlcore::Matrix b){
    assert(a.cols() == b.rows() && "inner dimensions must agree");
    std::vector<double> c;
    for (std::size_t i=0; i<a.rows(); i++){
        for (std::size_t j=0; j<b.cols();j++){
            double sum=0;
            for (std::size_t k=0; k<a.cols(); k++){
                sum += a(i,k) * b(k, j);
            }
            c.push_back(sum);
        }    
    }
    return Matrix(a.rows(), b.cols(), c);
}

Matrix transpose(mlcore::Matrix in){
    Matrix out(in.cols(), in.rows());
    for (std::size_t i = 0; i < in.rows(); ++i)
        for (std::size_t j = 0; j < in.cols(); ++j)
            out(j, i) = in(i, j);
    return out;
}

Matrix subtract(mlcore::Matrix a, mlcore::Matrix b){
    assert(a.rows()==b.rows() && a.cols()==b.cols() && "matrices must have same structure");
    std::vector<double> out;
    for (std::size_t i=0; i<a.rows(); i++){
        for (std::size_t j=0; j<a.cols(); j++){
            out.push_back(a(i,j)-b(i,j));
        }
    }
    return Matrix(a.rows(), a.cols(), out);
}

Matrix scale(mlcore::Matrix a, double c){
    std::vector<double> out;
    for (std::size_t i=0; i<a.rows(); i++){
        for (std::size_t j=0; j<a.cols(); j++){
            out.push_back(a(i,j)*c);
        }
    }
    return Matrix(a.rows(), a.cols(), out);
}

}