#include <iostream>
using std::cout;
using std::endl;
using std::cin;

int main(int argc, char** argv) {
  double n = 0.0;
  cin >> n;

  int k = static_cast<int>(n);

  switch(k) {
    case 1:
      cout << "Sunday" << endl;
      break;
    case 2:
      cout << "Monday" << endl;
      break;
    default:
      cout << "Not a day" << endl;
      break;
  }
}
