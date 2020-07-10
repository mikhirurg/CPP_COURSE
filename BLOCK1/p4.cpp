//
// Created by @mikhirurg on 09.03.2020.
//
#include <iostream>
using namespace std;

int main() {

  char c = '\0';
  int count = 0;
  while (cin.get(c)) {
    if (c == ' ') {
      count++;
    }
    if (c == ' ' && count == 1) {
      cout << c;
    } else {
      if (c != ' ') {
        count = 0;
        cout << c;
      }
    }
  }

  return 0;
}
