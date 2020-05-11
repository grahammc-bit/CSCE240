// Copyright 2020 Matthew Graham
#ifndef _INC_TIGHT_VECTOR_H_ // NOLINT
#define _INC_TIGHT_VECTOR_H_ // NOLINT
// TightVector points:
//   Compiles: 1 (make test_tight_vector)
//   Lints: 1 (cpplint */tight_vector.*)
//   TestAppendEmpty: 0.5 (./test_tight_vector 0)
//   TestAppendNotEmpty: 1 (./test_tight_vector 1)
//   TestAppendEmpty: 0.5 (./test_tight_vector 2)
//   TestAppendNotEmpty: 1 (./test_tight_vector 3)
//   test_tight_vector_memory: 1 (make test_tight_vector_memory)


#include <cstddef>
// using size_t


/* TightVector class is an exploration of an alternative implementation of the
 * vector class from the STL. This class maintains a tight bound on its
 * underlying array. That is, its underlying array is always full or is not
 * allocated if empty.
 *
 * To receive any points, you may not allocate any extra space. This is a test
 * of your ability to manage memory that fills up or is not available. It is
 * also a test of your ability to manage memory "in place."
 */
class TightVector {
 public:
  TightVector();

  /* Deletes any allocated memory
   */
  ~TightVector();

  /* Adds a new element to the end of the array after growing the array by ONE
   * element.
   */
  void Append(int element);

  /* Adds a new element to the beginning of the array after growing the array
   * by ONE element.
   */
  void Prepend(int element);

  friend class TightVectorTester;  // ignore this. it is for my tests

 private:
  int *array_;  // you must use this for memory
  size_t count_;  // you must use this for memory size
};


#endif // NOLINT
