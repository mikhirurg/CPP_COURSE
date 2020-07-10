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

void strcat(char *to, const char *from) {
  unsigned start = strlen(to);
  unsigned size = start + strlen(from);

  for (unsigned i = start; i < size; i++) {
    to[i] = from[i - start];
  }

  to[size] = '\0';
}

int main() {
  char a[] = "abc";
  const char *b = "def";
  strcat(a, b);

  std::cout << a;
  return 0;
}
