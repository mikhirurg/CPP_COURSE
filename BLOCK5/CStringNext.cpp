//
// Created by @mikhirurg on 13.07.2020.
//

#include <cstddef> // size_t
#include <iostream>
#include <cstring>

class SubString;

struct String {
  String(const char *str = "") {
    size = strlen(str);
    this->str = new char[size + 1];
    for (int i = 0; i < size; i++) {
      this->str[i] = str[i];
    }
    this->str[size] = '\0';
  }

  String(size_t n, char c)
      : size(n), str(new char[size + 1]) {
    for (int i = 0; i < size; i++) {
      str[i] = c;
    }
    str[size] = '\0';
  }
  ~String() {
    delete [] str;
  }

  String(const String &other);
  String &operator=(const String &other);

  void append(const String &other);

  class SubString {
   public:
    SubString(const String& string, size_t start)
    : size_(string.size), start_(start)
    {
      str_ = new char[size_ + 1];
      for (int i = 0; i <= size_; i++) {
        str_[i] = string.str[i];
      }
    }

    ~SubString() {
      delete [] str_;
    }

    String operator[] (int i) {
      char * substring = new char[i - start_ + 1];

      for (int j = start_; j < i; j++) {
        substring[j - start_] = str_[j];
      }
      substring[i - start_] = '\0';

      String tmp(substring);
      delete [] (substring);

      return tmp;
    }

   private:
    size_t size_, start_;
    char *str_;
  };

  SubString operator[](int i) const {
    return SubString(*this, i);
  }

  size_t size;
  char *str;
};



int main() {

  String const str("hello");

  String const ell = str[1][4];

  std::cout << ell.str << std::endl;

  return 0;
}