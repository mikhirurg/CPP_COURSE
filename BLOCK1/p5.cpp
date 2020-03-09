//
// Created by @mikhirurg on 09.03.2020.
//
#include <iostream>
using namespace std;

int log2(int x) {
    int result = 0;
    while (x > 1) {
        x /= 2;
        result++;
    }
    return result;
}

int main() {
    int n = 0;
    int x = 0;
    cin >> n;
    while (n > 0) {
        cin >> x;
        cout << log2(x) << endl;
        n--;
    }
    return 0;
}
