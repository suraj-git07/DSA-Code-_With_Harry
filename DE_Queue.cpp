#include <iostream>
using namespace std;

class DEQueue
{

public:
    int size;
    int frt_idx;
    int back_idx;
    int *arr;
};

int isEmpty(DEQueue *ptr)
{
    if (ptr->back_idx == ptr->frt_idx)
    {
        return 1;
    }

    return 0;
}

int isFull(DEQueue *ptr)
{
    if (ptr->back_idx == ptr->size - 1)
    {
        return 1;
    }

    return 0;
}


void enQueue_R(DEQueue *ptr, int value)
{

    if (isFull(ptr))
    {
        cout << "DEQueue overflow!!!" << endl;
    }

    else
    {
        ptr->back_idx++;
        ptr->arr[ptr->back_idx] = value;
    }
}

void enQueue_F(DEQueue *ptr, int value)
{
    if (ptr->frt_idx == -1)
    {
        cout << "DEQueue overflow!!!" << endl;
    }
    
    else
    {
        ptr->arr[ptr->frt_idx] = value;
        ptr->frt_idx--;
    }
}

int deQueue_F(DEQueue *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "DEQueue Underflow!!!" << endl;
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

int deQueue_R(DEQueue *ptr)
{
    if (isEmpty(ptr))
    {
        cout << "DEQueue Underflow!!!" << endl;
        return -1;
    }

    else
    {
        int a;
        a = ptr->arr[ptr->back_idx];
        ptr->back_idx--;
        return a;
    }
}


int peek(DEQueue* ptr, int idx){

    if (idx > ptr->back_idx)
    {
        cout<<"Error"<<endl;
        return -1;
    }
    
    
    return ptr->arr[(ptr->frt_idx + 1) + idx];
}


int main()
{
    DEQueue *q = new DEQueue();
    q->size = 10;
    q->frt_idx = -1;
    q->back_idx = -1;
    q->arr = new int[q->size];

    enQueue_R(q,10);
    enQueue_R(q,8);
    enQueue_R(q,7);
    enQueue_R(q,4);
    // cout<<peek(q,2)<<endl;

    deQueue_R(q);
    deQueue_R(q);
    // enQueue_F(q,5);
    // cout<<peek(q,2)<<endl;

    return 0;
}