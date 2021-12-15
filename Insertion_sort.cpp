#include <iostream>
using namespace std;

void Insertion_sort(int *arr, int n)
{
   int i , key ,j;
   for (int i = 0; i < n; i++)
   {
       key = arr[i];
       j = i-1;
       while (j>= 0 && arr[j]> key)
       {
           arr[j+1] = arr[j];
           j--;
       }
       arr[j+1] = key;
       
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

    // printarr(arr, n);

    Insertion_sort(arr, n);

    cout << endl;
    printarr(arr, n);

    return 0;
}