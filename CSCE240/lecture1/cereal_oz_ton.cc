/* Copyright 2020
 *
 * A metric ton is 35,273.92 ounces. Write a program which accepts the
 * weight of a box of cereal in ounces and displays how many boxes would
 * be required to provide one metric ton.
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char** argv[]) {//This is a typical main function in C++
  const double kOz_in_ton = 35273.92;


  // get ounces in cereal box (from STDIN)
  int oz_in_box;
  cout << "Enter oz in cereal box: ";
  cin >> oz_in_box;

  // divide ounces in metric ton by cereal ounces
  double boxes_in_ton = kOz_in_ton / oz_in_box;

  // round boxes up to nearest integer
  int boxes_sent = static_cast<int>(boxes_in_ton) + 1;//Casting does NOT round

  // display results
  cout << "Sending " << boxes_sent << endl;//This can be done since cout is a cout is a cout (for instance 1+2+3 is allowed because its a string)
  

  return 0;
}

