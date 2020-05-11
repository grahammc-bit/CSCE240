#ifndef HW4_INC_TEST_TAX_H_
#define HW4_INC_TEST_TAX_H_


#include <inc/tax.h>
#include <cmath>
// using fabs
#include <cstddef>
// using size_t
#include <iomanip>
#include <iostream>
#include <istream>
#include <ostream>
#include <sstream>
#include <string>


/* Accepts a pre-calculated expected value and uses the percent and amount
 * parameters to first build a test Tax instance. It compares expected to the
 * Calculate method of the instance. Comparison is made using percent
 * difference method.
 */
bool TestTaxCalculate(double expected, double percent, double amount);
const size_t kPrecision = 5;  // for printing differences
const double kPercent_diff = 0.00001;  // bound of difference for equality


/* Accepts an expected string that is extracted from the Tax instance parameter
 * using the instance's Extract method. 
 */
bool TestTaxExtract(const std::string& expected, const Tax& from);


/* Accepts expected tax object, a code, and amount. Uses instances Insert
 * object to build and test.
 */
bool TestTaxInsert(const Tax& expected,
                   const std::string code,
                   double amount);

#endif // HW4_INC_TEST_TAX_H_
