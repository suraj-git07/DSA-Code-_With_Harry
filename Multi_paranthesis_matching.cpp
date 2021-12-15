#include <iostream>
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
        return '-1';
    }

    else
    {
        char val = ptr->arr[ptr->top];
        ptr->top--;
        return val;
    }
}

int main()
{

    // making a character array

    int size;
    cout << "Enter size: " << endl;
    cin >> size;
    char ar[size];
    cout << "Enter the expression :" << endl;
    for (int i = 0; i < size; i++)
    {
        cin >> ar[i];
    }

    // Creating a stack

    Stack *s = new Stack();
    s->size = size;
    s->top = -1;
    s->arr = new char[s->size];

    for (int i = 0; i < size; i++)
    {

        char exp = ar[i];
        if (exp == '(' || exp == '{' || exp == '[')
        {
            push(s, exp);
        }

        else if (exp == ')' || exp == '}' || exp == ']')
        {
            char val = pop(s);
            if (val == '-1')
            {
                cout << "Expression is Unbalanced !!" << endl;

                return 0;
            }

            if (exp == ')')
            {
                if (val != '(')
                {
                    cout << "Expression is Unbalanced !!" << endl;

                    return 0;
                }
            }
            
            if (exp == '{')
            {
                if (val != '}')
                {
                    cout << "Expression is Unbalanced !!" << endl;

                    return 0;
                }
            }
            
            if (exp == '[')
            {
                if (val != ']')
                {
                    cout << "Expression is Unbalanced !!" << endl;

                    return 0;
                }
            }
        }

        else
        {
        }
    }

    if (isEmpty(s))
    {
        cout << "Expression is balanced " << endl;
    }

    else
    {
        cout << "Expression is Unbalanced !!" << endl;
    }
    return 0;
}