// AVL named after inventors Adelson - Velsky - Landis

#include <iostream>
using namespace std;

class Node
{
public:
    int key;
    Node *left;
    Node *right;
    int height;
};

int getHeight(Node *n)
{
    if (n == NULL)
    {
        return 0;
    }
    return n->height;
}

Node *createNode(int key)
{
    Node *n = new Node();
    n->key = key;
    n->left = NULL;
    n->right = NULL;
    n->height = 1; //any new node would be a leaf node of height one
    return n;
}

int getBalanceFac(Node *n)
{
    if (n == NULL)
    {
        return 0;
    }

    return getHeight(n->left) - getHeight(n->right);
}

Node *rightRotate(Node *y)
{
    Node *x = y->left;
    Node *T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return x;
}

Node *leftRotate(Node *x)
{
    Node *y = x->right;
    Node *T2 = y->left;

    x->right = T2;
    y->left = x;

    y->height = max(getHeight(y->left), getHeight(y->right)) + 1;
    x->height = max(getHeight(x->left), getHeight(x->right)) + 1;

    return y;
}

Node *insert(Node *node, int key)
{
    if (node == NULL)
    {
        return createNode(key);
    }

    if (key < node->key)
    {
        node->left = insert(node->left, key);
    }

    else if (key > node->key)
    {
        node->right = insert(node->right, key);
    }

    node->height = max(getHeight(node->left), getHeight(node->right)) + 1;
    int bf = getBalanceFac(node);

    // left Left Case

    if (bf > 1 && key < node->left->key)
    {
        return rightRotate(node);
    }

    // Right Right Case
    if (bf < -1 && key > node->right->key)
    {
        return leftRotate(node);
    }

    // left Right Case

    if (bf > 1 && key > node->left->key)
    {
        node->left = leftRotate(node->left);
        return rightRotate(node);
    }

    // Right Left Case
    if (bf < -1 && key < node->right->key)
    {
        node->right = rightRotate(node->right);
        return leftRotate(node);
    }

    return node;
}

void preOrderTraversal(Node *root)
{
    if (root != NULL)
    {
        cout << root->key << " ";
        preOrderTraversal(root->left);
        preOrderTraversal(root->right);
    }
}

int main()
{
    Node *root = NULL;
    root = insert(root, 1);
    root = insert(root, 2);
    root = insert(root, 4);
    root = insert(root, 5);
    root = insert(root, 6);
    root = insert(root, 3);

    preOrderTraversal(root);

    return 0;
}