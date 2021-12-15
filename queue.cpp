#include <iostream>
using namespace std;

class Queue
{

public:
    int size;
    int frt_idx;
    int back_idx;
    int *arr;
};

int isEmpty(Queue *ptr)
{
    if (ptr->back_idx == ptr->frt_idx)
    {
        return 1;
    }

    return 0;
}

int isFull(Queue *ptr)
{
    if (ptr->back_idx == ptr->size - 1)
    {
        return 1;
    }

    return 0;
}

void enQueue(Queue *ptr, int value)
{

    if (isFull(ptr))
    {
        cout << "Queue overflow!!!" << endl;
    }

    else
    {
        ptr->back_idx++;
        ptr->arr[ptr->back_idx] = value;
    }
}

int deQueue(Queue *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "Queue Underflow!!!" << endl;
        return -1;
    }

    else
    {
        int a;
        ptr->frt_idx++;
        a = ptr->arr[ptr->frt_idx];
        return a;
    }
}

int peek(Queue* ptr, int idx){

    return ptr->arr[(ptr->frt_idx + 1) + idx];
}


int main()
{
    Queue *q = new Queue();
    q->size = 10;
    q->frt_idx = -1;
    q->back_idx = -1;
    q->arr = new int[q->size];

    // cout<<isEmpty(q);
    // cout<<isFull(q);

    enQueue(q, 10);
    enQueue(q, 15);
    enQueue(q, 4);
    enQueue(q, 80);
    enQueue(q, 11);
    enQueue(q, 8);

    // cout<<isEmpty(q);

    // int a = deQueue(q);
    // cout<<a<<endl;
    // cout<<isEmpty(q);

    cout<<peek(q , 2);
    cout<<endl;
    deQueue(q);
    deQueue(q);
    cout<<peek(q,2);

    return 0;
}