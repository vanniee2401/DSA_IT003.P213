#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n, m;
vector<int> a, b;
vector<pair<int, int>> DanhSach;

bool HighAble(int);
int HighMax();

int main()
{
    cin >> n;
    a.resize(n);
    for (int &x : a)
        cin >> x;

    cin >> m;
    b.resize(m);
    for (int &x : b)
        cin >> x;

    int h = HighMax();
    HighAble(h);

    cout << h << " " << DanhSach.size() << "\n";
    for (auto [x, y] : DanhSach)
    {
        cout << x << " " << y << "\n";
    }
    return 0;
}

bool HighAble(int h)
{
    DanhSach.clear();
    int j = 0;

    for (int i = 0; i < n; i++)
    {
        if (a[i] >= h)
            continue;

        while (j < m && a[i] + b[j] < h)
        {
            j++;
        }

        if (j == m)
            return false;

        DanhSach.emplace_back(i + 1, j + 1);
        j++;
    }
    return true;
}

int HighMax()
{
    int l = 1, r = *max_element(a.begin(), a.end()) + *max_element(b.begin(), b.end());
    int KetQua = l;

    while (l <= r)
    {
        int mid = (l + r) / 2;
        if (HighAble(mid))
        {
            KetQua = mid;
            l = mid + 1;
        }
        else
        {
            r = mid - 1;
        }
    }
    return KetQua;
}