#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    vector<int> High(n);

    for (int i = 0; i < n; i++)
    {
        cin >> High[i];
    }

    long result = 0;
    stack<pair<int, int>> Bien;

    for (int i = 0; i < n; i++)
    {
        int count = 1;

        while (!Bien.empty() && Bien.top().first <= High[i])
        {
            result += Bien.top().second;
            if (Bien.top().first == High[i])
            {
                count += Bien.top().second;
            }
            Bien.pop();
        }

        if (!Bien.empty())
            result++;

        Bien.push({High[i], count});
    }

    cout << result << endl;
    return 0;
}