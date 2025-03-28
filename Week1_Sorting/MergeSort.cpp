#include <iostream>
using namespace std;
#define MAX 200

void NhapMang(int N, int a[]);
void XuatMang(int N, int a[], int, int);
void MergeSort(int a[], int, int, int);
void Merge(int a[], int L, int M, int R, int N);

int main()
{
    int N, a[MAX];
    cin >> N;
    NhapMang(N, a);
    MergeSort(a, 0, N - 1, N);
}

void NhapMang(int N, int a[])
{
    for (int i = 0; i < N; i++)
    {
        cin >> a[i];
    }
}

void XuatMang(int N, int a[], int L, int R)
{
    for (int i = 0; i < N; i++)
    {
        if (i == L)
            cout << "[ ";
        cout << a[i] << " ";
        if (i == R)
            cout << "] ";
    }
    cout << endl;
}

void MergeSort(int a[], int L, int R, int N)
{
    if (L < R)
    {
        int M = (L + R) / 2;
        MergeSort(a, L, M, N);
        MergeSort(a, M + 1, R, N);
        Merge(a, L, M, R, N);
    }
}

void Merge(int a[], int L, int M, int R, int N)
{
    int n1 = M - L + 1;
    int n2 = R - M;
    int arrL[n1];
    int arrR[n2];

    for (int i = 0; i < n1; i++)
    {
        arrL[i] = a[i + L];
    }
    for (int i = 0; i < n2; i++)
    {
        arrR[i] = a[i + M + 1];
    }

    int i = 0, j = 0, k = L;
    while (i < n1 && j < n2)
    {
        if (arrL[i] <= arrR[j])
        {
            a[k] = arrL[i];
            i++;
        }
        else
        {
            a[k] = arrR[j];
            j++;
        }
        k++;
    }
    while (i < n1)
    {
        a[k] = arrL[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        a[k] = arrR[j];
        j++;
        k++;
    }
    XuatMang(N, a, L, R);
}