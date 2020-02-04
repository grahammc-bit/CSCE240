/* calc_sqrt.cc copyright 2020
 * 
 * Revisit the Babylonian square root calculation:
 * 1.) Guess at the correct square root (n/2 maybe?)
 * 2.) Calculate root = n / guess
 * 3.) Let guess = (guess + root)/2
 * 4.) Repeat steps 2 and 3 until the square root is resolved.
 *
 * This time, however, use a loop and define what it means to be "resolved."
 */
// using fabs  NOTICE!!!! this is not abs, but fabs. abs is for ints


#include <cmath>
// using fabs
#include <iostream>
using std::cout;
using std::cin;
using std::endl;


int main(int argc, char* argv[]) {
  const double kMax_dist = 0.00001;

  cout << "Enter n: ";
  double n;
  cin >> n;
  double guess = n/2.0;
  double root = n/guess;
  guess = (guess + root)/2.0;

  while (fabs(guess - root) > kMax_dist) {
    root = n/guess;
    guess = (guess + root)/2.0;
  }
  cout << "Root: " << root << endl;

  return 0;
}
