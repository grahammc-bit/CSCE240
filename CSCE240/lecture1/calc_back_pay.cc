/* Copyright 2020
 *
 * Workers have won a 7.6% pay increase retroactive for six months. Given a
 * worker's salary, display how much retroactive pay is due the worker.
 *
 * Ensure that the number of months and pay increase are stored in const
 * variables.
 */


#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
  // create const int variable to store number of months and assign it 6
  const int kNum_of_months = 6;

  // create const floating point variable to store pay increase and assign it 0.076
  const double kPay_increase = 0.076;

  // prompt user for salary and store in floating point variable
  cout << "Enter your salary: ";
  double salary;
  cin >> salary;
  //operator >> (cin, salary); <- optional for future use  
  
  // calculate pay increase from salary, divide by 12 (months in year)
  //store in floating point variable named back_pay.
  double back_pay = salary / 12;
  

  // display result of pay over number of months to show the 6 months of back pay owed the worker
  cout << "Your back pay is "
    << (back_pay * kNum_of_months * kPay_increase) << endl;
  
  return 0;
}
