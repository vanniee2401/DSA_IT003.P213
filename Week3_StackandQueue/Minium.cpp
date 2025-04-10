#include <iostream>
#include <string>
#include <stack>
using namespace std;

int minAddParentheses(string s)
{
    stack<char> Dau;
    int count = 0;

    for (char c : s)
    {
        if (c == '(')
        {
            Dau.push(c);
        }
        else if (c == ')')
        {
            if (!Dau.empty() && Dau.top() == '(')
            {
                Dau.pop();
            }
            else
            {
                count++;
            }
        }
    }

    return count + Dau.size();
}

int main()
{
    string s;
    cin >> s;

    cout << minAddParentheses(s) << endl;
    return 0;
}