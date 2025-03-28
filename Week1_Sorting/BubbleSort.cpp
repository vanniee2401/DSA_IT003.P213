#include <iostream>
using namespace std;
#define MAX 200

void NhapMang(int N, int a[]);
void XuatMang(int N, int a[]);
void swap(int N, int a[]);
void BubbleSort(int N, int a[]);

int main()
{
    int N, a[MAX];
    cin >> N;
    NhapMang(N, a);
    BubbleSort(N, a);
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

void swap(int &a, int &b)
{
    int c = a;
    a = b;
    b = c;
}

void BubbleSort(int N, int a[])
{
    for (int j = 0; j < N - 1; j++)
    {
        for (int i = 0; i < N - j - 1; i++)
        {
            if (a[i] > a[i + 1])
            {
                swap(a[i], a[i + 1]);
                XuatMang(N, a);
            }
        }
    }
}