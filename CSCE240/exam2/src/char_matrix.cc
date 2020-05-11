// Copyright 2020 Matthew Graham

#include <inc/char_matrix.h>

CharMatrix::CharMatrix() {
  matrix_ = nullptr;
  rows_ = 0;
  cols_ = 0;
}

CharMatrix::~CharMatrix() {
  delete []matrix_;
}

CharMatrix::CharMatrix(const char** chars, size_t rows, size_t cols) {
  rows_ = rows;
  cols_ = cols;
  matrix_ = new char*[rows_];
  for (size_t i = 0; i < rows_; ++i)
    matrix_[i] = new char[cols_];
  for (size_t i = 0; i < rows_; ++i) {
    for (size_t j = 0; j < cols_; ++j) {
      matrix_[i][j] = chars[i][j];
    }
  }
}

CharMatrix::CharMatrix(const CharMatrix& that) {
  char** matrix = new char*[that.rows_];
  for (size_t i = 0; i < that.rows_; ++i)
    matrix[i] = new char[that.cols_];
  **matrix = **that.matrix_;
}

const CharMatrix& CharMatrix::operator=(const CharMatrix& rhs) {

}
