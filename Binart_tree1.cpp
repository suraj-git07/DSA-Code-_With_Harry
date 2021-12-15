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

// Pre-Order Traversal 

void preOrderTraversal(Binary_node* root){
    if (root != NULL)
    {
        cout<<root->data<<" ";
        preOrderTraversal(root->left_node);
        preOrderTraversal(root->right_node);
    }
    
}

// Post-Order Traversal 

void postOrderTraversal(Binary_node* root){
    if (root != NULL)
    {
        postOrderTraversal(root->left_node);
        postOrderTraversal(root->right_node);
        cout<<root->data<<" ";
    }
    
}

// In-Order Traversal 

void InOrderTraversal(Binary_node* root){
    if (root != NULL)
    {
        InOrderTraversal(root->left_node);
        cout<<root->data<<" ";
        InOrderTraversal(root->right_node);
    }
    
}





int main()
{
    
    Binary_node *p = create_node(4);  
    Binary_node *p1 = create_node(1); 
    Binary_node *p2 = create_node(6); 
    Binary_node *p3 = create_node(5); 
    Binary_node *p4 = create_node(2); 

    /*
     Finally the tree looks like

                4
              /   \
            1      6
          /  \
        5     2

        
    */

    // Linking the root node
    p->left_node = p1;
    p->right_node = p2;
    p1->left_node = p3;
    p1->right_node = p4;


    // preOrderTraversal(p);
    
    // postOrderTraversal(p);
    
    // InOrderTraversal(p);

    return 0;
}