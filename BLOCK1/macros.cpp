//
// Created by mikha on 09.03.2020.
//
#define MAX(x, y, r) {int x1 = (x); int y1 = (y); r = (x1 > y1) ? x1 : y1;}
#include <iostream>
using namespace std;
int main() {
  int x = 0;
  int a = 10;
  int b = 20;
  MAX(a += b, b, x);
  cout << x;
  return 0;
}
