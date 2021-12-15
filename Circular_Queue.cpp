#include <iostream>
using namespace std;

class Queue
{
public:
    int size;
    int f;
    int b;
    int *arr;
};

void enque(Queue *ptr, int val)
{
    if (((ptr->b + 1) % ptr->size) == ptr->f) // ptr->b ka circular increment ptr->f  ke equal
    {
        cout << "Queue Overflow!!!" << endl;
    }

    else
    {
        ptr->b = ((ptr->b + 1) % ptr->size); // ptr->b ko circular increment karo
        ptr->arr[ptr->b] = val;
    }
}

int deque(Queue *ptr)
{
    if (ptr->b == ptr->f)
    {
        cout<<"Queue Underflow!!"<<endl;
        return -1;

    }

    else{
        int val;
        ptr->f = (ptr->f+1)%ptr->size;
        val = ptr->arr[ptr->f];
        return val;
    }
    
}

int main()
{
    Queue *q = new Queue();
    q->size = 11;
    q->f = 0;
    q->b = 0;
    q->arr = new int[q->size];
 
    enque(q,12);
    enque(q,1);
    enque(q,2);
    enque(q,10);
    enque(q,8);

    // cout<<deque(q)<<endl;
    // cout<<deque(q);
    
    return 0;
}