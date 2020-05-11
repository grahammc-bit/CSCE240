// Copyright 2020 Matthew Graham
#ifndef INC_MEDIAN_H_  // NOLINT
#define INC_MEDIAN_H_  // NOLINT

#include <inc/statistic.h>
#include <vector>
using std::vector;
#include <algorithm>
using std::sort;

/* This child of the Statistic class should be a concrete class---that is, it
 * should implement both Collect and Calculate methods from the parent class
 * Statistic. I will let you decide how to implement those methods.
 * 
 * The Calculate method should return the median of data gathered by the Collect
 * method. You are free to implement both methods by any means you choose.
 */

namespace csce240 {

class Median : public Statistic {
 public:
  void Collect(double);

  double Calculate() const;

 private:
  vector<double> data_;
};

}  // namespace csce240

#endif  // NOLINT