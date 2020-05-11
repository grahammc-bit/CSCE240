/* Copyright 2020 CSCE 240
 */

#include <inc/test_time_span.h>
#include <inc/time_span.h>


using std::cout;
using std::endl;
using std::stringstream;
using std::string;


int main(int argc, char* argv[]) {
  assert(argc == 2 && "You must supply the test number as argument to app");
  size_t kTest_arg = 1;

  switch(atoi(argv[kTest_arg])) {
    case 0: // test TimeSpan::operator+(const TimeSpan&)
      cout << "  RUNNING TestOperatorPlusTimeSpan" << endl;
      if (TestOperatorPlusTimeSpan()) {
        cout << "    PASSED" << endl;
        return 0;
      } else {
        cout << "    FAILED" << endl;
        return 1;
      }

    case 1: // test TimeSpan::operator+(int)
            // test operator+(int, TimeSpan)
      cout << "  RUNNING TestOperatorPlusInt" << endl;
      if (TestOperatorPlusInt()) {
        cout << "    PASSED" << endl;
        return 0;
      } else {
        cout << "    FAILED" << endl;
        return 1;
      }

    case 2: // test operator<<(ostream&, const TimeSpan&)
      cout << "  RUNNING TestOperatorExtract" << endl;
      if (TestOperatorExtract()) {
        cout << "    PASSED" << endl;
        return 0;
      } else {
        cout << "    FAILED" << endl;
        return 1;
      }

    case 3: // test operator>>(istream, TimeSpan&)
      cout << "  RUNNING TestOperatorInsert" << endl;
      if (TestOperatorInsert()) {
        cout << "    PASSED" << endl;
        return 0;
      } else {
        cout << "    FAILED" << endl;
        return 1;
      }

    default:
      assert(false && "Incorrect test number argument.");
  }

  return 0;
}


bool TestOperatorPlusTimeSpan() {
  int expected_hours = 4;
  int expected_minutes = 17;
  int expected_seconds = 1;

  TimeSpan lhs(1, 37, 16), rhs(2, 39, 45);

  TimeSpan actual;
  actual = lhs + rhs; // testing

  bool passed = true;
  if (expected_hours != actual.hours()) {
    cout << "      expected hours: " << expected_hours
        << ", actual.hours(): " << actual.hours() << endl;
    passed = false;
  }

  if (expected_minutes != actual.minutes()) {
    cout << "      expected minutes: " << expected_minutes
        << ", actual.minutes(): " << actual.minutes() << endl;
    passed = false;
  }

  if (expected_seconds != actual.seconds()) {
    cout << "      expected seconds: " << expected_seconds
        << ", actual.seconds(): " << actual.seconds() << endl;
    passed = false;
  }

  return passed;
}


bool TestOperatorPlusInt() {
  int expected_hours = 4;
  int expected_minutes = 29;
  int expected_seconds = 57;

  int lhs = 60*60*2 + 60*12 + 46;
  TimeSpan rhs(2, 17, 11);

  TimeSpan actual;
  actual = lhs + rhs;  // testing

  bool passed = true;
  if (expected_hours != actual.hours()) {
    cout << "      expected hours: " << expected_hours
        << ", actual.hours(): " << actual.hours() << endl;
    passed = false;
  }

  if (expected_minutes != actual.minutes()) {
    cout << "      expected minutes: " << expected_minutes
        << ", actual.minutes(): " << actual.minutes() << endl;
    passed = false;
  }

  if (expected_seconds != actual.seconds()) {
    cout << "      expected seconds: " << expected_seconds
        << ", actual.seconds(): " << actual.seconds() << endl;
    passed = false;
  }

  return passed;
}


bool TestOperatorExtract() {
  string expected("2 : 37 : 14");
  TimeSpan rhs(2, 37, 14);
  stringstream lhs;

  lhs << rhs; // testing

  if (expected != lhs.str()) {
    cout << "      Expected: " << expected << ", Actual: " << lhs.str()
        << endl;
    return false;
  }
  
  return true;
}


bool TestOperatorInsert() {
  int expected_hours = 100;
  int expected_minutes = 1;
  int expected_seconds = 44;
  TimeSpan rhs;
  stringstream lhs("100 : 1 : 44");

  lhs >> rhs; // testing

  bool failed = true;
  if (expected_hours != rhs.hours()) {
    cout << "      expected hours: " << expected_hours
        << ", actual.hours(): " << rhs.hours() << endl;
    failed = false;
  }

  if (expected_minutes != rhs.minutes()) {
    cout << "      expected minutes: " << expected_minutes
        << ", actual.minutes(): " << rhs.minutes() << endl;
    failed = false;
  }

  if (expected_seconds != rhs.seconds()) {
    cout << "      expected seconds: " << expected_seconds
        << ", actual.seconds(): " << rhs.seconds() << endl;
    failed = false;
  }

  return failed;
}
