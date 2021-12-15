#include <iostream>
#include <algorithm>
using namespace std;

template <class T>
class Myarr
{
public:
    int total_size;
    int used_size;
    T *ptr;

    Myarr(int tsize, int usize) // Constructor , taking  total and used size and reserve memry  of total size
    {
        total_size = tsize;
        used_size = usize;
        ptr = new T[total_size];
    }

    void set_data(int i, T value) // used to set data of perticular index
    {

        *(ptr + i) = value;
    }

    void insertion(int idx, T value) // Inserting an ele at index idx
    {
        if (used_size < total_size)
        {
            for (int i = used_size - 1; i >= idx; i--)
            {
                *(ptr + i + 1) = *(ptr + i);
            }
            *(ptr + idx) = value;
            used_size++;
        }

        else
        {
            cout << "Overflow!!!" << endl;
        }
    }

    void deletion(int idx) // Deleting  an ele at index idx
    {
        if (*(ptr + idx))
        {
            for (int i = idx; i < used_size; i++)
            {
                *(ptr + i) = *(ptr + i + 1);
            }
            *(ptr + used_size) = 0;
            used_size--;
        }
        else
        {

            cout << "No element at " << idx << " index!!" << endl;
        }
    }

    int search(T value) // Use binary_search to find a given element
    {
        int low = 0;
        int high = used_size - 1;

        // sort(ptr , ptr + used_size);

        sort(ptr, ptr + used_size);

        while (low <= high)
        {
            int mid = (low + high) / 2;

            if (value == (*(ptr + mid)))
            {

                return mid;
            }

            else if (value < (*(ptr + mid)))
            {
                high = mid - 1;
            }

            else
            {
                low = mid + 1;
            }
        }

        cout << "NOT FOUND !!!" << endl;
        return -1;
    }

    void display() // show the items of array  (used)
    {
        for (int i = 0; i < used_size; i++)
        {
            cout << (*(ptr + i)) << " ";
        }
        cout << endl;
    }
};

int main()
{
    Myarr<int> arr(10, 4);
    arr.set_data(0, 12);
    arr.set_data(1, 5);
    arr.set_data(2, 45);
    arr.set_data(3, 8);
    // arr.display();

    // arr.insertion(1, 2);
    // // arr.display();
    // arr.deletion(3);
    // arr.display();
    // arr.deletion(1);
    // arr.display();
    // arr.deletion(9);
    // arr.display();

    cout << arr.search(45);

    return 0;
}