#include <iostream>
#include <vector>
using namespace std;
#define MAX 200000

void NhapMang(int, int[]);
void FindMex(int, int[]);

int main()
{
    int N, a[MAX];
    cin >> N;
    NhapMang(N, a);
    FindMex(N, a);
}

void NhapMang(int N, int a[])
{
    for (int i = 0; i < N; i++)
        cin >> a[i];
}

void FindMex(int N, int a[])
{
    int key = 0;
    vector<bool> XuatHien(MAX, false);
    for (int i = 0; i < N; i++)
    {
        if (a[i] >= 0)
        {
            XuatHien[a[i]] = true; // đánh dấu a[i] đã xuất hiệnhiện
        }
        while (XuatHien[key]) // nếu key đã xuất hiện thì tăng đến khi key nhỏ nhất&chưa xuất hiện
        {
            key++;
        }
        cout << key << " ";
    }
}
