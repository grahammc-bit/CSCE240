/* Copyright 2020 CSCE240
 */
#include <inc/test_tax.h>
using std::cout;
using std::defaultfloat;
using std::endl;
using std::fixed;
using std::setprecision;
using std::stringstream;
using std::to_string;


int main(int argc, char* argv[]) {
  // for test number command line arg
  const size_t kTest_arg = 1;
  // if no arg given, run all tests
  size_t test = 0;
  bool run_all = true;
  if (argc > 1) {  // test no arg provided by user
    test = static_cast<size_t>(argv[kTest_arg][0] - '0');  // char to int
    run_all = false;
  }

  switch (test) {
    case 0:
    // map test 0 to TestTaxCalculate
      cout << "TESTING Tax::Calculate" << endl;
      if (TestTaxCalculate(1.05, 10.5, 10.0)) {  // 1.5 is 10% of 10.5
        cout << "  PASSED" << endl;
        if (!run_all)
          return 0;
      } else {
        cout << "  FAILED" << endl;
        if (!run_all)
          return 1;
      }

    case 1: {  // need a block when declaring variables in switch-statement
    // map test 1 to TestTaxExtract
      cout << "TESTING Tax::Extract" << endl;
      Tax extract_tax("EXT", 33.3);
      if (TestTaxExtract("EXT:33.3", extract_tax)) {
        cout << "  PASSED" << endl;
        if (!run_all)
          return 0;
      } else {
        cout << "  FAILED" << endl;
        if (!run_all)
          return 1;
      }
    }  // end case 1 block

    case 2: {  // block needed to declare variables in switch
    // map test 2 to TestTaxInsert
      cout << "TESTING Tax::Insert" << endl;
      Tax insert_tax("INS", 25.4);
      if (TestTaxInsert(insert_tax, "INS", 25.4)) {
        cout << "  PASSED" << endl;
        if (!run_all)
          return 0;
      } else {
        cout << "  FAILED" << endl;
        if (!run_all)
          return 1;
      }
    }  // end case 2 block

  default:
    // style guide says default must exist, but is an error
    return 1;
  }

  return 0;
}


bool TestTaxCalculate(double expected, double percent, double amount) {
  Tax test_tax("TST", percent);  // instance is TST:percent
  double actual = test_tax.Calculate(amount);  // get actual value
  // test using percent difference and const double from header
  double abs_diff = fabs(expected - actual);
  if (abs_diff < kPercent_diff) {
    return true;
  } else {
    cout << setprecision(kPrecision) << fixed  // to display difference
      << "  Expected: " << expected << ", Actual: " << actual << endl
      << defaultfloat;  // turn off fixed
    return false;
  }
}


bool TestTaxExtract(const std::string& expected, const Tax& from) {
  stringstream sout;  // will function as an output stream
  from.Extract(&sout);  // pass reference to Tax::Extract via addressof op
  if (expected == sout.str()) {  // stringstream::str returns a string class obj
    return true;
  } else {
    cout << "  Expected: " << expected << ", Actual: " << sout.str();
    return false;
  }
}


bool TestTaxInsert(const Tax& expected,
                   const std::string code,
                   double amount) {
  Tax actual("", 0);  // no default constructor, manually init empty instance
  stringstream sin;  // will function as input stream
  sin << code << ' ' << amount;  // add values to stream
  actual.Insert(&sin);  // pass reference to Tax::Insert via addressof op
  if (expected.code() == actual.code()  // compare apples to apples and...
      && expected.percent() == actual.percent()) {
    return true;
  } else {
    cout << "  Expected: " << expected.code() << ':' << expected.percent()
        << ",  Actual: " << actual.code() << ':' << actual.percent() << endl;
    return false;
  }
}  
