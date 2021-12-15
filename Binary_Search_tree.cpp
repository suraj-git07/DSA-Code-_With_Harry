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

// In-Order Traversal

void InOrderTraversal(Binary_node *root)
{
    if (root != NULL)
    {
        InOrderTraversal(root->left_node);
        cout << root->data << " ";
        InOrderTraversal(root->right_node);
    }
}

int isBST(Binary_node *root)
{
    static Binary_node* prev = NULL;
    
    if(root != NULL){
        if (!isBST(root->left_node))
        {
            return 0;
        }
        if (prev!= NULL && root->data <=prev->data)
        {
            return 0;
        }
        
        prev = root;
        return isBST(root->right_node);
        
    }

    else{
        return 1;
    }
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

    /*
     Finally the BST looks like

                 9
              /    \
            4      11
          /   \      \
        2      7      15
             /  \    /
            6   8   14


    */

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

    // InOrderTraversal(p); // Should give a sorted array , since tree is a BST

    cout<<isBST(p);

    return 0;
}