#include <iostream>
#include <stack>
using namespace std;

int main() {
    int num, digit;
    stack<int> s;

    cout << "Enter a number: ";
    cin >> num;

    int temp = num;

  
    while (temp > 0) {
        digit = temp % 10;
        s.push(digit);
        temp /= 10;
    }

    cout << "Reversed number: ";

    while (!s.empty()) {
        cout << s.top();
        s.pop();
    }

    return 0;
}