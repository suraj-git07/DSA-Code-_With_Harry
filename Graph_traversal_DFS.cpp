// We use stack to implement this , but since func use stack already so we don't have to implement it #include <iostream>
#include <iostream>
using namespace std;

// DFS Implementation

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

void DFS(int i)
{
    
    cout << i;
    visited[i] = 1;
    for (int j = 0; j < 7; j++)
    {
        if (a[i][j] == 1 && !visited[j])
        {
            DFS(j);
        }
    }
}

int main()
{

    // start with n  node

    DFS(0);

    return 0;
}