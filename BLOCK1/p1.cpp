//
// Created by mikha on 09.03.2020.
//
#include <iostream>
using namespace std;
int main() {
    int n = 0;
    int a = 0;
    int b = 0;
    cin >> n;
    while (n > 0) {
        cin >> a >> b;
        cout << a + b << endl;
        n--;
    }
}
