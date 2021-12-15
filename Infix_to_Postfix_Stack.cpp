#include <iostream>
#include <string>
using namespace std;

class Stack
{

public:
    int size;
    char *arr;
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

int push(Stack *ptr, char value)
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

char pop(Stack *ptr) // pop and return the value
{
    if (isEmpty(ptr))
    {
        cout << "Stack Underflow !!" << endl;
        return '0';
    }

    else
    {
        int val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

char stack_top(Stack *ptr)
{
    return ptr->arr[ptr->top];
}

// Precedence Function

int prece(char a, char b)
{
    if (a == '/' || a == '*')
    {
        if (b == '*' || b == '/')
        {
            return 0;
        }
        return 1;
    }

    if (a == '+' || a == '-')
    {
        if (b == '/' || b == '*' || b == '+' || b == '-')
        {
            return 0;
        }
        return 1;
    }
}

// other way to implement precedence function

// int prece(char val){
//     if (val == '*' || val == '/')
//     {
//         return 3;
//     }

//     if (val == '+' || val =='-')
//     {
//         return 2;
//     }
    
    
// }

// isOperator function

int isOperator(char val)
{

    char op[4] = {'+', '-', '*', '/'};
    for (int i = 0; i < 4; i++)
    {
        if (val == op[i])
        {
            return 1;
        }
    }

    return 0;
}

int main()
{
    // Creating an ecprression array(infix)

    int size;
    cout << "Enter the size: " << endl;
    cin >> size;
    char infix[size];
    cout << "Enter the infix expression " << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> infix[i];
    }

    // Creating postfix array and Stack

    char *postfix = new char[size];
    Stack *s = new Stack();
    s->size = size;
    s->top = -1;
    s->arr = new char[s->size];

    int i = 0, j = 0;

    // Main program , travesing the expression

    for (i = 0; i < size; i++)
    {
        if (isOperator(infix[i]))
        {
            if (prece(infix[i] , stack_top(s)))
            {
                push(s, infix[i]);
            }

            else
            {
                char val = pop(s);
                postfix[j] = val;
                j++;
                i--;
            }
        }

        else
        {
            postfix[j] = infix[i];
            j++;
        }
    }

    // After traversing checking weather the stack is empty or not, then doing the remaining work

    if (isEmpty(s))
    {
        cout << "Here's the Postfix Expression :" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << postfix[i] << " ";
        }
    }

    else
    {
        while (s->top != -1)
        {
            char val = pop(s);
            postfix[j] = val;
            j++;
        }

        cout << "Here's the Postfix Expression :" << endl;
        for (int i = 0; i < size; i++)
        {
            cout << postfix[i];
        }
    }
    cout<<endl;

    return 0;
}