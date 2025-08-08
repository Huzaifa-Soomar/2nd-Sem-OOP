#include <iostream>
#include <stack>
using namespace std;
int main()
{
    string bracket = "[{()}]";
    stack<char> s;

    for (int i = 0; i < bracket.length(); i++)
    {
        if (bracket[i] == '[' || bracket[i] == '{' || bracket[i] == '(')
        {
            s.push(bracket[i]);
        }
        else if (bracket[i] == ']' || bracket[i] == '}' || bracket[i] == ')')
        {
            if (!s.empty())
            {
                if ((bracket[i] == ']' && s.top() == '[') ||
                    (bracket[i] == '}' && s.top() == '{') ||
                    (bracket[i] == ')' && s.top() == '('))
                {
                    s.pop();
                }
            }
            else
            {
                cout << "invalid \n";
                return 0;
            }
        }
        else
        {
            cout << "invalid \n";
            return 0;
        }
    }
    if (s.empty())
        cout << "valid\n";
    else
        cout << "invalid\n";

    return 0;
}