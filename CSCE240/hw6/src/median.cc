// Copyright 2020 Matthew Graham
#include <inc/median.h>

namespace csce240 {

void Median::Collect(double datum) {
  data_.push_back(datum);
}

double Median::Calculate() const {
  vector<double> temp = data_;
  sort(temp.begin(), temp.end());
  if (temp.size() % 2 == 0)
    return (temp[temp.size()/2 - 1] + temp[temp.size()/2]) / 2;
  else
    return temp[temp.size()/2];
}

}  // namespace csce240
