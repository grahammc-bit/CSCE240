// Copyright 2020 Matthew Graham
#include <inc/tight_vector.h>

TightVector::TightVector() {
  array_ = nullptr;
  count_ = 0;
}

TightVector::~TightVector() {
  delete []array_;
}

void TightVector::Append(int element) {
  int* temp = new int[count_ + 1];
  for (size_t i = 0; i < count_; ++i) {
    temp[i] = array_[i];
  }
  temp[count_] = element;
  count_++;
  delete []array_;
  array_ = temp;
}

void TightVector::Prepend(int element) {
  int* temp = new int[count_ + 1];
  for (size_t i = 0; i < count_; ++i) {
    temp[i] = array_[i];
  }
  if (array_[0] > 0)
    temp[1] = array_[0];
  temp[0] = element;
  count_++;
  delete []array_;
  array_ = temp;
}
