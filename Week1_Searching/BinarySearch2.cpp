#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

int BinarySearch(int, string, int &, vector<string>);

int main()
{
    int N;
    int count = 0;
    cin >> N;
    vector<string> a;
    a.resize(N);
    for (auto &it : a)
        cin >> it;
    string x;
    cin >> x;
    int result = BinarySearch(N, x, count, a);
    if (result != -1)
        cout << result << endl
             << count;
    else
        cout << -1;
}

int BinarySearch(int N, string x, int &count, vector<string> a)
{
    int left = 0;
    int right = N - 1;
    while (left <= right)
    {
        int mid = (left + right) / 2;
        count++;
        if (a[mid] == x)
        {
            return mid;
        }
        if (a[mid] < x)
        {
            left = mid + 1;
        }
        else
        {
            right = mid - 1;
        }
    }
    return -1;
}