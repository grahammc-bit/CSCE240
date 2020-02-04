/* calc_avg.cc copyright 2020
 * 
 * Given a file (using IO redirect) which begins with a single integer n, and
 * contains n whitespace-delimited doubles, calculate the mean of the doubles.
 * Use io redirect. 
 */


#include <iostream>
using std::cin;
using std::cout;
using std::endl;


int main(int argc, char* argv[]) {
  int n;
  double input, sum = 0.0;

  cin >> n;
  for (int i = 0; i < n; i++) {
    cin >> input;
    sum += input;
  }
  cout << (sum / n) << endl;
  return 0;
}
