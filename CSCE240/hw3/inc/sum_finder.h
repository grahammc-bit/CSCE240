// Copyright 2020 Matthew Graham
#ifndef HW3_INC_SUM_FINDER_H_ //NOLINT
#define HW3_INC_SUM_FINDER_H_ //NOLINT

#include <cstddef>
// using size_t
#include <iostream>
using std::cout;
using std::endl;

/* The function accepts an integer, an integer matrix, a pair of unsigned
 * integrals in a size_t array representing matrix size, and an unsigned
 * integral type output parameter storing the number of sums found. It returns
 * an n x 2 matrix with the indicies of any sums found.
 *
 * The function searches the columns, diagonals, and rows of the matrix
 * parameter for a series of integers which sum to the provided sum. It returns
 * the number sums found in the output parameter and pairs of any indices as
 * the function's return value.
 *
 * Preconditions:
 *  - All array parameters are allocated,
 *  - The matrix array's dimensions are correctly represented in the two
 *    elements of the array matrix_size.
 *
 * Parameters:
 *  - sum: the integer sum begin sought
 *  - matrix: a two-dimension integer array
 *  - matrix_size: a two-element size_t array with index 0 storing the number
 *    of rows, and index 1 storing the number of columns in the matrix.
 *    See kRow and kCol below.
 *  - sums_found: an output parameter to store the number of summations found
 *
 * Postconditions:
 *  - The output parameter sums_found corresponds to the number of summations
 *    found.
 *  - The output parameter sums_found holds zero if no summations were found.
 *
 * Returns:
 *  - Returns an unsigned integral type matrix of size n x 4, where n is the
 *    value in sums_found. If any summations are found, row the the matrix
 *    shall correspond to the following:
 *      {start row, start col, end row, end col}
 *    The returned values must be of the form:
 *      start row <= end row AND start column <= end column
 *  - Returns the nullptr if no summations were found.
 */
size_t** FindSum(
    int sum, const int** matrix, const size_t matrix_size[],
    size_t* sums_found);

const size_t kRow = 0;  // maps to row of matrix_size
const size_t kCol = 1;  // maps to col of matrix_size
const size_t kStartRow = 0;  // maps to index of starting row in indices
const size_t kStartCol = 1;  // maps to index of starting colum in indices
const size_t kEndRow = 2;  // maps to index of ending row in indices
const size_t kEndCol = 3;  // maps to index of ending colum in indices

#endif  // NOLINT
