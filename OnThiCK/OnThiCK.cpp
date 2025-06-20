#include <bits/stdc++.h>
using namespace std;

// linked list

struct Node
{
    int data;
    Node *next;
    Node(int idata)
    {
        data = idata;
        next = nullptr;
    }
};

struct List
{
    Node *head;
    Node *tail;
    List()
    {
        head = nullptr;
        tail = nullptr;
    }
};

void CreateList(List &a)
{
    a.head = a.tail = nullptr;
}

void AddHead(List &a, int x)
{
    Node *add = new Node(x);
    if (a.head == nullptr)
    {
        a.head = a.tail = add;
    }
    else
    {
        add->next = a.head;
        a.head = add;
    }
}

void AddTail(List &a, int x)
{
    Node *add = new Node(x);
    if (a.head == nullptr)
    {
        a.head = a.tail = add;
    }
    else
    {
        a.tail->next = add;
        a.tail = add;
    }
}

void PrintList(List &a)
{
    Node *current = a.head;
    if (a.head == nullptr)
    {
        cout << "Empty list.";
    }
    else
    {
        while (current)
        {
            cout << current->data << " ";
            current = current->next;
        }
    }
}

void DeleteAtk(List &a, int k)
{
    if (a.head == nullptr)
    {
        return;
    }
    Node *p = a.head;
    if (k == 1) // xoa node dau tien
    {
        a.head = a.head->next;
        delete p;
        return;
    }
    Node *current = a.head;
    for (int i = 1; i < k - 1; i++)
    {
        current = current->next;
    }
    if (current == nullptr || current->next == nullptr)
        return;
    Node *current1 = current->next; // luu node thu k
    current->next = current1->next; // gan node tiep theo cua k
    delete current1;                // xoa node thu k
}