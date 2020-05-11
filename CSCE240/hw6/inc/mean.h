// Copyright 2020 Matthew Graham
#ifndef INC_MEAN_H_  // NOLINT
#define INC_MEAN_H_  // NOLINT

#include <inc/statistic.h>

/* This child of the Statistic class should be a concrete class---that is, it
 * should implement both Collect and Calculate methods from the parent class
 * Statistic. I will let you decide how to implement those methods.
 *
 * The Calculate method should return the mean of data gathered by the Collect
 * method. You are free to implement both methods by any means (pun not
 * intended) you choose.
 */

namespace csce240 {

class Mean : public Statistic {
 public:
  void Collect(double);

  double Calculate() const;

 private:
  double sum_;
  double count_;
};

}  // namespace csce240

#endif  // NOLINT
