#include <iostream>
#include "sorting_and_searching_algos/sorting-algos.h"
using namespace std;

void print(int array[], int size) {
    for (int i = 0; i < size; i++)
        cout << array[i] << " ";
    cout << endl;
}

int main()
{
    int array[] = {27, 10, 36, 18, 25, 45, 0};
    int size = sizeof(array)/sizeof(array[0]);
    print(array, size);
    quick_sort(array, 0, size - 1);
    print(array, size);
    return 0;
}
