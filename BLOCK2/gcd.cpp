//
// Created by @mikhirurg on 09.03.2020.
//

#include <iostream>
using namespace std;

unsigned gcd(unsigned a, unsigned b) {
  if (b == 0) {
    return a;
  }
  return a > b ? gcd(b, a % b) : gcd(a, b % a);
}

int main() {
  int a, b;
  cin >> a >> b;
  cout << gcd(a, b);
}

