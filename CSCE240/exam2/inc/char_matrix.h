// Copyright 2020 Matthew Graham
#ifndef INC_CHAR_MATRIX_H_  // NOLINT
#define INC_CHAR_MATRIX_H_  // NOLINT
// CharMatrix Points:
//   Compiles: 1 (make test_char_matrix)
//   Lints: 1  (cpplint --root=./ */char_matrix.*)
//   TestFillConstructor: 1
//   TestCopyConstructor: 1
//   TestAssignOperator: 1
//   test_char_matrix_memory: 1 (make test_char_matrix_memory)


#include <cstddef>
// using size_t


/* This is a small character matrix class to test your ability to manage
 * memory in a class. You must Implement a fill constructor, a copy constructor,
 * and assignment operator, and a destructor.
 */
class CharMatrix {
 public:
  /* implement default constructor, does not need to allocate memory
   */
  CharMatrix();

  /* chars is a two-dimensional array with rows x cols cells
   */
  CharMatrix(const char** chars, size_t rows, size_t cols);

  /* implement me
   */
  CharMatrix(const CharMatrix& that);

  /* implement me
   */
  ~CharMatrix();

  /* implement me
   */
  const CharMatrix& operator=(const CharMatrix& rhs);

  friend class CharMatrixTester;  // ignore me

 private:
  char **matrix_;
  size_t rows_;
  size_t cols_;
};

#endif  // NOLINT
