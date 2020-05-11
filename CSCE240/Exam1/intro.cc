#include "intro.h"
int main(int argc, char** argv) {
  cout << mul(9, 9) << endl;
  cout << pow(3, 3) << endl;
}

double pow(double a, double b) {
  if (b == 0)
    return 1;
  double p  = 1;
  for (int i = 0; i < b; ++i)
    p *= a;
  return p;
}

double mul(double a, double b) {
  return a * b;
}