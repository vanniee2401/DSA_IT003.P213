#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
#define MAX 200000

void NhapMang(int N, vector<int> &a);
int TimMaxMin(int &maxVal, int &minVal, int N, vector<int> &a);
void XoaMaxMin(int Delete, int &N, vector<int> &a);

int main()
{
    ios_base::sync_with_stdio(false); // Tăng tốc độ nhập/xuất
    cin.tie(NULL);
    int T, N, S1, S2;
    int maxS1, minS1;
    cin >> T;
    vector<int> KetQua(T);
    for (int i = 0; i < T; i++)
    {
        cin >> N;
        vector<int> a(N);
        NhapMang(N, a);
        S1 = TimMaxMin(maxS1, minS1, N, a);
        // cout << S1 << endl;
        // cout << maxS1 << " " << minS1 << endl;
        XoaMaxMin(maxS1, N, a);
        XoaMaxMin(minS1, N, a);
        // cout << maxS1 << " " << minS1 << endl;
        S2 = TimMaxMin(maxS1, minS1, N, a);
        // cout << maxS1 << " " << minS1 << " " << S2 << endl;
        KetQua[i] = S1 + S2;
    }
    for (int i = 0; i < T; i++)
    {
        cout << KetQua[i] << endl;
    }
}

void NhapMang(int N, vector<int> &a)
{
    for (int i = 0; i < N; i++)
        cin >> a[i];
}

int TimMaxMin(int &maxVal, int &minVal, int N, vector<int> &a)
{
    maxVal = a[0];
    minVal = a[0];
    for (int i = 1; i < N; i++)
    {
        maxVal = max(maxVal, a[i]);
        minVal = min(minVal, a[i]);
    }
    return maxVal - minVal;
}

void XoaMaxMin(int Delete, int &N, vector<int> &a)
{
    auto it = find(a.begin(), a.end(), Delete);

    if (it != a.end())
    {
        // Nếu tìm thấy, xóa phần tử đầu tiên có giá trị 4
        a.erase(it);
    }
    N--;
}