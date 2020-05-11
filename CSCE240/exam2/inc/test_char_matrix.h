/* Copyright 2020 CSCE 240
 */


#include <inc/char_matrix.h>
#include <cassert>
// using assert
#include <cstdlib>
// using atoi
#include <iostream>


// This is what your matrix and size parameters might look like
const size_t kTestRows = 2;
const size_t kTestCols = 3;
const char kTestMatrix[kTestRows][kTestCols] = {
 { 'a', 'b', 'c' },
 { 'd', 'f', 'i' },
};


class CharMatrixTester {
 public:
  /* Converts kTestMatrix to const char** and uses to test fill constructor
   */
  bool TestFillConstructor();

  /* Converts kTestMatrix to const char** and uses to test copy constructor
   */
  bool TestCopyConstructor();
  
  /* Converts kTestMatrix to const char** and uses to test assignment operator
   */
  bool TestAssignOperator();


  friend int main(int, char*[]);  // What a horrid idea this is. You should
                                  // ignore. I have my reasons. (;

 private:
  void BuildChars();
  void CleanChars();

  char** chars_;
};
