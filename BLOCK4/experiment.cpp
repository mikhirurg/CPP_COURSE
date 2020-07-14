//
// Created by @mikhirurg on 13.07.2020.
//

#include <iostream>

class UnderBase {
 public:
  int y;
};

class Base: protected UnderBase {
 private:
  virtual void f() {
    std::cout << "Base F" << std::endl;
  }
  int x;
};

class Derived : private Base {
 public:
  void f() override {
    y++;
    std::cout << "Derived F" << std::endl;
  }
};


int main() {
  Derived derived;
  derived.f();
  return 0;
}