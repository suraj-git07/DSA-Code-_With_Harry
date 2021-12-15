#include <iostream>
using namespace std;

class Node
{
public:
    int data;
    Node *next;
};

// Function for traversing
void linked_list_traverse(Node *ptr)
{

    while (ptr != NULL)
    {

        cout << "Element: " << ptr->data << endl;
        ptr = ptr->next;
    }
}

//   INSERTION IN LINKED LIST

// Function for Inserting in the begining
Node *Insert_At_First(Node *head, int data)
{
    Node *ptr = new Node();
    ptr->next = head;
    ptr->data = data;
    return ptr;
}

// Function for Inserting at index
Node *Insert_At_Index(Node *head, int data, int index)
{
    Node *ptr = new Node();
    Node *p = head;
    int i = 0;
    while (i != index - 1)
    {
        p = p->next;
        i++;
    }
    ptr->data = data;
    ptr->next = p->next;
    p->next = ptr;
    return head;
}

// Function for Insering At end
Node *Insert_At_End(Node *head, int data)
{
    Node *ptr = new Node();
    ptr->data = data;
    Node *p = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    p->next = ptr;
    ptr->next = NULL;
    return head;
}

// Function for Insering After a Node
Node *Insert_After_Node(Node *head, Node *prevNode, int data)
{
    Node *ptr = new Node();
    ptr->data = data;

    ptr->next = prevNode->next;
    prevNode->next = ptr;

    return head;
}

//   DELITION IN LINKED LIST

// Function to delete the First Node, In the Linked list
Node *Delete_At_First(Node *head)
{
    Node *ptr = head;
    head = head->next;
    delete ptr; // free the space of first node
    return head;
}

// Function to delete any Node with given index, In the Linked list
Node *Delete_node_between(Node *head, int index)
{
    Node *p = head;
    Node *q = head;

    int i = 0, j = 0;
    while (i < index)
    {
        p = p->next;
        i++;
    }

    while (j < index - 1)
    {
        q = q->next;
        j++;
    }

    q->next = p->next;
    delete p;

    return head;
}

// Function to delete last Node, In the Linked list
Node *Delete_last_node(Node *head)
{
    Node *p = head;
    Node *q = head;
    while (p->next != NULL)
    {
        p = p->next;
    }
    while (q->next != p)
    {
        q = q->next;
    }

    q->next = NULL;
    delete p;

    return head;
}

// Function to deLete First Node With Given Value
Node *Delete_with_val(Node *head, int value)
{
    Node *p = head;
    Node *q = head;
    while (p->data != value && p->next != NULL)
    {
        p = p->next;
    }
    while (q->next != p)
    {
        q = q->next;
    }

    q->next = p->next;
    delete p;

    return head;
}

int main()
{
    Node *head;
    Node *second;
    Node *third;

    // Allocating memory for nodes in the linked list in Heap

    head = new Node();
    second = new Node();
    third = new Node();

    // link First and Second Nodes
    head->data = 7;
    head->next = second;

    // link Second and Third Nodes
    second->data = 13;
    second->next = third;

    // link third node to Null
    third->data = 14;
    third->next = NULL;

    linked_list_traverse(head);

    // head = Insert_At_First(head , 56);  //changed the head

    // head = Insert_At_Index(head, 56, 1); // inserting at index , without changing the head  ,no work for index = 0

    // head = Insert_At_End(head, 12); // inserting at End , without changing the head

    // head = Insert_After_Node(head, second, 36); // inserting after second , without changing the head

    cout << endl;

    // head = Delete_At_First(head);

    // head = Delete_node_between(head,1);

    // head = Delete_last_node(head);

    head = Delete_with_val(head, 13);
    linked_list_traverse(head);

    return 0;
}