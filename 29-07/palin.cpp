#include <iostream>
#include <stack>
using namespace std;

int main() {
    int num, temp;
    stack<int> s;

    cout << "Enter a number: ";
    cin >> num;

    temp = num;

    // Push digits into the stack
    while (temp > 0) {
        s.push(temp % 10);
        temp /= 10;
    }

    temp = num;
    bool palindrome = true;

    // Compare digits from right to left
    while (temp > 0) {
        int digit = temp % 10;
        if (digit != s.top()) {
            palindrome = false;
            break;
        }
        s.pop();
        temp /= 10;
    }

    if (palindrome)
        cout << num << " is a Palindrome.";
    else
        cout << num << " is not a Palindrome.";

    return 0;
}