#include <iostream>
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
    int countDC = 0, check = 0, countCD = 0;
    for (int i = 0; i < N; i++)
    {
        countDC++;
        if (a[i] == x)
        {
            cout << i << endl;
            cout << countDC << endl;
            cout << N - i - 1 << endl;
            cout << N - countDC + 1;
            check++;
        }
    }
    /*for (int j = N - 1; j >= 0; j--)
    {
        countCD++;
        if (a[j] == x)
        {
            cout << j << endl;
            cout << countCD << endl;
        }
    }*/
    if (check == 0)
        cout << -1;
}