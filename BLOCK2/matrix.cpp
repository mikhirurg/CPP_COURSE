//
// Created by @mikhirurg on 01.07.2020.
//

#include <cstdio>
#include <iostream>
int **create_array2d(size_t a, size_t b) {
  int **m = new int *[a];
  m[0] = new int[a * b];
  for (size_t i = 1; i != a; ++i) {
    m[i] = m[i - 1] + b;
  }

  return m;
}

void free_array2d(int **m) {
  delete[] m[0];
  delete[] m;
}

int **transpose(const int *const *m, unsigned rows, unsigned cols) {

  int **tmp = create_array2d(cols, rows);

  for (int i = 0; i < rows; i++) {
    for (int j = 0; j < cols; j++) {
      tmp[j][i] = m[i][j];
    }
  }

  return tmp;
}

int main() {

  int **m = create_array2d(2, 2);
  m[0][0] = 1;
  m[0][1] = 2;
  m[1][0] = 3;
  m[1][1] = 4;

  int **out = transpose(m, 2, 2);

  for (int i = 0; i < 2; i++) {
    for (int j = 0; j < 2; j++) {
      std::cout << out[i][j] << " ";
    }
    std::cout << std::endl;
  }

  return 0;
}