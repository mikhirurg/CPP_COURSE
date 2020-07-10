//
// Created by @mikhirurg on 09.03.2020.
//

#include <iostream>

using namespace std;

void read() {
  int a = 0;
  cin >> a;
  if (a != 0) {
    read();
  }
  if (a != 0) {
    cout << a << " ";
  }
}

int main() {
  read();
  return 0;
}