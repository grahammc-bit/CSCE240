// Copyright 2020 Matthew Graham
#ifndef HW4_INC_TAX_H_ // NOLINT
#define HW4_INC_TAX_H_ // NOLINT

#include <istream>
#include <ostream>
#include <string>


class Tax {
 public:
  /* Constructor builds a tax instance from provided string code and double
   * percentage. The percent parameter should be a percentage.
   *
   * Precondition: percent is positive
   */
  Tax(const std::string& code, double percent);

  /* Accessor returns tax instance code
   */
  const std::string& code() const;

  /* Accessor returns tax instance percentage as a percent
   */
  double percent() const;
  /* Mutator updates stored percentage. Should be passed in as a percent.
   *
   * Precondition: new_percent is positive
   */
  void percent(double new_percent);

  /* Method accepts an amount and applies the tax percent, returning the
   * product of taxation.
   *
   * Precondition: amount is positive
   */
  double Calculate(double amount) const;

  /* Extractor appends the code and tax in the form:
   *   AAA:00.0
   */
  std::ostream& Extract(std::ostream* out) const;
  /* Inserter removes a string and numeric from the input stream, storing in
   * this calling instance.
   *
   * Precondition: there exists a whitespace-delimited string and numeric on
   *               the stream in the form:
   *   AAA 00.0
   */
  std::istream& Insert(std::istream* in);

 private:
  std::string code_;
  double percent_;
};

#endif  // NOLINT
