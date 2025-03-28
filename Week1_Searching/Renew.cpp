#include <iostream>
using namespace std;

// long long a, k, b, m, n;

// bool KiemTra(long long)

int main()
{
    ios_base::sync_with_stdio(false); // Tăng tốc độ nhập/xuất
    cin.tie(NULL);
    long long a, k, b, m, n;
    cin >> a >> k >> b >> m >> n;
    long long SoCay = 0, SoNgay = 0;
    // float x = (float)n / (a + b);
    long long SoNgayMin = n / (a + b);
    long long SoCayMin = a * SoNgayMin + b * SoNgayMin;
    long long SoCayThieu = n - SoCayMin + a * (SoNgayMin / k) + b * (SoNgayMin / m);
    while (SoCay < SoCayThieu)
    {
        SoNgay++;
        bool ChiaHetChoK = (SoNgayMin + SoNgay) % k == 0;
        bool ChiaHetChoM = (SoNgayMin + SoNgay) % m == 0;
        if (!ChiaHetChoK)
        {
            if (!ChiaHetChoM)
                SoCay += (a + b);
            else
                SoCay += a;
        }
        else if (!ChiaHetChoM)
            SoCay += b;
    }
    cout << SoNgayMin + SoNgay;
}
