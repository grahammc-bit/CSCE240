// Copyright 2020 Matthew Graham
#include <inc/item.h>

namespace csce240 {

Item::Item() : description_(""), price_(0.0), taxes_(nullptr), range_(0) {
/* Intentionally Empty */ }

Item::Item(const std::string& description, double price) {
  description_ = description;
  price_ = price;
}

Item::~Item() {
  delete []taxes_;
}

Item::Item(const std::string& description,
     double price,
     const Tax* first,
     const Tax* end) {
  price_ = price;
  description_ = description;
  range_ = end - first;
  taxes_ = new Tax[range_];
  Tax *itr = taxes_;
  while (first != end) {
    *itr = *first;
    ++itr;
    ++first;
  }
}

double Item::price() const {
  double new_percent = 0.0;
  for (size_t i = 0; i < sizeof(taxes_); ++i) {
    new_percent += taxes_[i].percent();
  }
  return ((new_percent / 100) + 1) * price_;
}

bool Item::operator==(const Item& rhs) const {
  if (price_ != rhs.price_)
    return false;
  if (description_ != rhs.description_)
    return false;
  if (taxes_ != rhs.taxes_)
    return false;
  if (range_ != rhs.range_)
    return false;
  for (size_t i = 0; i < range_; ++i)
    if (taxes_[i].percent() != rhs.taxes_[i].percent())
      return false;
  for (size_t i = 0; i < range_; ++i)
    if (taxes_[i].code() != rhs.taxes_[i].code())
      return false;
  return true;
}

bool Item::operator!=(const Item& rhs) const {
  if (price_ != rhs.price_)
    return true;
  if (description_ != rhs.description_)
    return true;
  if (taxes_ != rhs.taxes_)
    return true;
  if (range_ != rhs.range_)
    return true;
  for (size_t i = 0; i < range_; ++i)
    if (taxes_[i].percent() != rhs.taxes_[i].percent())
      return true;
  for (size_t i = 0; i < range_; ++i)
    if (taxes_[i].code() != rhs.taxes_[i].code())
      return true;
  return false;
}

double Item::operator+(const Item& rhs) const {
  return price() + rhs.price();
}

}  // namespace csce240
