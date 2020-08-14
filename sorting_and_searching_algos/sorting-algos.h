#ifndef __SORTING_ALGORITHMS__
#define __SORTING_ALGORITHMS__

void bubble_sort(int array[], int size); 
void bubble_sort_optimized(int array[], int size); 
void insertion_sort(int array[], int size);
void selection_sort(int array[], int size);

// merge sort
void merge_sort(int array[], int start, int end);
void merge(int array[], int start, int mid, int end);

#endif