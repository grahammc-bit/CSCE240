#ifndef TEST_INC_TEST_ITEM_H_
#define TEST_INC_TEST_ITEM_H_


#include <inc/item.h>
#include <inc/tax.h>

#include <cassert>
// using assert
#include <cmath>
// using fabs
// using pow
#include <cstddef>
// using size_t
#include <cstdlib>
// using atoi
#include <iomanip>
#include <iostream>
#include <istream>
#include <ostream>
#include <string>

bool TestItemPrice();  // tests csce240::Item::price
bool TestItemEquals();  // tests csce240::Item::operator==
bool TestItemAdd();  // tests csce240::Item::operator+
const size_t kPrecision = 5;  // for displaying differences
const double kPercent_diff = 1.0/pow(10, kPrecision);  // bound for equality

#endif // TEST_INC_TEST_ITEM_H_
