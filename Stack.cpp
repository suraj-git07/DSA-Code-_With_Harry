#include <iostream>
using namespace std;

class Stack
{
public:
    int size;
    int top;
    int *arr;
};

int isEmpty(Stack *ptr)
{

    if (ptr->top < 0)
    {
        return 1;
    }
    return 0;
}

int isFull(Stack *ptr)
{
    if (ptr->top == (ptr->size - 1))
    {
        return 1;
    }
    return 0;
}

int main()
{
    // Stack s;
    // s.size = 10;
    // s.top = -1 ;   // Initially top = -1 that means stack is empty
    // s.arr = new int[s.size];

    Stack *s = new Stack(); // Ye Isliye Taki Easily Func me Pass Kara Ja sake
    s->size = 10;
    s->top = -1;
    s->arr = new int[s->size];

    cout << isFull(s) << endl;
    cout<<isEmpty(s)<<endl;

    return 0;
}