// Copyright 2020 Matthew Graham

#include <inc/tax.h>

namespace csce240 {

Tax::Tax() : code_(""), percent_(0.0) { /* Intentionally Empty */ }

Tax::Tax(const std::string& code, double percent) {
  code_ = code;
  if (percent > 0.0)
    percent_ = percent;
}

const std::string& Tax::code() const {
  return code_;
}

double Tax::percent() const {
  return percent_;
}

double Tax::operator*(double rhs) const {
  if (rhs > 0.0) {
    double new_percent = percent_ * 0.01;
    return rhs * new_percent;
  }
  return 0.0;
}

std::istream& Tax::Insert(std::istream* in) {
  *in >> code_ >> percent_;
  return *in;
}

std::ostream& Tax::Extract(std::ostream* out) const {
  *out << code_ << ":" << percent_;
  return *out;
}

double operator*(double lhs, const Tax& rhs) {
  return rhs.operator*(lhs);
}

std::istream& operator>>(std::istream& lhs, Tax& rhs) {
  return rhs.Insert(&lhs);
}

std::ostream& operator<<(std::ostream& lhs, const Tax& rhs) {
  return rhs.Extract(&lhs);
}

}  // namespace csce240
