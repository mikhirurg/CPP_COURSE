//
// Created by @mikhirurg on 05.07.2020.
//
#include <iostream>

struct Cls {
  Cls(char c, double d, int i);
 private:
  char c;
  double d;
  int i;
};
Cls::Cls(char c, double d, int i) {
  this->c = c;
  this->d = d;
  this->i = i;
}

struct Cls2 {
  char c;
  double d;
  int i;
};

// Эта функция должна предоставить доступ к полю c объекта cls.
// Обратите внимание, что возвращается ссылка на char, т. е.
// доступ предоставляется на чтение и запись.
char &get_c(Cls &cls) {
  return ((Cls2 &) cls).c;
}

// Эта функция должна предоставить доступ к полю d объекта cls.
// Обратите внимание, что возвращается ссылка на double, т. е.
// доступ предоставляется на чтение и запись.
double &get_d(Cls &cls) {
  return ((Cls2 &) cls).d;
}

// Эта функция должна предоставить доступ к полю i объекта cls.
// Обратите внимание, что возвращается ссылка на int, т. е.
// доступ предоставляется на чтение и запись.
int &get_i(Cls &cls) {
  return ((Cls2 &) cls).i;
}

int main() {

  Cls cls('a', 1.2, 2);

  std::cout << get_c(cls) << " " << get_d(cls) << " " << get_i(cls);

  return 0;
}