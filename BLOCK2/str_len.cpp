//
// Created by @mikhirurg on 01.07.2020.
//

#include <iostream>

unsigned strlen(const char *str) {
  unsigned count = 0;
  const char *c = str;
  while (*c != '\0') {
    count++;
    c++;
  }
  return count;
}

int main() {
  std::cout << strlen("");
  return 0;
}

