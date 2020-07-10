//
// Created by @mikhirurg on 01.07.2020.
//

#include <iostream>

char *resize(char *str, unsigned size, unsigned new_size) {
  char *tmp = new char[new_size];
  unsigned copy_len = new_size < size ? new_size : size;
  for (int i = 0; i < copy_len; i++) {
    tmp[i] = str[i];
  }
  delete[] (str);
  return tmp;
}

char *getline() {
  int line_size = 8;
  char *str = new char[line_size];
  char ch;
  int size = 0;
  while ((ch = std::cin.get()) != -1 && ch != '\n') {
    if (size >= line_size) {
      str = resize(str, line_size, line_size * 2);
      line_size *= 2;
    }
    str[size] = ch;
    size++;
  }
  str = resize(str, line_size, size);
  str[size] = '\0';
  return str;
}

int main() {
  char *s = getline();
  std::cout << s << " - LINE!";
  return 0;
}