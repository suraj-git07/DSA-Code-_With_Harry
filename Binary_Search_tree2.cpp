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

// Insert function

void insert(Binary_node *root, int key)
{
    Binary_node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (key == root->data)
        {
            cout << "Cannot insert!!! " << endl;
            cout << "Element is already in the tree" << endl;
            return;
        }

        if (key > root->data)
        {
            root = root->right_node;
        }
        else
        {
            root = root->left_node;
        }
    }

    Binary_node *ptr = create_node(key);
    if (key < prev->data)
    {
        prev->left_node = ptr;
    }

    else
    {
        prev->right_node = ptr;
    }
}

// Inorder_Precedence func

Binary_node *inOrderPre(Binary_node *root)
{

    // Inorder-preceder is the right-most node of the left sub-tree of the particular node
    root = root->left_node;
    while (root->right_node != NULL)
    {
        root = root->right_node;
    }

    return root;
}

// Inorder_succesor func

Binary_node *inOrderSucc(Binary_node *root)
{

    // Inorder-succesor is the left-most node of the right sub-tree of the particular node

    Binary_node *current = root;
    current = current->right_node; // right subtree

    while (current && current->left_node != NULL)
    {
        current = current->left_node;
    }

    return current;
}

// Deletion Function

Binary_node *delete_node(Binary_node *root, int value)
{

    // Base case
    if (root == NULL)
    {
        return root;
    }

    // Search for the node to be deleted
    if (value < root->data)
    {
        // go for deletion process taking root->right  as root and del the key then, return the updated subtree
        root->left_node = delete_node(root->left_node, value);
    }

    else if (value > root->data)
    {
        root->right_node = delete_node(root->right_node, value);
    }

    // Deletion Strategy when the node is found

    else
    {
        // node has no child
        if (root->left_node == NULL && root->right_node == NULL)
        {
            return NULL;
        }

        // node with only one child or no child
        else if (root->left_node == NULL)
        {
            Binary_node *temp = root->right_node;
            delete root;
            return temp;
        }
        else if (root->right_node == NULL)
        {
            Binary_node *temp = root->left_node;
            delete root;
            return temp;
        }

        // node with two children: Get the inorder_preceder
        Binary_node *temp = inOrderPre(root);

        // copy the temp content to this node
        root->data = temp->data;

        // del the inorder_preceder
        root->left_node = delete_node(root->left_node, temp->data);
    }

    return root;
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

    InOrderTraversal(p);

    delete_node(p, 11);
    cout << endl;

    InOrderTraversal(p);

    return 0;
}