// Copyright 2020 Matthew Graham
#ifndef INC_STATISTIC_H_  // NOLINT
#define INC_STATISTIC_H_  // NOLINT

namespace csce240 {

class Statistic {
 public:
  /* Notice this is not a pure virtual function. It is provided to manage any
   * memory a child class may utilize.
   */
  virtual ~Statistic() {}

  /* Provided by a child class, the child should implement whatever is meant by
   * "Collect." If that means storing all data in memory, then it should. If
   * that means summing all data, then it should.
   */
  virtual void Collect(double) = 0;

  /* Depending on the child, this method will provide different behavior. In
   * the case of a mean, for example, it will calculate the mean of all data
   * collected by the Collect method (above).
   * In the case of a median, for example, it will calculate the median of all
   * data collect by the Collect method (above).
   */
  virtual double Calculate() const = 0;
};

}  // namespace csce240

#endif  // NOLINT
