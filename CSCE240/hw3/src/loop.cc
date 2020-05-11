// Copyright 2020 Matthew Graham

#include <iostream>
using namespace std;

int main() {
  int rows = 5;
  int cols = 2;

  int matrix[rows][cols] = {{0,0}, {1,2}, {2,4}

  for (int i = 0; i < rows; ++i) {
    for (int j = 0; j < cols; ++j) {
      cout << matrix[i][j] << " ";
    }
    cout << endl;
  }
}