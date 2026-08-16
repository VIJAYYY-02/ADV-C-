#include <iostream>
#include <stack>
#include <string>
using namespace std;

bool isMatched(char a, char b)
{
    return (a == '(' && b == ')') ||
           (a == '[' && b == ']') ||
           (a == '{' && b == '}');
}

bool isBalanced(string &str)
{
    stack<char> s;

    for (char x : str)
    {
        if (x == '(' || x == '[' || x == '{')
        {
            s.push(x);
        }
        else if (x == ')' || x == ']' || x == '}')
        {
            if (s.empty())
                return false;

            if (!isMatched(s.top(), x))
                return false;

            s.pop();
        }
    }

    return s.empty();
}

int main()
{
    string str;

    
    cin >> str;

    if (isBalanced(str))
        cout << "Balanced Brackets";
    else
        cout << "Not Balanced";

    return 0;
}