/* calc_prime.cc copyright 2020
 * 
 * Write a program that prints on a single line, separated but not terminated by
 * commas, all prime numbers [3, 100).
 *
 * Now, update the app to accept a lower bound and upper bound from user input
 * and, so long as 2 < lower_bound < upper_bound, display all prime numbers
 * from [lower_bound, upper_bound]
 */


#include <iostream>
using std::cin;
using std::cout;
using std::endl;


int main(int argc, char* argv[]) {
  // get upper and lower bound from user and ensure constraints
  int upper, lower;

  cout << "Enter lower and upper bound, s.t. lower <= upper: ";
  cin >> lower >> upper;

  // loop over all integers in [lower, upper]
  for (int i = lower; i <= upper; ++i) {
    // for each int, determine whether prime and print
    bool is_prime = true;
    for (int j = 2; j <= i/2; ++j) {
      if (i % j == 0) {
        is_prime = false;
        break;
      }
    }
    if (is_prime)
      cout << i << " is prime" << endl;
    else
      cout << i << " is not prime" << endl;
  }
  return 0;
}
