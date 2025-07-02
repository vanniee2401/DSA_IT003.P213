#include <bits/stdc++.h>

// o(n2)
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

// o(n), o(n2), o(n2)
void InsertionSort(int a[], int n)
{
    for (int i = 1; i < n; i++)
    {
        int temp = a[i];
        int j = i - 1;
        for (j; j >= 0; j--)
        {
            if (temp > a[j])
                break;
            a[j + 1] = a[j];
        }
        a[j + 1] = temp;
    }
}

// o(nlogn), o(nlogn), o(nlogn)
void heapify(int a[], int n, int i)
{
    int j = 2 * i + 1;
    while (j < n)
    {
        if (j + 1 < n)
            if (a[j] < a[j + 1])
                j++;
        if (a[i] >= a[j])
            return;
        swap(a[i], a[j]);
        i = j;
        j = 2 * i + 1;
    }
}

void heapifymin(int a[], int n, int i)
{
    int j = 2 * i + 1;
    while (j < n)
    {
        if (j + 1 < n)
        {
            if (a[j] > a[j + 1])
                j++;
        }
        if (a[i] <= a[j])
            return;
        swap(a[i], a[j]);
        i = j;
        j = 2 * i + 1;
    }
}

void heapsort(int a[], int n)
{
    // tao heapmax
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(a, n, i);
    }

    // sort
    for (int i = n - 1; i >= 0; i--)
    {
        swap(a[0], a[i]);
        heapify(a, i, 0);
    }
}

// o(n2)
void BubbleSort(int a[], int n)
{
    for (int i = 0; i < n - 1; i++)
    {
        for (int j = 0; j < n - i - 1; j++)
        {
            if (a[j + 1] < a[j])
                swap(a[j], a[j + 1]);
        }
    }
}

// o(nlogn)
void merge(int a[], int l[], int r[], int nl, int nr)
{
    int i = 0, j = 0, k = 0;
    while (i < nl && j < nr)
    {
        if (l[i] <= r[j])
            a[k++] = l[i++];
        else
            a[k++] = r[j++];
    }
    while (i < nl)
        a[k++] = l[i++];
    while (j < nr)
        a[k++] = r[j++];
}

void mergesort(int a[], int n)
{
    if (n < 2)
        return;
    int mid = n / 2;
    int nl = mid;
    int nr = n - mid;
    int *l = new int[nl];
    int *r = new int[nr];
    for (int i = 0; i < mid; i++)
    {
        l[i] = a[i];
    }
    for (int j = mid; j < n; j++)
    {
        r[j - mid] = a[j];
    }
    mergesort(l, nl);
    mergesort(r, nr);
    merge(a, l, r, nl, nr);
    delete[] l;
    delete[] r;
}

// o(nlogn), o(nlogn), o(n2)
void quicksort(int a[], int begin, int end)
{
    if (begin >= end)
        return;
    int mid = (begin + end) / 2;
    int pivot = a[mid];
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
        quicksort(a, begin, j);
    if (i < end)
        quicksort(a, i, end);
}

int m, n;
const int N = 1e5;
vector<int> adj[N];
bool visited[N];

void input()
{
    cin >> n >> m;
    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }
}

void dfs(int u)
{
    stack<int> s;
    s.push(u);
    visited[u] = 1;
    while (!s.empty())
    {
        int v = s.top();
        s.pop();
        for (auto x : adj[v])
        {
            if (!visited[x])
            {
                visited[x] = 1;
                s.push(x);
            }
        }
    }
}

void bfs(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while (!q.empty())
    {
        int v = q.front();
        q.pop();
        for (auto x : adj[v])
        {
            if (!visited[x])
            {
                visited[x] = 1;
                q.push(x);
            }
        }
    }
}
