#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void linked_list_traverse(Node *top)
{

    while (top != NULL)
    {

        cout << "Element: " << top->data << endl;
        top = top->next;
    }
}

int isEmpty(Node *top)
{
    if (top == NULL)
    {
        return 1;
    }
    else
        return 0;
}

int isFull(Node *top)
{
    Node *p = new Node();
    if (p == NULL)
    {
        return 1;
    }
    else
        return 0;
}

Node *push(Node *top, int x)
{
    if (isFull(top))
    {
        cout << "Stack Overflow!!! " << endl;
    }

    else
    {
        Node *n = new Node();
        n->data = x;
        n->next = top;
        top = n;
        return top;
    }
}

int pop(Node **top)
{
    if (isEmpty(*top))
    {
        cout << "Stack Underflow !!!" << endl;
    }
    else
    {
        Node *n = *top;
        *top = (*top)->next;
        int x = n->data;
        delete n;
        return x;
    }
}

int peek(Node *top, int pos)
{
    Node *ptr = top;
    for (int i = 0; (i < (pos - 1)) && (ptr != NULL) ; i++)
    {
        ptr = ptr->next;
    }

    if (ptr != NULL)
    {
        return ptr->data;
    }

    else
        return -1;
}

int main()
{
    Node *top = NULL;
    top = push(top, 78);
    top = push(top, 12);
    top = push(top, 8);

    // cout << endl;
    // int ele = pop(&top);
    // cout << endl;
    // linked_list_traverse(top);

    cout<<peek(top, 3);

        return 0;
}