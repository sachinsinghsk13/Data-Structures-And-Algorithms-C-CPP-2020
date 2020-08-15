#include "sorting-algos.h"

/*
    Bubble Sort
*/
void bubble_sort(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;
            }
        }
    }
}

/*
    Optimized Bubble Sort Algorithm
*/
void bubble_sort_optimized(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        bool flag = true; // assume that our array is sorted so set flag to true
        for (int j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                int tmp = array[j];
                array[j] = array[j + 1];
                array[j + 1] = tmp;

                flag = false; // swapping is made because our assumtion is wrong so set flag to false
            }
        }
        if (flag) // if our assumption is true then no need to sort further and return now
            return;
    }
}

void insertion_sort(int array[], int size)
{
    for (int i = 1; i < size; i++)
    {
        int j = i - 1;
        while (array[j] > array[j + 1] && j >= 0)
        {
            int tmp = array[j];
            array[j] = array[j + 1];
            array[j + 1] = tmp;
            j--;
        }
    }
}

void selection_sort(int array[], int size)
{
    for (int i = 0; i < size; i++)
    {
        int min = i;
        for (int j = i + 1; j < size; j++)
        {
            if (array[j] < array[min])
                min = j;
        }
        int tmp = array[i];
        array[i] = array[min];
        array[min] = tmp;
    }
}

void merge_sort(int array[], int start, int end)
{
    if (start < end)
    {
        int mid = (start + end) / 2;
        merge_sort(array, start, mid);
        merge_sort(array, mid + 1, end);
        merge(array, start, mid, end);
    }
}

void merge(int array[], int start, int mid, int end)
{
    int temp[100], i = start, j = mid + 1, index = start;

    while (i <= mid && j <= end)
    {
        if (array[i] < array[j])
        {
            temp[index] = array[i];
            i++;
        }
        else
        {
            temp[index] = array[j];
            j++;
        }
        index++;
    }

    if (i > mid)
    {
        while (j <= end)
        {
            temp[index] = array[j];
            index++;
            j++;
        }
    }
    else
    {
        while (i <= mid)
        {
            temp[index] = array[i];
            index++;
            i++;
        }
    }

    for (int k = start; k < index; k++)
        array[k] = temp[k];
}

void quick_sort(int array[], int start, int end)
{
    if (start < end)
    {
        int loc = partition(array, start, end);
        quick_sort(array, start, loc);
        quick_sort(array, loc + 1, end);
    }
}

int partition(int array[], int start, int end)
{
    int left = start, loc = start, right = end;
    bool flag = false;

    while (!flag)
    {
        while (array[loc] <= array[right] && loc != right)
            right--;
        if (loc == right)
            flag = true;
        else if (array[loc] > array[right])
        {
            int temp = array[loc];
            array[loc] = array[right];
            array[right] = temp;
            loc = right;
        }

        if (!flag)
        {
            while (array[loc] >= array[left] && loc != left)
                left++;
            if (loc == left)
                flag = true;
            else if (array[loc] < array[left])
            {
                int temp = array[loc];
                array[loc] = array[left];
                array[left] = temp;
                loc = left;
            }
        }
    }
    return loc;
}