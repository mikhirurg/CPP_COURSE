//
// Created by @mikhirurg on 02.07.2020.
//

#include <cstddef> // size_t
#include <cstring> // strlen, strcpy
#include <iostream>

struct String {
  String(const char *str = "")
      : size(strlen(str)), str(new char[size + 1]) {
    strcpy(this->str, str);
  }

  String(size_t n, char c)
      : size(n), str(new char[size + 1]) {
    for (int i = 0; i < size; i++) {
      str[i] = c;
    }
    str[size] = '\0';
  }

  String(const String &other)
      : size(other.size), str(new char[size + 1]) {
    strcpy(str, other.str);
  }

  String &operator=(const String &other) {
    if (&other != this) {
      delete[] str;
      size = other.size;
      str = new char[size + 1];
      strcpy(str, other.str);
    }
    return *this;
  }

  ~String() {
    delete[] str;
  }

  void append(String &other) {
    String tmp = String(size + other.size, ' ');
    for (int i = 0; i < size; i++) {
      tmp.str[i] = str[i];
    }
    for (int i = size; i < size + other.size; i++) {
      tmp.str[i] = other.str[i - size];
    }
    size = size + other.size;
    delete[] str;
    str = new char[size + 1];

    strcpy(str, tmp.str);
  }

  size_t size;
  char *str;
};

int main() {

  String s("Hello");
  s.append(s);
  std::cout << s.str << std::endl;

  s = String("popa");
  std::cout << s.str << std::endl;

  return 0;
}