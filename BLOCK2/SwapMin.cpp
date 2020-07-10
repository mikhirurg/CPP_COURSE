//
// Created by @mikhirurg on 01.07.2020.
//

#include <iostream>
int **create_array2d(unsigned a, unsigned b) {
  int **m = new int *[a];
  m[0] = new int[a * b];
  for (unsigned i = 1; i != a; ++i) {
    m[i] = m[i - 1] + b;
  }

  return m;
}

void free_array2d(int **m) {
  delete[] m[0];
  delete[] m;
}

void swap_min(int *m[], unsigned rows, unsigned cols) {
  int min = m[0][0];
  int a = 0;

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      if (m[i][j] < min) {
        min = m[i][j];
        a = i;
      }
    }
  }

  int *tmp = m[0];
  m[0] = m[a];
  m[a] = tmp;
}

int main() {

  int **m = create_array2d(2, 2);

  m[0][0] = 4;
  m[0][1] = 3;
  m[1][0] = 2;
  m[1][1] = 1;

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      std::cout << m[i][j] << " ";
    }
    std::cout << std::endl;
  }

  std::cout << std::endl;

  swap_min(m, 2, 2);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      std::cout << m[i][j] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}