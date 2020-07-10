//
// Created by @mikhirurg on 06.07.2020.
//

/* Этот код просто напоминание как выглядит класс Foo и функция foo_says.
Не нужно его расскоментировать и/или менять.*/

#include <iostream>

struct Foo {
  void say() const { std::cout << "Foo says: " << msg << "\n"; }
 protected:
  Foo(const char *msg) : msg(msg) {}
 private:
  const char *msg;
};

void foo_says(const Foo &foo) { foo.say(); }

struct Foo2 : public Foo {
 public:
  Foo2(const char *msg)
      : Foo(msg) {}
};


// Вам нужно определить функцию get_foo, как описано в задании,
// чтобы компилировался и работал как ожидается следующий код:
//
// foo_says(get_foo("Hello!"));


Foo get_foo(const char *msg) {
  Foo2 const foo_2 = Foo2(msg);
  return foo_2;
}

int main() {

  foo_says(get_foo("123"));

  return 0;
}