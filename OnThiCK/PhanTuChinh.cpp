#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int majorityElement(const vector<int> &arr)
{
    int n = arr.size();
    unordered_map<int, int> a;
    unordered_set<int> check;
    for (int i = 0; i < n; i++)
    {
        a[arr[i]]++;
    }
    for (auto &it : a)
    {
        if (it.second > n / 2)
            return it.first;
    }
    return -1;
}

int main()
{
    int n;
    cin >> n;

    vector<int> arr(n);
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }

    cout << majorityElement(arr) << endl;

    return 0;
}