#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

// Function for traversing
void linked_list_traverse(Node *head)
{
    Node *ptr = head;
    do
    {
        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    } while (ptr != head);
}

// Function for Inserting before current head
Node *Insert_At_First(Node *head, int data)
{
    Node *ptr = new Node();
    ptr->data = data;

    Node *p = head->next;
    while (p->next != head)
    {
        p = p->next;
    }

    p->next = ptr;
    ptr->next = head;

    return ptr;
}

int main()
{

    Node *Head, *Second, *Third, *Fourth;

    // Allocating memory for nodes in the linked list in Heap

    Head = new Node();
    Second = new Node();
    Third = new Node();
    Fourth = new Node();

    Head->data = 7;
    Head->next = Second;

    Second->data = 14;
    Second->next = Third;

    Third->data = 8;
    Third->next = Fourth;

    Fourth->data = 45;
    Fourth->next = Head; // Last Node Pointing To The First

    linked_list_traverse(Head);

    cout << endl;

    Head = Insert_At_First(Head, 5);
    linked_list_traverse(Head);

    return 0;
}