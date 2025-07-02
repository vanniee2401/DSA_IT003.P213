// o(1), o(n), o(n)
int LinearSearch(int a[], int n, int x)
{
    for (int i = 0; i < n; i++)
    {
        if (a[i] == x)
            return i;
    }
    return -1;
}

// o(1),o(logn),o(logn)
int BinarySearch(int a[], int n, int x)
{
    int left = 0, right = n - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (a[mid] == x)
            return mid;
        if (x < a[mid])
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}