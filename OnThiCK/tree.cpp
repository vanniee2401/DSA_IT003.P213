#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node *left;
    Node *right;
    Node(int a)
    {
        data = a;
        left = right = nullptr;
    }
};