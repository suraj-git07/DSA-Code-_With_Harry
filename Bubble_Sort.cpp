#include <iostream>
using namespace std;

// Not Adaptive Algo
void bubble_sort(int *arr, int n)
{
    // Innner and Outer Loop run same time

    for (int i = 0; i < (n - 1); i++) // For no of pass
    {
        for (int j = 0; j < (n - 1) - i; j++) // For no of comparison
        {
            if (arr[j] > arr[j + 1])
            {
                // swap
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

// Adaptive Algo 
void bubble_sort_A(int *arr, int n)
{
    int isSorted = 0;

    // Sorted array Single sort me hi bata dega  , O(n)
    
    for (int i = 0; i < (n - 1); i++)
    {
        
        cout<<"Working on pass No "<<i+1<<endl;
        isSorted = 1;

        for (int j = 0; j < (n - 1) - i; j++) // Agar array Sorted hai to ye condition kabhi true nahi hogi
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;

                isSorted = 0;
            }
        }

        if (isSorted)  
        {
            return;
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

    int arr[n] = {7, 11, 9, 2, 17, 4};

    int arr2[n] = {1, 2, 3, 4, 5, 6}; // for Adaptive checking

    int arr3[n] = {3,2,1,4,5,6};  
    // printarr(arr, n);

    bubble_sort_A(arr3, n);

    cout << endl;
    printarr(arr3, n);

    return 0;
}