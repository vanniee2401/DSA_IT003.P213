#include <iostream>
using std::cin;
using std::cout;

bool check(int *a, int n, int k, long long maxPages)
{
    int count = 1;
    long long sum = 0;

    for (int i = 0; i < n; i++)
    {
        if (sum + a[i] > maxPages)
        {
            count++;
            sum = a[i];
            if (count > k)
                return false;
        }
        else
        {
            sum += a[i];
        }
    }
    return true;
}

int main()
{
    cin.tie(0);
    std::ios::sync_with_stdio(false);

    int n, k;
    cin >> n >> k;
    int *a = new int[n];

    long long sum = 0, maxElement = 0;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
        sum += a[i];
        if (a[i] > maxElement)
            maxElement = a[i];
    }

    long long left = maxElement, right = sum, result = sum;
    while (left <= right)
    {
        long long mid = (left + right) / 2;
        if (check(a, n, k, mid))
        {
            result = mid;
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }

    cout << result << '\n';
    delete[] a;
    return 0;
}