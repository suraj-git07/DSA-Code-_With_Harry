#include <iostream>
#include <climits>
using namespace std;

void Count_sort(int *arr, int n)
{

    // Find the max ele in A
    int max = INT_MIN;
    for (int i = 0; i < n; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
        }
    }

    // making count arr and initializing it
    int *count = new int[max + 1];

    for (int i = 0; i < max + 1; i++)
    {
        count[i] = 0;
    }

    // incrimentation of count arr
    for (int i = 0; i < n; i++)
    {
        count[arr[i]]++;
    }

    // i is counter of count array , j is counter of given arr
    int i = 0, j = 0;

    while (i <= max)
    {
        if (count[i] > 0)
        {
            arr[j] = i;
            count[i]--;
            j++;
        }
        else
        {
            i++;
        }
    }
}

void printarr(int *arr, int n)
{
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    int n = 6;

    int arr[n] = {7, 2, 91, 77, 3, 81};

    printarr(arr, n);

    Count_sort(arr, n);

    cout <<endl;
    printarr(arr, n);

    return 0;
}