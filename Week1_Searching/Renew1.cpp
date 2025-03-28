#include <iostream>
using namespace std;

bool check(long long SoNgay, long long a, long long k, long long b, long long m, long long n)
{
    long long SoCay = (SoNgay - SoNgay / k) * a + (SoNgay - SoNgay / m) * b;
    return SoCay >= n;
}

long long SoNgay(long long a, long long k, long long b, long long m, long long n)
{
    long long left = 1, right = n / ((a + b) / 2) + 1, ans = right;
    while (left <= right)
    {
        long long mid = left + (right - left) / 2;
        if (check(mid, a, k, b, m, n))
        {
            ans = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return ans;
}

int main()
{
    long long a, k, b, m, n;
    cin >> a >> k >> b >> m >> n;
    cout << SoNgay(a, k, b, m, n) << endl;
    return 0;
}