#include <iostream>
using namespace std;

// int partition(int *arr, int low, int high)
// {
//     int pivot = arr[low];
//     int i = low + 1;
//     int j = high;

//     while (arr[i] <= pivot)
//     {
//         i++;
//     }

//     do
//     {

//         while (arr[j] > pivot)
//         {
//             j--;
//         }

//         if (i < j)
//         {
//             int temp = arr[j];
//             arr[j] = arr[i];
//             arr[i] = temp;
//         }

//     } while (i < j);

//     int temp = arr[low];
//     arr[low] = arr[j];
//     arr[j] = temp;

//     return j;
// }

int partition(int *arr, int low, int high)
{
    int pivot = arr[low];
    int i = low + 1;
    int j = high;

    do    // do-while isliye taki 2 ele wali array bhi sort ho jae
    {
        // Finding i = ele greater than pivot
        while (arr[i] <= pivot)
        {
            i++;
        }

        // Finding j = ele less than or equal to pivot
        while (arr[j] > pivot)
        {
            j--;
        }

        // swap i and j ele , given condition is true
        if (i < j)
        {
            int temp = arr[j];
            arr[j] = arr[i];
            arr[i] = temp;
        }

    }while (i < j);
 
    //Finally swapping arr[j] with pivot and returning j = partitioning index
    int temp = arr[low];
    arr[low] = arr[j];
    arr[j] = temp;

    return j;
}

void Quick_sort(int *arr, int low, int high)
{
    int partition_index; // Index of Pivot After Partion

    if (low < high)
    {

        partition_index = partition(arr, low, high);

        Quick_sort(arr, low, partition_index - 1);  // sort left subarray
        Quick_sort(arr, partition_index + 1, high); // sort right subarray
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
    int n = 9;

    int arr[n] = {48, 2, 1, 15, 74, 61, 54, 29, 66};

    printarr(arr, n);

    Quick_sort(arr, 0, n - 1);

    cout << endl;
    printarr(arr, n);

    return 0;
}