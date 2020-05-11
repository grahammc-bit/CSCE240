// Copyright 2020 Matthew Graham
#include <sum_finder.h>

size_t** FindSum(
  int sum, const int** matrix, const size_t matrix_size[], size_t* sums_found) {
  *sums_found = 0;

  // Create Matrix
  size_t** ret = new size_t*[2];
  for (size_t i = 0; i < 2; ++i) {
    ret[i] = new size_t[4];
    for (size_t j = 0; j < 4; ++j) {
      ret[i][j] = 0;
    }
  }

  // Finds Sums in Rows
  for (size_t i = 0; i < matrix_size[0]; ++i) {
    bool loop = true;
    if (i == matrix_size[0] && *sums_found == 0)
      loop = false;
    if (loop != false) {
      for (size_t j = 0; j < matrix_size[1]; ++j) {
        int tmp = 0;
        for (size_t k = j; k < matrix_size[1]; ++k) {
          if (matrix[i][k] != sum)
            tmp += matrix[i][k];
          if (tmp == sum) {
            size_t tmp_array[] = {i, j, i, k};
            for (size_t run = 0; run < 4; ++run)
              ret[*sums_found][run] = tmp_array[run];
            ++(*sums_found);
            tmp = 0;
          }
        }
      }
    } else if (*sums_found == 0 && loop == false) {
      return nullptr;
      }
  }

  // Finds Sums in Columns
  for (size_t i = 0; i < matrix_size[0]; ++i) {
    bool loop = true;
    if (i == matrix_size[0])
      loop = false;
    if (loop != false) {
      for (size_t j = 0; j < matrix_size[1]; ++j) {
        int tmp = 0;
        for (size_t k = i; k < matrix_size[0]; ++k) {
          if (matrix[k][j] != sum)
            tmp += matrix[k][j];
          if (tmp == sum) {
            size_t tmp_array[] = {i, j, k, j};
            for (size_t run = 0; run < 4; ++run)
              ret[*sums_found][run] = tmp_array[run];
            ++(*sums_found);
            tmp = 0;
          }
        }
      }
    } else if (*sums_found == 0 && loop == false) {
      return nullptr;
    }
  }
  return ret;
}
