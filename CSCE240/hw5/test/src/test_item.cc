/* Copyright 2020 CSCE240
 */
#include <test/inc/test_item.h>
using std::cout;
using std::defaultfloat;
using std::endl;
using std::fixed;
using std::setprecision;
using std::string;


int main(int argc, char* argv[]) {
  assert(argc == 2 && "Missing test number argument");
  // test number command line arg
  const size_t kTest_arg = 1;

  switch (atoi(argv[kTest_arg])) {
    case 0:
    // map test 0 to TestItemPrice
      cout << "TESTING csce240::Item::price" << endl;
      if (TestItemPrice()) {
        cout << "  PASSED" << endl;
        return 0;
      } else {
        cout << "  FAILED" << endl;
        return 1;
      }

    case 1:
    // map test 1 to TestItemEquals
      cout << "TESTING csce240::Item::operator==" << endl;
      cout << "TESTING csce240::Item::operator!=" << endl;
      if (TestItemEquals()) {
        cout << "  PASSED" << endl;
        return 0;
      } else {
        cout << "  FAILED" << endl;
        return 1;
      }

    case 2:
    // map test 2 to TestItemAdd
      cout << "TESTING csce240::Item::operator+" << endl;
      if (TestItemAdd()) {
        cout << "  PASSED" << endl;
        return 0;
      } else {
        cout << "  FAILED" << endl;
        return 1;
      }

  default:
    // style guide says default must exist, but is an error
    return 1;
  }

  return 0;
}


bool FloatingPointEquals(double lhs, double rhs) {
  double abs_diff = fabs(lhs - rhs);
  // test using percent difference and const double from header
  return abs_diff < kPercent_diff;
}


bool TestItemPrice() {
  string test_descrip = "Helmet";
  double test_price = 280.0;

  // build a tax array for test Item
  string test_codes[] = { "STATE", "CITY" };
  double test_percents[] = { 6.0, 4.0 };
  const size_t kTest_size = 2;
  csce240::Tax test_taxes[kTest_size];
  for (size_t i = 0; i < kTest_size; ++i)
    test_taxes[i] = csce240::Tax(test_codes[i], test_percents[i]);

  csce240::Item test_item(test_descrip,  // make the test item
                          test_price,
                          test_taxes,
                          test_taxes + kTest_size);

  double expected = 0.0;  // build expected outcome
  for (size_t i = 0; i < kTest_size; ++i)
    expected += test_percents[i];
  expected /= 100.0;
  expected = (1 + expected) * test_price;

  if (FloatingPointEquals(expected, test_item.price()))  // compare outcome
    return true;

  cout << setprecision(kPrecision) << fixed  // display difference
    << "  Expected: " << expected << ", Actual: " << test_item.price() << endl
    << defaultfloat;  // turn off fixed
  return false;
}


bool TestItemEquals() {
  string test_codes[] = {"STATE", "CITY"};
  double test_percents[] = {6.0, 4.0};

  const size_t kTest_size = 2;
  csce240::Tax test_taxes[kTest_size];
  for (size_t i =0; i < kTest_size; ++i)
    test_taxes[i] = csce240::Tax(test_codes[i], test_percents[i]);

  csce240::Item item1("iPhone x", 780.34,
                          test_taxes,
                          test_taxes + kTest_size);

  csce240::Item item2("iPhone x", 780.34,
                          test_taxes,
                          test_taxes + kTest_size);
  if (item1 == item2)
    return true;
  return false;
}

bool TestItemNotEquals() {
  string test_codes[] = {"STATE", "CITY"};
  double test_percents[] = {6.0, 4.0};

  const size_t kTest_size = 2;
  csce240::Tax test_taxes[kTest_size];
  for (size_t i =0; i < kTest_size; ++i)
    test_taxes[i] = csce240::Tax(test_codes[i], test_percents[i]);

  csce240::Item item1("iPhone 7", 780.34,
                          test_taxes,
                          test_taxes + kTest_size);

  csce240::Item item2("iPhone x", 780.34,
                          test_taxes,
                          test_taxes + kTest_size);
  if (item1 != item2)
    return true;
  return false;
}

bool TestItemAdd() {
  return true;
}
