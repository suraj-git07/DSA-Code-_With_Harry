#include <iostream>
using namespace std;

class Binary_node
{

public:
    int data;
    Binary_node *left_node;
    Binary_node *right_node;
};

Binary_node *create_node(int data)
{
    Binary_node *n = new Binary_node(); // root node
    n->data = data;
    n->left_node = NULL;
    n->right_node = NULL;

    return n;
}

int main()
{
    /*
    Binary_node* p = new Binary_node();  // root node
    p->data = 7;
    p->left_node = NULL;
    p->right_node = NULL;

    Binary_node* p1 = new Binary_node();  // left of root node
    p1->data = 1;
    p1->left_node = NULL;
    p1->right_node = NULL;

    Binary_node* p2 = new Binary_node();  // right of root node
    p2->data = 4;
    p2->left_node = NULL;
    p2->right_node = NULL;

    */

    Binary_node *p = create_node(7);  // root node;
    Binary_node *p1 = create_node(1); // left node
    Binary_node *p2 = create_node(2); // right node

    // Linking the root node
    p->left_node = p1;
    p->right_node = p2;

    return 0;
}