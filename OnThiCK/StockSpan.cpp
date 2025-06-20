#include <iostream>
#include <stack>
#include <vector>
#include <string>

using namespace std;

vector<int> calculateSpan(int arr[], int n)
{
    vector<int> span(n);
    stack<int> s;

    for (int i = 0; i < n; i++)
    {
        while (!s.empty() && arr[s.top()] <= arr[i])
        {
            s.pop();
        }

        span[i] = s.empty() ? (i + 1) : (i - s.top());

        s.push(i);
    }

    return span;
}

int main()
{
    int n;
    cin >> n;

    int arr[n];

    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    vector<int> result = calculateSpan(arr, n);

    for (int x : result)
    {
        cout << x << " ";
    }

    return 0;
}