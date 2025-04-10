#include <bits/stdc++.h>
using namespace std;

bool KiemTraDau(string s)
{
    stack<char> Dau;
    for (int i = 0; i < s.length(); i++)
    {
        if (s[i] == '(' || s[i] == '[' || s[i] == '{')
            Dau.push(s[i]);
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}')
        {
            if (Dau.empty())
                return false;
            else if (s[i] == ')')
            {
                if (Dau.top() != '(')
                    return false;
                else
                    Dau.pop();
            }
            else if (s[i] == ']')
            {
                if (Dau.top() != '[')
                    return false;
                else
                    Dau.pop();
            }
            else if (s[i] == '}')
            {
                if (Dau.top() != '{')
                    return false;
                else
                    Dau.pop();
            }
        }
    }
    return Dau.empty();
}

int main()
{
    string s;
    getline(cin, s);
    if (KiemTraDau(s))
        cout << 1;
    else
        cout << 0;
}