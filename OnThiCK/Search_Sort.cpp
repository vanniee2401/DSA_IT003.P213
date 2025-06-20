#include <bits/stdc++.h>

// linear search
int LinearSearch(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
            return i;
    }
    return -1;
}

// binary search, thu tu tang dan
int BinarySearch(int a[], int n, int x)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = (right + left) / 2;
        if (a[mid] == x)
            return mid;
        else if (x < a[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}

// bubble sort
void BubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 1; j < n - i - 1; j++)
        {
            if (a[j] > a[j + 1])
                swap(a[j], a[j + 1]);
        }
    }
}

// selection sort
void SelectionSort(int a[], int n)
{
    for (int i = 0; i < n; i++)
    {
        int min = i;
        for (int j = i + 1; j < n; j++)
        {
            if (a[j] < a[min])
                min = j;
        }
        swap(a[i], a[min]);
    }
}

// insertion sort
void InsertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = a[i];
        int j = i - 1;
        while (j >= 0 && a[j] > temp)
        {
            a[j + 1] = a[j];
            j--;
        }
        a[j + 1] = temp;
    }
}

// heapsort
void heapify(int a[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (a[largest] < a[left] && left < n)
        largest = left;
    if (a[largest] < a[right] && right < n)
        largest = right;
    if (largest != i)
    {
        swap(a[largest], a[i]);
        heapify(a, n, largest);
    }
}

void HeapSort(int a[], int n)
{
    // tao heap max
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }

    // tao heap min
    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[i], a[0]);
        heapify(a, i, 0);
    }
}

// quick sort
void QuickSort(int a[], int begin, int end)
{
    if (begin >= end)
        return;
    int pivot = a[(end + begin) / 2];
    int i = begin, j = end;
    while (i <= j)
    {
        while (a[i] < pivot)
            i++;
        while (a[j] > pivot)
            j--;
        if (i <= j)
        {
            swap(a[i], a[j]);
            i++;
            j--;
        }
    }
    if (begin < j)
        QuickSort(a, begin, j);
    if (i < end)
        QuickSort(a, i, end);
}

// merge sort
void merge(int a[], int L[], int R[], int nL, int nR)
{
    int i = 0, j = 0, k = 0;
    while (i < nL && j < nR)
    {
        if (L[i] <= R[j])
            a[k++] = L[i++];
        else
            a[k++] = R[j++];
    }
    while (i < nL)
        a[k++] = L[i++];
    while (j < nR)
        a[k++] = R[j++];
}

void mergesort(int a[], int n)
{
    if (n < 2)
        return;
    int mid = n / 2;
    int nL = mid;
    int nR = n - mid;
    int *L = new int[nL];
    int *R = new int[nR];
    for (int i = 0; i < mid; i++)
        L[i] = a[i];
    for (int i = mid; i < n; i++)
        R[i - mid] = a[i];
    mergesort(L, nL);
    mergesort(R, nR);
    merge(a, L, R, nL, nR);
    delete L;
    delete R;
}

int main()
{
    int n = 5;
    int a[5] = {1, 3, 4, 5, 2};
    mergesort(a, n);
    for (int i = 0; i < n; i++)
    {
        cout << a[i] << " ";
    }
    return 0;
}