/* Copyright 2020 CSCE 240
 */

#include <inc/test_tight_vector.h>
#include <inc/tight_vector.h>


using std::cout;
using std::endl;


int main(int argc, char* argv[]) {
  assert(argc == 2 && "You must supply the test number as argument to app");
  size_t kTest_arg = 1;

  TightVectorTester tester;

  switch(atoi(argv[kTest_arg])) {
    case 0: // test TightVector::Append with empty array
      cout << "  RUNNING TightVectorTester::TestAppendEmpty" << endl;
      if (tester.TestAppendEmpty()) {
        cout << "    PASSED" << endl;
        return 0;
      } else {
        cout << "    FAILED" << endl;
        return 1;
      }

    case 1: // test TightVector::Append with (not) empty array
      cout << "  RUNNING TightVectorTester::TestAppendNotEmpty" << endl;
      if (tester.TestAppendNotEmpty()) {
        cout << "    PASSED" << endl;
        return 0;
      } else {
        cout << "    FAILED" << endl;
        return 1;
      }

    case 2: // test TightVector::Prepend with empty array
      cout << "  RUNNING TightVectorTester::TestPrependEmpty" << endl;
      if (tester.TestPrependEmpty()) {
        cout << "    PASSED" << endl;
        return 0;
      } else {
        cout << "    FAILED" << endl;
        return 1;
      }

    case 3: // test TightVector::Prepend with (not) empty array
      cout << "  RUNNING TightVectorTester::TestPrependNotEmpty" << endl;
      if (tester.TestPrependNotEmpty()) {
        cout << "    PASSED" << endl;
        return 0;
      } else {
        cout << "    FAILED" << endl;
        return 1;
      }

    default:
      assert(false && "Incorrect test number argument.");
  }

  return 1;
}



bool TightVectorTester::TestAppendEmpty() {
  int val1 = 13, val2 = 17;
  size_t count = 2;
  TightVector t_vec;

  t_vec.Append(val2);
  t_vec.Append(val1);

  bool passed = true;
  if (t_vec.count_ != count) {
    cout << "      Expected member TightVector::count_: " << count
        << ", Actual: " << t_vec.count_ << endl;
    passed = false;
  }

  if (t_vec.array_[count - 1] != val1) {
    cout << "      Expected member TightVector::array_[" << (count - 1)
        << "]: " << val1 << ",  Actual: " << t_vec.array_[count - 1] << endl;
    passed = false;
  }

  if (t_vec.array_[count - 2] != val2) {
    cout << "      Expected member TightVector::array_[" << (count - 2)
        << "]: " << val2 << ",  Actual: " << t_vec.array_[count - 2] << endl;
    passed = false;
  }

  return passed;
}


bool TightVectorTester::TestAppendNotEmpty() {
  int val1 = 3, val2 = 67;
  size_t count = 5;

  TightVector t_vec;
  t_vec.array_ = new int[count - 2];
  t_vec.count_ = count - 2;

  t_vec.Append(val1);
  t_vec.Append(val2);

  bool passed = true;
  if (count != t_vec.count_) {
    cout << "      Expected member TightVector::count_: " << count
        << ", Actual: " << t_vec.count_ << endl;
    passed = false;
  }

  if (t_vec.array_[count - 2] != val1) {
    cout << "      Expected member TightVector::array_[" << (count - 2)
        << "]: " << val1 << ",  Actual: " << t_vec.array_[count - 2] << endl;
    passed = false;
  }

  if (t_vec.array_[count - 1] != val2) {
    cout << "      Expected member TightVector::array_[" << (count - 1)
        << "]: " << val2 << ",  Actual: " << t_vec.array_[count - 1] << endl;
    passed = false;
  }

  return passed;
}


bool TightVectorTester::TestPrependEmpty() {
  int val1 = 3, val2 = 71;
  size_t count = 2;
  TightVector t_vec;

  t_vec.Prepend(val1);
  t_vec.Prepend(val2);

  bool passed = true;
  if (t_vec.count_ != count) {
    cout << "      Expected member TightVector::count_: " << count
        << ", Actual: " << t_vec.count_ << endl;
    passed = false;
  }

  if (t_vec.array_[1] != val1) {
    cout << "      Expected member TightVector::array_[1]: " << val1
        << ",  Actual: " << t_vec.array_[1] << endl;
    passed = false;
  }

  if (t_vec.array_[0] != val2) {
    cout << "      Expected member TightVector::array_[0]: " << val2
        << ",  Actual: " << t_vec.array_[0] << endl;
    passed = false;
  }

  return passed;
}


bool TightVectorTester::TestPrependNotEmpty() {
  int val1 = 33, val2 = 27;
  size_t count = 14;

  TightVector t_vec;
  t_vec.array_ = new int[count - 2];
  t_vec.count_ = count - 2;

  t_vec.Prepend(val1);
  t_vec.Prepend(val2);

  bool passed = true;
  if (count != t_vec.count_) {
    cout << "      Expected member TightVector::count_: " << count
        << ", Actual: " << t_vec.count_ << endl;
    passed = false;
  }

  if (t_vec.array_[1] != val1) {
    cout << "      Expected member TightVector::array_[1]: " << val1
        << ",  Actual: " << t_vec.array_[1] << endl;
    passed = false;
  }

  if (t_vec.array_[0] != val2) {
    cout << "      Expected member TightVector::array_[0]: " << val2
        << ",  Actual: " << t_vec.array_[0] << endl;
    passed = false;
  }

  return passed;
}

