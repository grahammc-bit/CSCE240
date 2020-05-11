#include <iostream>
#include <cmath>
using namespace std;

int main() {
  int bit, dec;
  cin >> bit >> dec;

  if( bit < 1 or bit > 32)
    return 1;
  if (dec < 0 or dec > pow(2,31) -1)
    return 2;

  int power = static_cast<int>(log2(dec));

  if (bits > power - 1)
    for (int i = 0; i < power - 1; ++i)
      cout << "0";

  return 0;
}