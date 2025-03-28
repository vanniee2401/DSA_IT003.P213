#include <iostream>
using namespace std;
#define MAX 32000

void NhapMang(int, int[]);
int BinarySearch(int, int, int &, int[]);

int main()
{
    int N, x, a[MAX];
    int count = 0;
    cin >> N;
    NhapMang(N, a);
    cin >> x;
    int result = BinarySearch(N, x, count, a);
    if (result != -1)
        cout << result << endl
             << count;
    else
        cout << -1;
}

void NhapMang(int N, int a[])
{
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
}

int BinarySearch(int N, int x, int &count, int a[])
{
    int L = 0;
    int R = N - 1;
    while (L <= R)
    {
        count++;
        int m = (L + R) / 2;
        if (a[m] < x)
            L = m + 1;
        else if (a[m] > x)
            R = m - 1;
        else
            return m;
    }
    return -1;
}