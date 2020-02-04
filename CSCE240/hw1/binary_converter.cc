/* binary_converter.cc copyright 2020
 *
 * This program takes an input in decimals and outputs the number in binary.
 * The amount of bits will be specified by the first input and seperated by a space
 * before the decimal input.
 */


#include <iostream>
#include <cmath>
using std::cout;
using std::cin;
using std::endl;

int main(int argc, char* argv[]) {
  // Call for user input
  int bits;
  int decimal;
  cin >> bits >> decimal;
  bool bit_check;
  bool decimal_check;

  // Checks if the amount of bits is valid
  if (bits <= 31 && bits >= 1) {
    bit_check = true;
  } else {
    bit_check = false;
    exit(1);
  }

  // Checks if the decimal value is valid
  if (decimal >= 0 && decimal <= (pow(2, 31) - 1)) {
    decimal_check = true;
  } else {
    decimal_check = false;
    exit(2);
  }

  /*// Computes binary value
  while (decimal_check == true && bit_check == true) {
    if (decimal > 0) {
      int i = 1;
      while (i <= decimal)
        i *= 2;
      i /=2;

      do {
        if (decimal >= i) {
          cout << '1';
          decimal -= i;
        } else {
          cout << '0';
        }
        i /= 2;
      } while (i > 0);
      cout << endl;
    } else {
      cout << '0';
    }
    break;
  }*/

  // Computes Binary Value
  while (decimal_check == true && bit_check == true) {
      int i = 0;
      while (i <= bits) {
        
      }
  }


  cout << endl;
  return 0;
}
