/* Copyright 2020 CSCE 240
 */


#include <inc/functional_array.h>
#include <cassert>
// using assert
#include <cstdlib>
// using atoi
#include <iostream>


/* These tests expect Allocate to create an array as below, based on current
 *   test values, and Deallocate to sum and delete an array as depicted below.
 *   These values *WILL* change, but remain rectangular.
 *
 * Expected allocation:
 * 5 5 5 5 5
 * 5 5 5 5 5
 * 5 5 5 5 5
 * 5 5 5 5 5
 */
bool TestAllocateRectangle();
const size_t kRectangle_sizes[] = { 5, 5, 5, 5 }; // 4 rows of 5 columns
const size_t kRectangle_sizes_length = sizeof(kRectangle_sizes)/sizeof(size_t);
const size_t kRectangle_sum = 5 * 5 * 4;

bool TestDeallocateRectangle();  // must pass TestAllocate to pass this test


/* These tests expect Allocate to create an array as depicted below, based on
 *   current test values, and Deallocate to sum and delete an array as depicted
 *   below. Again, these test values *WILL* change. If you hard-code them, you
 *   will not pass the tests I use to grade.
 *
 * Expected Allocation:
 * 5 5 5 5 5
 * 3 3 3
 * 1
 * 6 6 6 6 6 6
 * 4 4 4 4
 */
bool TestAllocateJagged();
const size_t kJagged_sizes[] = { 5, 3, 1, 6, 4 }; // 5 rows of varying columns
const size_t kJagged_sizes_length = sizeof(kJagged_sizes) / sizeof(size_t);
const size_t kJagged_sum = 5 * 5 + 3 * 3 + 1 * 1 + 6 * 6 + 4 * 4;

bool TestDeallocateJagged();  // must pass TestAllocate to pass this test


/* Utilty function to convert from auto arrays above into dynamic arrays for
 *   function calls.
 */
const size_t* AutoToDynamic(const size_t[], const size_t);
