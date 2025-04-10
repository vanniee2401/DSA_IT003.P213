#include <bits/stdc++.h>
using namespace std;

int UuTienToanTu(char dau)
{
    if (dau == '+' || dau == '-')
        return 1;
    if (dau == '*' || dau == ':')
        return 2;
    return 0;
}

int ThemDau(int a, int b, char dau)
{
    switch (dau)
    {
    case '+':
        return a + b;
    case '-':
        return a - b;
    case '*':
        return a * b;
    case ':':
        return a / b;
    }
    return 0;
}

int XuLi(const string &s)
{
    stack<int> GiaTri;
    stack<char> KiHieu;
    int i = 0;
    while (i < s.length())
    {
        if (isdigit(s[i]))
        {
            int val = 0;
            while (i < s.length() && isdigit(s[i]))
            {
                val = val * 10 + (s[i] - '0');
                i++;
            }
            GiaTri.push(val);
        }
        else if (s[i] == '(')
        {
            KiHieu.push(s[i]);
            i++;
        }
        else if (s[i] == ')')
        {
            while (!KiHieu.empty() && KiHieu.top() != '(')
            {
                int b = GiaTri.top();
                GiaTri.pop();
                int a = GiaTri.top();
                GiaTri.pop();
                char op = KiHieu.top();
                KiHieu.pop();
                GiaTri.push(ThemDau(a, b, op));
            }
            KiHieu.pop();
            i++;
        }
        else
        {
            while (!KiHieu.empty() && UuTienToanTu(KiHieu.top()) >= UuTienToanTu(s[i]))
            {
                int b = GiaTri.top();
                GiaTri.pop();
                int a = GiaTri.top();
                GiaTri.pop();
                char op = KiHieu.top();
                KiHieu.pop();
                GiaTri.push(ThemDau(a, b, op));
            }
            KiHieu.push(s[i]);
            i++;
        }
    }

    while (!KiHieu.empty())
    {
        int b = GiaTri.top();
        GiaTri.pop();
        int a = GiaTri.top();
        GiaTri.pop();
        char op = KiHieu.top();
        KiHieu.pop();
        GiaTri.push(ThemDau(a, b, op));
    }

    return GiaTri.top();
}

int main()
{
    string s;
    cin >> s;
    cout << XuLi(s) << endl;
    return 0;
}
