#include <iostream>
#include <string>
#include <cctype>
using namespace std;

char stack[100];
int top = -1;

// Push function
void push(char x)
{
    stack[++top] = x;
}

// Pop function
char pop()
{
    return stack[top--];
}

// Priority function
int priority(char x)
{
    if (x == '(')
        return 0;
    if (x == '+' || x == '-')
        return 1;
    if (x == '*' || x == '/')
        return 2;
    if (x == '^')
        return 3;
    return -1;
}

int main()
{
    string exp;
    cout << "Enter infix expression: ";
    cin >> exp;

    int i = 0;

    while (exp[i] != '\0')
    {
        if (isalnum(exp[i]))
        {
            cout << exp[i];
        }
        else if (top == -1)
        {
            push(exp[i]);
        }
        else if (exp[i] == '(')
        {
            push(exp[i]);
        }
        else if (exp[i] == ')')
        {
            while (stack[top] != '(')
            {
                cout << pop();
            }
            pop(); // Remove '('
        }
        else if (priority(stack[top]) >= priority(exp[i]))
        {
            while (top != -1 &&
                   priority(stack[top]) >= priority(exp[i]))
            {
                cout << pop();
            }
            push(exp[i]);
        }
        else
        {
            push(exp[i]);
        }

        i++;
    }

    while (top != -1)
    {
        cout << pop();
    }

    cout << endl;

    return 0;
}