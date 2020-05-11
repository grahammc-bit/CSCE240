/* Copyright 2019 CSCE240 */


#include <test_sum_finder.h>


int main(int argc, char* argv[]) {
  std::cout << "TESTING ROW FindSum:" << std::endl;
  size_t expected_row_indices[][4] = {
    {0, 0, 0, 1},
    {4, 3, 4, 4}
  };
  if (TestSummation(56, 2, expected_row_indices)) {
    std::cout << "  PASSED" << std::endl;
  } else {
    std::cout << "  FAILED" << std::endl;
    return 1;
  }

  std::cout << "TESTING COLUMN FindSum:" << std::endl;
  size_t expected_col_indices[][4] = {
    {1, 3, 2, 3},
    {2, 1, 3, 1}
  };
  if (TestSummation(86, 2, expected_col_indices)) {
    std::cout << "  PASSED" << std::endl;
  } else {
    std::cout << "  FAILED" << std::endl;
    return 1;
  }

  return 0;
}


bool TestSummation(
    int sum, size_t size, const size_t expected_indices[][kIndices_size]) {
  // create matrix to pass to FindSum
  const int **matrix = AutoToDynamic(kTest_matrix);
  // create matrix size for FindSum
  const size_t matrix_size[] = {kRows, kCols};

  size_t sums_found = static_cast<size_t>(-1);  // space for output param
  size_t **actual_indices = FindSum(sum, matrix, matrix_size, &sums_found);
  const size_t ** const_actual = const_cast<const size_t **>(actual_indices);

  if (sums_found == 0 || !actual_indices) {
    std::cout << "  No summation found for sum: " << sum << std::endl;
    Delete(matrix, kRows);
    return false;
  }

  if (sums_found != size) {
    std::cout << "  Expected sums found: "
        << size
        << ", Actual sums found: " << sums_found << std::endl;

    Delete(matrix, kRows);
    Delete(actual_indices, sums_found);
    return false;
  }

  if (sums_found == 0 || !actual_indices) {
    std::cout << "  No summation found for sum: " << sum << std::endl;
    Delete(matrix, kRows);
    Delete(actual_indices, sums_found);
    return false;
  }

  if (sums_found != size) {
    std::cout << "  Expected sums found: "
        << size << ", Actual sums found: " << sums_found << std::endl;

    Delete(matrix, kRows);
    Delete(actual_indices, sums_found);
    return false;
  }

  if (!IndicesEqual(expected_indices, const_actual, sums_found)) {
    Delete(matrix, kRows);
    Delete(actual_indices, sums_found);
    return false;
  }

  Delete(matrix, kRows);
  Delete(actual_indices, sums_found);
  return true;
}


const int** AutoToDynamic(const int auto_array[kRows][kCols]) {
  int **dyna_array = new int*[kRows];
  for (size_t i = 0; i < kRows; ++i) {
    dyna_array[i] = new int[kCols];

    for (size_t j = 0; j < kCols; ++j)
      dyna_array[i][j] = auto_array[i][j];
  }

  return const_cast<const int**>(dyna_array);
}


void Delete(const int** dyna_array, size_t size) {
  for (size_t i = 0; i < size; ++i)
    delete [] dyna_array[i];
  delete [] dyna_array;
}

void Delete(size_t** dyna_array, size_t size) {
  for (size_t i = 0; i < size; ++i)
    delete [] dyna_array[i];
  delete [] dyna_array;
}


bool IndicesEqual(
    const size_t expected[][kIndices_size], const size_t** actual,
    size_t size) {
  bool *found = new bool[size];
  for (size_t i = 0; i < size; ++i) {
    found[i] = false;
    for (size_t j = 0; j < size; ++j) {
      // NOTE: this method was suggested by Matthew Shelly
      if (actual[i][kStartRow] == expected[j][kStartRow]
          && actual[i][kStartCol] == expected[j][kStartCol]
          && actual[i][kEndRow] == expected[j][kEndRow]
          && actual[i][kEndCol] == expected[j][kEndCol]) {
        found[i] = true;
        break;
      }
    }
  }
  for (size_t i = 0; i < size; ++i)
    if (!found[i]) {
      std::cout << "  " << ToString(expected[i])
        << " NOT FOUND" << std::endl;
      delete [] found;
      return false;  // one of the index pairs was not found
    }
  delete [] found;
  return true;
}


string ToString(const size_t* indices) {
  stringstream sout;
  sout << "(" << indices[kStartRow] << ", " << indices[kStartCol] << ") - ("
    << indices[kEndRow] << ", " << indices[kEndCol] << ")";
  return sout.str();
}
