#include <bits/stdc++.h>
using namespace std;

void ChuyenDoi(int n)
{
    stack<int> KetQua;
    while (n > 0)
    {
        KetQua.push(n % 2);
        n /= 2;
    }
    while (!KetQua.empty())
    {
        cout << KetQua.top();
        KetQua.pop();
    }
}

int main()
{
    int n;
    cin >> n;
    ChuyenDoi(n);
}