#include <iostream>
#include <stack>
using namespace std;

int main() {
    int decimal;
    stack<int> s;

    cout << "Enter a decimal number: ";
    cin >> decimal;

    if (decimal == 0) {
        cout << "Binary Number = 0";
        return 0;
    }

 
    while (decimal > 0) {
        s.push(decimal % 2);
        decimal /= 2;
    }

    cout << "Binary Number = ";

    
    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }

    return 0;
}