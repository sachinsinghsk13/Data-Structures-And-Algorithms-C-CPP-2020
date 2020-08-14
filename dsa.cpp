#include <iostream>
#include "sorting_and_searching_algos/searching-algos.h"
using namespace std;

int main()
{
    int arr[] = {0, 2, 4, 7, 8, 9, 11, 15, 16, 23, 45, 50, 65};
    int size = sizeof(arr) / sizeof(arr[0]);
    int key = 9;
    cout << linear_search(arr, size, key) << endl;
    cout << binary_search(arr, size, key) << endl;
    cout << interpolation_search(arr, size, key) << endl;
    cout << jump_search(arr, size, key) << endl;
    return 0;
}
