#include <iostream>
using std::cin;
using std::cout;
using std::endl;

int main(int argc, char** argv) {
  int n = 0;

  cin >> n;

  for (int i = n; i > 0; --i) {
    cout << i << " ";
  }
  cout << endl;
  return 0;
}