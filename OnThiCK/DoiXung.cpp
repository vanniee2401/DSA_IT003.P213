
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

Node *reverse(Node *a)
{
    Node *current = a, *next = nullptr, *pre = nullptr;
    while (current != nullptr)
    {
        next = current->next;
        current->next = pre;
        pre = current;
        current = next;
    }
    return pre;
}

bool isSymmetric(LinkedList llist)
{
    if (llist.head == nullptr)
        return false;
    LinkedList llistR;
    Node *slow = llist.head;
    Node *fast = llist.head;
    while (fast != nullptr && fast->next != nullptr)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    Node *secondHalf = reverse(slow->next);
    Node *firstHalf = llist.head;
    Node *tempSecond = secondHalf;
    while (tempSecond != nullptr)
    {
        if (firstHalf->data != tempSecond->data)
        {
            return false;
        }
        firstHalf = firstHalf->next;
        tempSecond = tempSecond->next;
    }
    return true;
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

    if (isSymmetric(llist))
    {
        cout << "CO" << endl;
    }
    else
    {
        cout << "KHONG" << endl;
    }

    return 0;
}