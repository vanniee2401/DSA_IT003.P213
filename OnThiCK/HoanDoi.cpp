
#include <iostream>
using namespace std;

struct Node
{
    int data;
    Node *next;
};

// Double Linked List
struct LinkedList
{
    Node *head;
};

Node *createNode(int data)
{
    Node *newNode = new Node();
    newNode->data = data;
    newNode->next = nullptr;
    return newNode;
}

void addTail(LinkedList &llist, int data)
{
    Node *newNode = createNode(data);
    if (llist.head == nullptr)
    {
        llist.head = newNode;
        return;
    }

    Node *current = llist.head;
    while (current->next != nullptr)
    {
        current = current->next;
    }

    current->next = newNode;
}

void printList(LinkedList llist)
{
    Node *current = llist.head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
}

void swapNodes(LinkedList &llist, int n, int k)
{
    if (n < k || k <= 0 || n <= 2 || llist.head == nullptr)
        return;
    if (n == k * 2 - 1)
        return;
    Node *curl = llist.head;
    Node *prel = nullptr;
    Node *curr = llist.head;
    Node *prer = nullptr;
    for (int i = 0; i < k - 1; i++)
    {
        prel = curl;
        curl = curl->next;
    }
    for (int i = 0; i < n - k; i++)
    {
        prer = curr;
        curr = curr->next;
    }
    if (prel == nullptr)
        llist.head = curr;
    else
        prel->next = curr;
    if (prer == nullptr)
        llist.head = curl;
    else
        prer->next = curl;
    Node *temp = curl->next;
    curl->next = curr->next;
    curr->next = temp;
}

int main()
{
    int n, k;
    cin >> n;

    LinkedList llist = LinkedList{nullptr};

    for (int i = 0; i < n; i++)
    {
        int data;
        cin >> data;
        addTail(llist, data);
    }

    cin >> k;

    swapNodes(llist, n, k);

    printList(llist);

    return 0;
}