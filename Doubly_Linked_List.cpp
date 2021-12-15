#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *prev;
    Node *next;
};

void traversing(Node *head)
{
    Node *p = head;
    while (p->next != NULL)
    {
        cout << "Element: " << p->data << endl;
        p = p->next;
    }
    cout << "Element: " << p->data << endl; // data of last node

    cout << endl;
    while (p != NULL)      // for re-traversing 
    {
        cout << "Element: " << p->data << endl;
        p = p->prev;
    }
}

int main()
{

    Node *head = new Node();
    Node *second = new Node();
    Node *third = new Node();
    Node *fourth = new Node();

    head->data = 7;
    head->prev = NULL;
    head->next = second;

    second->data = 4;
    second->prev = head;
    second->next = third;

    third->data = 46;
    third->prev = second;
    third->next = fourth;

    fourth->data = 12;
    fourth->prev = third;
    fourth->next = NULL;

    traversing(head);

    return 0;
}