#include <iostream>
using namespace std;

void merge(int *arr, int low, int high, int mid)
{
    int i, j, k, temp[high - low + 1];

    i = low;
    k = 0;
    j = mid + 1;

    while (i <= mid && j <= high)
    {
        if (arr[i] < arr[j])
        {
            temp[k] = arr[i];
            k++;
            i++;
        }
        else
        {
            temp[k] = arr[j];
            k++;
            j++;
        }
    }

    while (i <= mid)
    {
        temp[k] = arr[i];
        k++;
        i++;
    }

    while (j <= high)
    {
        temp[k] = arr[j];
        k++;
        j++;
    }

    for (int i = low; i <= high; i++)
    {
        arr[i] = temp[i - low];   // important line
    }
}

void merge_sort(int *arr, int low, int high)
{
    int mid;
    if (low < high)
    {
        mid = (low + high) / 2;
        merge_sort(arr, low, mid);
        merge_sort(arr, mid + 1, high);

        merge(arr, low, high, mid);
    }
}

void print_arr(int*arr ,int n){
    for (int i = 0; i < n; i++)
    {
        cout<<arr[i]<<" ";
    }
    
}

int main()
{
    int n =9;
    int arr[n] = {45,2,8,12,1,65,12,29,0};

    print_arr(arr,n);

    merge_sort(arr , 0 , n-1);
    cout<<endl;
    print_arr(arr,n);
    


    return 0;
}