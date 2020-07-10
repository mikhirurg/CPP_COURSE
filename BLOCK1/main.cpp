#include <iostream>

int main() {
  int n = 10;
  int *a = new int[1];
  for (int i = 0; i < n; i++) {
    std::cout << a[i] << std::endl;
  }
  return 0;
}

