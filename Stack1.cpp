#include <iostream>
using namespace std;

class Stack
{

public:
    int size;
    int *arr;
    int top;
};

int isEmpty(Stack *ptr)
{
    if (ptr->top == -1)
    {
        // cout << "Stack Is Empty" << endl;
        return 1;
    }

    // cout << "Stack Is Not Empty" << endl;
    return 0;
}

int isFull(Stack *ptr)
{
    if (ptr->top == (ptr->size - 1))
    {
        // cout << "Stack is Full " << endl;
        return 1;
    }
    // cout << "Stack isn't Full " << endl;
    return 0;
}

int push(Stack *ptr, int value)
{
    if (isFull(ptr))
    {
        cout << "Stack Overflow !!" << endl;
        return -1;
    }

    else
    {
        ptr->top++;
        ptr->arr[ptr->top] = value;
        return 1;
    }
}

int pop(Stack *ptr) // pop and return the value
{
    if (isEmpty(ptr))
    {
        cout << "Stack Underflow !!" << endl;
        return -1;
    }

    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int peek(Stack *ptr, int i)
{

    if (i > (ptr->top + 1))
    {
        cout << "Invalid Peek!!!" << endl;
        return -1;
    }
    else
        return ptr->arr[ptr->top - i + 1];
}

int main()
{
    Stack *s = new Stack();
    s->size = 10;
    int val = s->size;
    s->arr = new int[val];
    s->top = -1;

    push(s, 10);
    // cout << pop(s);
    // cout << endl;
    // cout << pop(s);

    push(s,11);
    push(s,15);
    push(s,7);
    // cout<<s->top;
    // cout<<peek(s,1)<<endl;
    // cout<<peek(s,2)<<endl;
    // cout<<peek(s,3)<<endl;
    // cout<<peek(s,4)<<endl;
    // cout<<peek(s,5)<<endl;
    // cout<<peek(s,6)<<endl;

    

    return 0;
}