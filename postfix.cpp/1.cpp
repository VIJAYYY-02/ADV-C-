#include <iostream>
#include <stack>
#include <string>
#include <cctype>
using namespace std;

int main()
{
    string exp;
    cout << "Enter postfix expression: ";
    cin >> exp;

    stack<int> st;

    for (int i = 0; exp[i] != '\0'; i++)
    {
        if (isdigit(exp[i]))
        {
            st.push(exp[i] - '0');   
        }
        else
        {
            int n1 = st.top();
            st.pop();

            int n2 = st.top();
            st.pop();

            switch (exp[i])
            {
                case '+':
                    st.push(n2 + n1);
                    break;

                case '-':
                    st.push(n2 - n1);
                    break;

                case '*':
                    st.push(n2 * n1);
                    break;

                case '/':
                    st.push(n2 / n1);
                    break;
            }
        }
    }

    cout << "Result = " << st.top() << endl;

    return 0;
}