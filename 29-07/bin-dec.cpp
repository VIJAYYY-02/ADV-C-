#include <iostream>
#include <stack>
#include <cmath>
using namespace std;

int main() {
    long long binary;
    stack<int> s;
    int decimal = 0, power = 0;

    cout << "Enter a binary number: ";
    cin >> binary;

   
    while (binary > 0) {
        s.push(binary % 10);
        binary /= 10;
    }

   
    while (!s.empty()) {
        decimal = decimal * 2 + s.top();
        s.pop();
    }

    cout << "Decimal Number = " << decimal << endl;

    return 0;
}
