/* Copyright 2020
 *
 * This is a rational file parser. I will open a specified file and expects a
 * file format of n num den num den num den..., where there are n num
 * den pairs. All values are integers.
 *
 * The values are printed to the terminal as num/den, one per line.
 */


#include <fstream>
using std::fstream;
#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char* argv[]) {
  const int kNo_of_args = 2;
  const int kIdx_of_file = 1;
  // check number of arguments, give usage message if missing file name
  if (argc != kNo_of_args) {
    cout << "Usage: parse_file <file name>" << endl;
    return 1;
  }

  // use filename from argument list to open filestream
  fstream fin(argv[kIdx_of_file]);

  // ensure file is open, return 2 if not
  if (!fin.is_open()) {
    cout << "Error: cannot open file " << argv[kIdx_of_file] << endl;
    return 2;
  }
  // ensure file is not empty, return 3 for corrupt/empty file

  // get number of rationals
  int n;
  fin >> n;

  // ensure data actually exists

  // loop over rationals
  double input, sum = 0.0;
  for (int i = 0; i < n; ++i) {
    fin >> input;
    sum += input;
  }
  fin.close();

  cout << (sum / n) << endl;

  return 0;
}
