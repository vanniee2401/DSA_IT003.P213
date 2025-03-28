#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;
#define MAX 300000

void NhapMang(int, int[]);
void EqualDiverse(int, int, int, int, int[], vector<bool> &);

int main()
{
    ios_base::sync_with_stdio(false); // Tăng tốc độ nhập/xuất
    cin.tie(NULL);
    int T, N, K;
    int a[MAX];
    cin >> T;
    vector<bool> KetQua(T, false);
    for (int i = 0; i < T; i++)
    {
        cin >> N >> K;
        NhapMang(N, a);
        EqualDiverse(i, T, N, K, a, KetQua);
    }
    for (int i = 0; i < T; i++)
    {
        if (KetQua[i])
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
}

void NhapMang(int N, int a[])
{
    for (int i = 0; i < N; i++)
        cin >> a[i];
}

void EqualDiverse(int idx, int T, int N, int K, int a[], vector<bool> &KetQua)
{
    vector<bool> XuatHien(MAX, false);
    int count = 0, trung = 0;
    /*for (int i = 0; i < N; i++)
    {
        if (XuatHien[a[i]])
        {
            trung++;
        }
        if (!XuatHien[a[i]])
        {
            count++;
            XuatHien[a[i]] = true;
        }
    }*/
    unordered_map<int, int> countMap; // Đếm số lần xuất hiện của mỗi phần tử

    // Đếm số lần xuất hiện của mỗi phần tử
    for (int i = 0; i < N; i++)
    {
        countMap[a[i]]++;
        if (countMap[a[i]] == 2)
            trung++;
        // 1 3 3 3
    }
    // Xác định số lượng môn học duy nhất
    count = countMap.size();
    if (count < K)
        KetQua[idx] = false;
    else if ((count % 2) == 0)
    {
        if (count / 2 < K)
        {
            if ((count + trung) >= (K * 2))
                KetQua[idx] = true;
        }
        if (count / 2 == K)
            KetQua[idx] = true;
    }
    else if (((count % 2) != 0))
    {
        if (count / 2 < K)
        {
            if (count + trung >= (K * 2))
                KetQua[idx] = true;
        }
        else
            KetQua[idx] = false;
    }
    /*else if ((count % 2) == 0 && (count / 2 == K))
    {
        KetQua[idx] = true;
    }
    else if (count / 2 < K)
    {
        KetQua[idx] = true;
    }
    else
        KetQua[idx] = false;*/
} // 1 3 5 3 5
// cout << count << " " << trung;
