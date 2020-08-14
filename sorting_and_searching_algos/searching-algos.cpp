#include "searching-algos.h"
#include <iostream>
#include <cmath>
using namespace std;

int linear_search(int array[], int array_size, int key)
{
    int count = 0; // variable to count the comparisons.
    int index = -1;
    for (int i = 0; i < array_size; i++)
    {
        count++;
        if (key == array[i])
        {
            index = i;
            break;
        }
    }
    cout << "Linear Search Comparisons : " << count << endl;
    return index;
}

int binary_search(int array[], int array_size, int key)
{
    int count = 0;
    int index = -1;
    int start = 0, end = array_size;
    while (start <= end)
    {
        int middle = (start + end) / 2;
        count++;
        if (key == array[middle])
        {
            index = middle;
            break;
        }
        else if (key < array[middle])
            end = middle - 1;
        else
            start = middle + 1;
    }
    cout << "Binary Search Comparisons : " << count << endl;
    return index;
}

int interpolation_search(int array[], int array_size, int key)
{
    int count = 0;
    int index = -1;
    int start = 0, end = array_size;
    while (start <= end)
    {
        int mid = start + (end - start) * ((key - array[start]) / (array[end] - array[start]));
        count++;
        if (key == array[mid])
        {
            index = mid;
            break;
        }
        else if (key < array[mid])
            end = mid - 1;
        else
            start = mid + 1;
    }
    cout << "Interpolation Search Comparisons : " << count << endl;
    return index;
}

int jump_search(int array[], int array_size, int key)
{
    int step = sqrt(array_size);
    int prev = 0;
    while (array[std::min(step, array_size) - 1] < key) {
        prev = step;
        step += sqrt(array_size);
        if (prev >= array_size)
            return -1;   
    }

    while (array[prev] < key) {
        prev++;
        if (prev == std::min(step, array_size))
            return -1;
    }

    if (array[prev] == key)
        return prev;
    return -1;
}