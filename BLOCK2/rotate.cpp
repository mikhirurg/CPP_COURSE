//
// Created by @mikhirurg on 09.03.2020.
//
#include <iostream>

using namespace std;

void rotate(int a[], unsigned size, int shift) {
    int start = 0;
    while (shift > 0) {
        start = a[0];
        for (int i = 0; i < size - 1; i++) {
            a[i] = a[i + 1];
        }
        a[size - 1] = start;
        shift--;
    }
}

int main() {
    int n = 0;
    cin >> n;
    int* a = new int[n];

    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    int shift = 0;

    cin >> shift;

    rotate(a, n, shift);

    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
}
