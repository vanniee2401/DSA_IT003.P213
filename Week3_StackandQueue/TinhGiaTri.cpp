#include <bits/stdc++.h>
using namespace std;

double UuTienToanTu(char dau)
{
    if (dau == '+' || dau == '-')
        return 1;
    if (dau == '*' || dau == ':')
        return 2;
    return 0;
}

double ThemDau(double a, double b, char dau)
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

double XuLi(const string &s)
{
    stack<double> GiaTri;
    stack<char> KiHieu;
    double i = 0;
    while (i < s.length())
    {
        if (isdigit(s[i]))
        {
            double val = 0;
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
                double b = GiaTri.top();
                GiaTri.pop();
                double a = GiaTri.top();
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
                double b = GiaTri.top();
                GiaTri.pop();
                double a = GiaTri.top();
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
        double b = GiaTri.top();
        GiaTri.pop();
        double a = GiaTri.top();
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
    cout.precision(10);
    cout << XuLi(s) << endl;
    return 0;
}
