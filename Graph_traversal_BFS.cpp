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

int main()
{
    // Initializing Queue
    Queue *Exploration_Queue = new Queue();
    Exploration_Queue->size = 400;
    Exploration_Queue->frt_idx = Exploration_Queue->back_idx = -1;
    Exploration_Queue->arr = new int[Exploration_Queue->size];

    // BFS Implementation
    
    int i = 0; // first node of graph visited

    int visited[7] = {0, 0, 0, 0, 0, 0, 0};

    // a representing the graph
    int a[7][7] = {

        {0, 1, 1, 1, 0, 0, 0},
        {1, 0, 0, 1, 0, 0, 0},
        {1, 1, 0, 1, 1, 0, 0},
        {1, 0, 1, 0, 1, 0, 0},
        {0, 0, 1, 1, 0, 1, 1},
        {0, 0, 0, 0, 1, 0, 0},
        {0, 0, 0, 0, 1, 0, 0}};

    cout << i;
    visited[i] = 1;
    enQueue(Exploration_Queue, i); // enqueue i for exploration

    while (!isEmpty(Exploration_Queue))
    {
        int node = deQueue(Exploration_Queue);
        for (int j = 0; j < 7; j++)
        {
            if (a[node][j] == 1 && visited[j] == 0)
            {
                cout << j;
                visited[j] = 1;
                enQueue(Exploration_Queue, j);
            }
        }
    }

    return 0;
}