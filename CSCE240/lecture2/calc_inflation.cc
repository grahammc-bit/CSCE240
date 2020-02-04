/* calc_inflation.cc copyright 2020
 * 
 * Due to inflation, the cost of goods increase over the years in which they
 * must be purchased. Write an app which given the cost of a good, the expected
 * annual rate of inflation (as a percentage), and number of years, display the
 * increasing cost, year-by-year, line-by-line.
 */


#include <iostream>
using std::cout;
using std::cin;
using std::endl;


int main(int argc, char* argv[]) {
  double cost_of_good, rate_of_inf;
  int no_of_years;

  // Prompt for and read above variables
  cout << "Enter cost of a good: ";
  cin >> cost_of_good;
  cout << "Enter rate of inlation: ";
  cin >> rate_of_inf;
  cout << "Enter number of years: ";
  cin >> no_of_years;

  // Update rate_of_inf from percentage to decimal
  rate_of_inf /= 100.0;

  // loop over no_of_years
  for (int i = 0; i < no_of_years; ++i) {
    // for each year, add inflation and print
    cost_of_good *= 1.0 + rate_of_inf;
    cout << "After year " << (i+1) << " cost of good is " << cost_of_good
      << endl;
  }
  return 0;
}
