// Copyright 2020 Matthew Graham
#include <inc/tax.h>

using std::istream;
using std::ostream;

Tax::Tax(const std::string& code, double percent) {
  code_ = code;
  if (percent > 0)
    percent_ = percent;
}

const std::string& Tax::code() const {
  return code_;
}

double Tax::percent() const {
  return percent_;
}

void Tax::percent(double new_percent) {
  if (new_percent > 0)
    percent_ = new_percent;
}

double Tax::Calculate(double amount) const {
  double new_percent = percent_ * 0.01;
  return amount * new_percent;
}

ostream& Tax::Extract(ostream* out) const {
  *out << code_ << ":" << percent_;
  return *out;
}

istream& Tax::Insert(istream* in) {
  *in >> code_ >> percent_;
  return *in;
}
