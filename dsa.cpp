#include <iostream>
#include "sorting_and_searching_algos/sorting-algos.h"
using namespace std;

void print(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << array[i] << " ";
    }
    cout << endl;
}

int main()
{
    int arr[] = {30, 52, 29, 87, 63, 27, 19, 54, 0};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 9;
    print(arr, size);
    merge_sort(arr, 0, size - 1);
    cout << "sorted array" << endl;
    print(arr, size);
    return 0;
}
