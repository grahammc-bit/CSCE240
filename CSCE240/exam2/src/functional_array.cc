// Copyright 2020 Matthew Graham

#include <inc/functional_array.h>

size_t** Allocate(const size_t* sizes, size_t length) {
  size_t** array = new size_t*[length];
  for (size_t i = 0; i < length; ++i) {
    array[i] = new size_t[sizes[i]];
    for (size_t j = 0; j < sizes[i]; ++j) {
      array[i][j] = sizes[i];
    }
  }
  return array;
}

size_t Deallocate(const size_t** arrays,
                  const size_t* sizes,
                  size_t length) {
  size_t sum = 0;
  for (size_t i = 0; i < length; ++i) {
    for (size_t j = 0; j < sizes[i]; ++j)
      sum += arrays[i][j];
  }
  delete []arrays;
  return sum;
}
