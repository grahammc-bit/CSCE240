/* Copyright 2020 CSCE240 */
#ifndef HW3_INC_TEST_WORD_FINDER_H_  //NOLINT
#define HW3_INC_TEST_WORD_FINDER_H_  //NOLINT


#include <cstddef>
// using size_t
#include <iostream>
using std::cin;
using std::cout;
using std::endl;
#include <sstream>
using std::stringstream;
#include <string>
using std::string;

#include <sum_finder.h>  //NOLINT


const size_t kRows = 5;
const size_t kCols = 5;
const int kTest_matrix[kRows][kCols] = {
  {-1,  57,   17, -81,  47},
  {29, -61,   12,  10, 232},
  {47,  17, -101,  76,  -2},
  {-9,  69,  -99, 511,  94},
  {38, -89,  372, 267, -211}
};
const size_t kIndices_size = 4;


/* Used to generate a new dyamic array from the above fixed-size automatic
 * array.
 */
const int** AutoToDynamic(const int auto_array[kRows][kCols]);
void Delete(const int** dyna_array, size_t size);
void Delete(size_t** dyna_array, size_t size);


/* Compare two sets of indices to ensure they are equal.
 * Preconditions: two input parameters are allocated as arrays, each containing
 *   four elements
 */
bool IndicesEqual(const size_t expected[][kIndices_size], const size_t** actual,
  size_t size);

/* Converts a set of indices to a string for printing.
 * Preconditions: input parameter must be allocated as an array with four
 *   elements
 */
string ToString(const size_t*);

bool TestSummation(int, size_t, const size_t[][kIndices_size]);

#endif  //NOLINT
