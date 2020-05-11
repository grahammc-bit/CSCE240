// Copyright 2020 Matthew Graham
#ifndef INC_FUNCTIONAL_ARRAY_H_  // NOLINT
#define INC_FUNCTIONAL_ARRAY_H_  // NOLINT
// functional_array (points):
//   Compiles: 1 (make test_functional_array)
//   Lints: 1 (cpplint --root=./ */functional_array.*)
//   TestAllocateRectangle: 1
//   TestDeallocateRectangle: 1
//   TestAllocateJagged: 1
//   TestDeallocateJagged: 1
//   test_functional_array_memory: 1 (make test_functional_array_memory)


#include <cstddef>
// using size_t


/* Builds an n x s_i array, where s_i is a value at the ith index of the sizes
 *   parameter.  Initializes each element of a given row in the array to a
 *   value equal to the size of that row. Returns the allocated and initialized
 *   array.
 *
 * e.g. A call of Allocate({ 5, 1, 2, 3}, 4) results in the array:
 *   { { 5, 5, 5, 5, 5 },
 *     { 1 },
 *     { 2, 2 },
 *     { 3, 3, 3} }
 *
 * Preconditions: Parameter length is > 0. Each element of sizes is > 0.
 */
size_t** Allocate(const size_t* sizes, size_t length);


/* Accepts an array created by Allocate, sums the elements of the array,
 * deletes the array, and returns the calculated sum.
 *
 * e.g. The above array passed to Deallocate would result in
 *   5*5 + 1*1 + 2*2 + 3*3
 *   being returned.
 *
 * Note: Your allocate method must pass before this method will be tested. 
 */
size_t Deallocate(const size_t** arrays,
                  const size_t* sizes,
                  size_t length);

#endif  // NOLINT
