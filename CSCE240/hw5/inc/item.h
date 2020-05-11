// Copyright 2020 Matthew Graham
#ifndef HW5_INC_ITEM_H_  // NOLINT
#define HW5_INC_ITEM_H_  // NOLINT
/* This assignment is designed to test your ability to use a class you have
 * written and to manage memory. You will notice that I have not included
 * certain, possibly, necessary methods to ensure correct behavior. You should
 * add what is necessary to pass all tests based on what you have learned about
 * classes and memory.
 *
 * Points:
 *  Style : 1
 *  Compilation : 1
 *  Item::price : 1 
 *  Item::operator==, Item::operator!= : 1
 *  Item::operator+ : 1
 *  No memory leaks: 1
 */


#include <inc/tax.h>
#include <cstddef>
// using size_t
#include <istream>
#include <ostream>
#include <string>
#include <iostream>

namespace csce240 {

class Item {
 public:
  Item();

  Item(const std::string& description, double price);

  ~Item();

  /* Tested as part of testing Item::price()
   *
   * Items have a price and a description. You should store them in the most
   * correct and reasonable way. Items also keep a list of their taxes for
   * use when price is requested through price() method and comparisons are
   * made.
   *
   * Parameters first and end point to the first of a list of Tax instances and
   * one position past the last instance of said list, respectively. You should
   * read up to, but not including end.
   */
  Item(const std::string& description,
       double price,
       const Tax* first,
       const Tax* end);  // fill constructor

  /* Returns the price with all applicable taxes factored in.
   */
  double price() const;

  /* Two instances are equal if they have the same number of taxes and their
   * taxes are equal. Taxes are considered equal if their code and percent are
   * equal.
   * 
   * An instance is also equal to itself.
   */
  bool operator==(const Item& rhs) const;

  /* The complement of the above method.
   */
  bool operator!=(const Item& rhs) const;

  /* Returns the sum of two items, including any applicable taxes
   */
  double operator+(const Item& rhs) const;

 private:
  std::string description_;
  double price_;
  Tax *taxes_;
  size_t range_;
};

}  // namespace csce240

#endif  // NOLINT
