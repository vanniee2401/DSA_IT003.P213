#include <iostream>
using namespace std;
#define MAX 200

void NhapMang(int N, int a[]);
void XuatMang(int N, int a[]);
void swap(int N, int a[]);
void SelectionSort(int N, int a[]);

int main()
{
    int N, a[MAX];
    cin >> N;
    NhapMang(N, a);
    SelectionSort(N, a);
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

void SelectionSort(int N, int a[])
{
    for (int i = 0; i < N - 1; i++)
    {
        int min = i;
        // cho vị trí nhỏ nhất là vị trí đầu tiên
        for (int j = i + 1; j < N; j++)
        { // tìm vị trí nhỏ nhất
            if (a[j] < a[min])
                min = j;
        }
        if (min != i)
        // nếu vị trí min không thay đổi thì xuất để tránh lặp lại mảng đã sortsort
        {
            swap(a[i], a[min]);
            XuatMang(N, a);
        }
    }
}