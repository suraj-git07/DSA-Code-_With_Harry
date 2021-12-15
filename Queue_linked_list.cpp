#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

void enqueu(Node **f, Node **b, int val)
{

    Node *n = new Node();
    if (n == NULL)
    {
        cout << "Queue Overflow!!!" << endl;
    }

    else
    {
        n->data = val;
        n->next = NULL;

        if (*f == NULL) // case of Zero Nodes
        {
            *f = n;
            *b = n;
        }

        else
        {
            (*b)->next = n;
            (*b) = n;
        }
    }
}

int dequeue(Node **f)
{
    if (*f == NULL)
    {
        cout << "Queue Underflow !!!" << endl;
        return -1;
    }

    Node *n = *f;
    // cout<<(*f)->data<<endl;
    *f = (*f)->next;
    int val = n->data;
    delete n;
    return val;
}

// Function for traversing
void traverse(Node *ptr)
{

    while (ptr != NULL)
    {

        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

int main()
{
    Node *front = NULL; // front of Queue
    Node *back = NULL;  // Back of Queue

    enqueu(&front, &back, 15);
    enqueu(&front, &back, 12);
    enqueu(&front, &back, 11);
    enqueu(&front, &back, 16);

    // traverse(front);
    // cout<<endl;
    // cout<<dequeue(&front)<<endl;
    cout<<dequeue(&front)<<endl;
    cout<<dequeue(&front)<<endl;
    // cout<<dequeue(&front)<<endl;

    traverse(front);
    return 0;
}