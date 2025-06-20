

#include <iostream>
#include <vector>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int longestConsecutive(vector<int> &nums)
{
    unordered_set<int> s(nums.begin(), nums.end());
    int maxLen = 0;

    for (int num : s)
    {
        if (s.find(num - 1) == s.end())
        {
            int current = num;
            int length = 1;

            while (s.find(current + 1) != s.end())
            {
                current++;
                length++;
            }

            maxLen = max(maxLen, length);
        }
    }

    return maxLen;
}

int main()
{
    int n;
    cin >> n;
    vector<int> nums(n);
    for (int i = 0; i < n; i++)
    {
        cin >> nums[i];
    }

    cout << longestConsecutive(nums) << endl;

    return 0;
}