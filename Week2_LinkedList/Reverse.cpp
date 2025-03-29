#include <iostream>
#include <limits>
using namespace std;

class SinglyLinkedListNode
{
public:
    int data;
    SinglyLinkedListNode *next;

    SinglyLinkedListNode(int node_data)
    {
        this->data = node_data;
        this->next = nullptr;
    }
};

class SinglyLinkedList
{
public:
    SinglyLinkedListNode *head;
    SinglyLinkedListNode *tail;

    SinglyLinkedList()
    {
        this->head = nullptr;
        this->tail = nullptr;
    }
};

// Complete the insertSortedLinkedList function below.

/*
 * For your reference:
 *
 * SinglyLinkedListNode {
 *     int data;
 *     SinglyLinkedListNode* next;
 * };
 *
 */

// ###INSERT CODE HERE -

void insert_node(SinglyLinkedList *llist, int llist_item)
{
    SinglyLinkedListNode *node = new SinglyLinkedListNode(llist_item);
    if (llist->head == nullptr)
    {
        llist->head = node;
        llist->tail = node;
    }
    llist->tail->next = node;
    llist->tail = node;
}

void reverseLinkedList(SinglyLinkedList *llist)
{
    SinglyLinkedListNode *current = llist->head,
                         *next = nullptr,
                         *pre = nullptr;

    while (current != nullptr)
    {
        next = current->next;
        current->next = pre;
        pre = current;
        current = next;
    }
    llist->tail = llist->head;
    llist->head = pre;
}

void printLinkedList(SinglyLinkedList *llist)
{
    SinglyLinkedListNode *current = llist->head;
    while (current != nullptr)
    {
        cout << current->data << " ";
        current = current->next;
    }
}

int main()
{
    SinglyLinkedList *llist = new SinglyLinkedList();
    int llist_count;

    cin >> llist_count;

    for (int i = 0; i < llist_count; i++)
    {
        int llist_item;
        cin >> llist_item;

        insert_node(llist, llist_item);
    }

    reverseLinkedList(llist);
    printLinkedList(llist);

    return 0;
}
