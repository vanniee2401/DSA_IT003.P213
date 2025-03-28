#include <iostream>
#include <vector>
using namespace std;

int main()
{
    int N;
    cin >> N;
    vector<int> a(N);
    int count = 0;
    bool XuatHien[N] = {false};
    for (auto &it : a)
    {
        cin >> it;
        if (!XuatHien[it])
        {
            count++;
            XuatHien[it] = true;
        }
    }
    cout << count;
}