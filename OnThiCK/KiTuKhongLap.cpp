
#include <iostream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

string solve(string s)
{
    unordered_map<char, int> a;
    for (char it : s)
    {
        a[it]++;
    }
    for (char it : s)
    {
        if (a[it] == 1)
            return string(1, it);
    }
    return "KHONG CO";
}

int main()
{
    string s;
    getline(cin, s);

    cout << solve(s) << endl;

    return 0;
}