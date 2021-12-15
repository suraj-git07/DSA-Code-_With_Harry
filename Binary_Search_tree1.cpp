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

Binary_node *Search_recursive(Binary_node *root, int key)
{

    if (root == NULL)
    {
        return NULL;
    }

    if (root->data == key)
    {
        return root;
    }

    else if (root->data > key)
    {
        return Search_recursive(root->left_node, key);
    }

    else
    {
        return Search_recursive(root->right_node, key);
    }
}

Binary_node *Search_iter(Binary_node *root, int key)
{

    while (root != NULL)
    {
        if (root->data == key)
        {
            return root;
        }

        else if (root->data > key)
        {
            root = root->left_node;
        }

        else
        {
            root = root->right_node;
        }
    }

    return NULL; //empty tree
}

int main()
{

    Binary_node *p = create_node(9);
    Binary_node *p1 = create_node(4);
    Binary_node *p2 = create_node(11);
    Binary_node *p3 = create_node(2);
    Binary_node *p4 = create_node(7);
    Binary_node *p5 = create_node(15);
    Binary_node *p6 = create_node(6);
    Binary_node *p7 = create_node(8);
    Binary_node *p8 = create_node(14);

    // Linking the root node
    p->left_node = p1;
    p->right_node = p2;

    p1->left_node = p3;
    p1->right_node = p4;

    p2->left_node = NULL;
    p2->right_node = p5;

    p4->left_node = p6;
    p4->right_node = p7;

    p5->left_node = p8;
    p5->right_node = NULL;

    Binary_node *ptr = Search_iter(p, 7);
    if (ptr != NULL)
    {
        cout << "Element Found: " << ptr->data << endl;
        ;
    }
    else
    {
        cout << "Element Not Found !!!" << endl;
    }

    return 0;
}