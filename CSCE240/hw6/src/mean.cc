// Copyright 2020 Matthew Graham
#include <inc/mean.h>

namespace csce240 {

void Mean::Collect(double datum) {
  sum_ += datum;
  ++count_;
}

double Mean::Calculate() const {
  return sum_ / count_;
}

}  // namespace csce240
