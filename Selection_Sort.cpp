#include <iostream>
using namespace std;

void Selection_sort(int *arr, int n)
{

    int index_of_min;
    for (int i = 0; i < n - 1; i++)
    {
        index_of_min = i;

        for (int j = i + 1; j < n ; j++)
        {
            if (arr[j] < arr[index_of_min])
            {
                index_of_min = j;
            }
        }

        int temp = arr[i];
        arr[i] = arr[index_of_min];
        arr[index_of_min] = temp;
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

    Selection_sort(arr, n);

    cout << endl;
    printarr(arr, n);

    return 0;
}