//
// Created by @mikhirurg on 01.07.2020.
//

#include <iostream>

char *resize(const char *str, unsigned size, unsigned new_size) {
  char *tmp = new char[new_size];
  unsigned copy_len = new_size < size ? new_size : size;
  for (int i = 0; i < copy_len; i++) {
    tmp[i] = str[i];
  }
  delete[] str;
  return tmp;
}

int main() {
  const char *a = "abcd";
  char *b = resize(a, 4, 2);

  std::cout << b;

  return 0;
}