#include <iostream>
using namespace std;
#define MAX 200

void NhapMang(int N, int a[]);
void XuatMang(int N, int a[]);
void InsertionSort(int N, int a[]);

int main()
{
    int N, a[MAX];
    cin >> N;
    NhapMang(N, a);
    InsertionSort(N, a);
}

void NhapMang(int N, int a[])
{
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
}

void XuatMang(int N, int a[])
{
    for (int i = 0; i < N; i++)
    {
        cout << a[i] << " ";
    }
    cout << endl;
}

void InsertionSort(int N, int a[])
{
    int i, key, j;
    for (i = 1; i < N; i++)
    {
        // cho key = phần tử thứ 2, so sánh về sau
        key = a[i];
        j = i - 1;
        while (j >= 0 && a[j] > key)
        {
            a[j + 1] = a[j]; // gán phần tử sau = phần tử trước;
            XuatMang(N, a);
            j = j - 1;
        }
        a[j + 1] = key;
        XuatMang(N, a);
    }
}