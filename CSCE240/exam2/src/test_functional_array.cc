/* Copyright 2020 CSCE 240
 */

#include <inc/test_functional_array.h>


using std::cout;
using std::endl;


int main(int argc, char* argv[]) {
  assert(argc == 2 && "You must supply the test number as argument to app");
  size_t kTest_arg = 1;

  switch(atoi(argv[kTest_arg])) {
    case 0: // test Allocate with rectangular array
      cout << "  RUNNING TestAllocateRectangle" << endl;
      if (TestAllocateRectangle()) {
        cout << "    PASSED" << endl;
        return 0;
      } else {
        cout << "    FAILED" << endl;
        return 1;
      }

    case 1: // test Deallocate with rectangular array
      cout << "  RUNNING TestDeallocateRectangle" << endl;
      if (TestDeallocateRectangle()) {
        cout << "    PASSED" << endl;
        return 0;
      } else {
        cout << "    FAILED" << endl;
        return 1;
      }

    case 2: // test Allocate with jagged array
      cout << "  RUNNING TestAllocateJagged" << endl;
      if (TestAllocateJagged()) {
        cout << "    PASSED" << endl;
        return 0;
      } else {
        cout << "    FAILED" << endl;
        return 1;
      }

    case 3: // test Deallocate with rectangular array
      cout << "  RUNNING TestDeallocateJagged" << endl;
      if (TestDeallocateJagged()) {
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


bool TestAllocateRectangle() {
  const size_t *sizes = AutoToDynamic(kRectangle_sizes,
                                      kRectangle_sizes_length);
  size_t **actual = Allocate(sizes, kRectangle_sizes_length);  // testing

  bool passed = true;
  for (size_t i = 0; i < kRectangle_sizes_length; ++i)
    for (size_t j = 0; j < kRectangle_sizes[i]; ++j)
      if (actual[i][j] != kRectangle_sizes[i]) {
        cout << "      Expected allocated array[" << i << "][" << j << "]: "
            << kRectangle_sizes[i] << ", Actual: " << actual[i][j] << endl;

        passed = false;
      }

  delete [] sizes;
  return passed;
}


bool TestDeallocateRectangle() {
  const size_t *sizes = AutoToDynamic(kRectangle_sizes,
                                      kRectangle_sizes_length);
  size_t **allocation = Allocate(sizes, kRectangle_sizes_length);

  size_t actual = Deallocate(const_cast<const size_t**>(allocation),
                             sizes,
                             kRectangle_sizes_length);  // testing

  delete [] sizes;
  if (kRectangle_sum != actual) {
    cout << "      Expected Deallocate sum: " << kRectangle_sum
        << ", Actual: " << actual << endl;
    return false;
  }

  return true;
}


bool TestAllocateJagged() {
  const size_t *sizes = AutoToDynamic(kJagged_sizes,
                                      kJagged_sizes_length);
  size_t **actual = Allocate(sizes, kJagged_sizes_length);  // testing

  bool passed = true;
  for (size_t i = 0; i < kJagged_sizes_length; ++i)
    for (size_t j = 0; j < kJagged_sizes[i]; ++j)
      if (actual[i][j] != kJagged_sizes[i]) {
        cout << "      Expected allocated array[" << i << "][" << j << "]: "
            << kJagged_sizes[i] << ", Actual: " << actual[i][j] << endl;

        passed = false;
      }

  delete [] sizes;
  return passed;
}


bool TestDeallocateJagged() {
  const size_t *sizes = AutoToDynamic(kJagged_sizes,
                                      kJagged_sizes_length);
  size_t **allocation = Allocate(sizes, kJagged_sizes_length);

  size_t actual = Deallocate(const_cast<const size_t**>(allocation),
                             sizes,
                             kJagged_sizes_length);  // testing

  delete [] sizes;
  if (kJagged_sum != actual) {
    cout << "      Expected Deallocate sum: " << kJagged_sum
        << ", Actual: " << actual << endl;
    return false;
  }
  return true;
}


const size_t* AutoToDynamic(const size_t auto_array[], const size_t length) {
  size_t *dyna_array = new size_t[length];

  for (size_t i = 0; i < length; ++i)
    dyna_array[i] = auto_array[i];

  return const_cast<const size_t *>(dyna_array);
}
