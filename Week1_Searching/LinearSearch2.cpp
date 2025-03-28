#include <iostream>
#include <vector>
using namespace std;
#define MAX 10000

void NhapMang(int, int[]);
void LinearSearch(int, int[], int);

int main()
{
    int N, a[MAX], x;
    cin >> N;
    NhapMang(N, a);
    cin >> x;
    LinearSearch(N, a, x);
}

void NhapMang(int N, int a[])
{
    for (int i = 0; i < N; i++)
        cin >> a[i];
}

void LinearSearch(int N, int a[], int x)
{
    int count = 0, flag = 0;
    vector<pair<int, int>> result;
    for (int i = 0; i < N; i++)
    {
        count++;
        if (a[i] == x)
        {
            flag++;
            result.push_back(make_pair(i, count));
        }
    }
    if (flag == 0)
        cout << 0;
    else
    {
        cout << flag << endl;
        for (auto &res : result)
            cout << res.first << " " << res.second << endl;
    }
}