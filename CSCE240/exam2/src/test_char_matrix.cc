/* Copyright 2020 CSCE 240
 */

#include <inc/test_char_matrix.h>
#include <inc/char_matrix.h>


using std::cout;
using std::endl;


int main(int argc, char* argv[]) {
  assert(argc == 2
    && "You must supply the test number (0~2) as argument to app");
  size_t kTest_arg = 1;

  CharMatrixTester tester;
  tester.chars_ = nullptr;

  switch(atoi(argv[kTest_arg])) {
    case 0: // test CharMatrix::CharMatrix(const char** chars, size_t, size_t)
      cout << "  RUNNING CharMatrixTester::TestFillConstructor" << endl;
      if (tester.TestFillConstructor()) {
        cout << "    PASSED" << endl;
        return 0;
      } else {
        cout << "    FAILED" << endl;
        return 1;
      }

    case 1: // test CharMatrix::CharMatrix(const CharMatrix&)
      cout << "  RUNNING CharMatrixTester::TestCopyConstructor" << endl;
      if (tester.TestCopyConstructor()) {
        cout << "    PASSED" << endl;
        return 0;
      } else {
        cout << "    FAILED" << endl;
        return 1;
      }

    case 2: // test CharMatrix::operator=(const CharMatrix&)
      cout << "  RUNNING CharMatrixTester::TestAssignOperator" << endl;
      if (tester.TestAssignOperator()) {
        cout << "    PASSED" << endl;
        return 0;
      } else {
        cout << "    FAILED" << endl;
        return 1;
      }

    default:
      assert(false && "Incorrect test number argument.");
  }

  return 1;
}


bool CharMatrixTester::TestFillConstructor() {
  BuildChars();
  CharMatrix c_matrix(const_cast<const char**>(chars_), kTestRows, kTestCols);

  bool passed = true;
  for (size_t i = 0; i < kTestRows; ++i)
    for (size_t j = 0; j < kTestCols; ++j)
      if (chars_[i][j] != c_matrix.matrix_[i][j]) {
        cout << "      Expected c_matrix.matrix_[" << i << "][" << j 
            << "]: " << chars_[i][j] << ", Actual: "
            << c_matrix.matrix_[i][j] << endl;
        passed = false;
      }

  CleanChars();
  return passed;
}


bool CharMatrixTester::TestCopyConstructor() {
  BuildChars();
  CharMatrix c_matrix1(const_cast<const char**>(chars_), kTestRows, kTestCols);

  CharMatrix c_matrix2(c_matrix1); // testing

  bool passed = true;
  for (size_t i = 0; i < kTestRows; ++i)
    for (size_t j = 0; j < kTestCols; ++j) {
      if (c_matrix1.matrix_[i][j] != c_matrix2.matrix_[i][j]){
        cout << "      Expected c_matrix1.matrix_[" << i << "][" << j 
            << "] == c_matrix2.matrix_[" << i << "][" << j
            << "]: true, Actual: false" << endl;
        passed = false;
      }

      c_matrix1.matrix_[i][j] = static_cast<char>(c_matrix1.matrix_[i][j] + 1);
      if (c_matrix1.matrix_[i][j] == c_matrix2.matrix_[i][j]) {
        cout << "      Expected modifed c_matrix1.matrix_[" << i << "][" << j 
            << "] != c_matrix2.matrix_[" << i << "][" << j
            << "]: true, Actual: false" << endl;
        passed = false;
      }
    }

  CleanChars();
  return passed;
}


bool CharMatrixTester::TestAssignOperator() {
  BuildChars();
  CharMatrix c_matrix1(const_cast<const char**>(chars_), kTestRows, kTestCols);
  CharMatrix c_matrix2;
  c_matrix2 = c_matrix1;

  bool passed = true;
  for (size_t i = 0; i < kTestRows; ++i)
    for (size_t j = 0; j < kTestCols; ++j) {
      if (c_matrix1.matrix_[i][j] != c_matrix2.matrix_[i][j]) {
        cout << "      Expected c_matrix1.matrix_[" << i << "][" << j 
            << "] == c_matrix2.matrix_[" << i << "][" << j
            << "]: true, Actual: false" << endl;
        passed = false;
      }

      c_matrix1.matrix_[i][j] = static_cast<char>(c_matrix1.matrix_[i][j] + 1);
      if (c_matrix1.matrix_[i][j] == c_matrix2.matrix_[i][j]) {
        cout << "      Expected modifed c_matrix1.matrix_[" << i << "][" << j 
            << "] != c_matrix2.matrix_[" << i << "][" << j
            << "]: true, Actual: false" << endl;
        passed = false;
      }
    }

  CleanChars();
  return passed;
}

void CharMatrixTester::BuildChars() {
  CleanChars();
  chars_ = new char*[kTestRows];
  for (size_t i = 0; i < kTestRows; ++i) {
    *(chars_ + i) = new char[kTestCols];
    for (size_t j = 0; j < kTestCols; ++j)
      *(*(chars_ + i) + j) = *(*(kTestMatrix + i) + j);
  }
}

void CharMatrixTester::CleanChars() {
  if (chars_) {
    for (size_t i = 0; i < kTestRows; ++i)
      delete [] *(chars_ + i);
    delete [] chars_;
  }
}
