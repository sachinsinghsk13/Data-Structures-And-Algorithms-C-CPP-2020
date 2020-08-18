/**
 * Author: Sachin Singh
*/

#include "binary-max-heap.h"
#include <iostream>
#include <climits>
#include <cmath>
using namespace std;

MaxHeap::MaxHeap(int level) : capacity(MAX)
{
    total_nodes = 0;
}

MaxHeap::~MaxHeap()
{
    
}
bool MaxHeap::isEmpty()
{
    return total_nodes == 0;
}

bool MaxHeap::isFull()
{
    return total_nodes == capacity;
}

int MaxHeap::parent(int node)
{
    return (node == 0) ? -1 : (node - 1) / 2;
}

int MaxHeap::left_child(int node)
{
    int x = 2 * node + 1;
    return (x >= capacity) ? -1 : x;
}

int MaxHeap::right_child(int node)
{
    int x = 2 * node + 2;
    return (x >= capacity) ? -1 : x;
}

void MaxHeap::insert(int key)
{
    if (!isFull())
    {
        int loc = total_nodes;
        total_nodes++;
        tree[loc] = key;
        int p = parent(loc);
        while (p != -1)
        {
            if (tree[loc] > tree[p])
            {
                int tmp = tree[loc];
                tree[loc] = tree[p];
                tree[p] = tmp;
            }
            loc = p;
            p = parent(loc);
        }
    }
    else
    {
        cout << "Heap is Full " << endl;
    }
}

int MaxHeap::pop()
{
    if (total_nodes == 0)
        return INT_MIN;
    if (total_nodes == 1) {
        total_nodes--;
        return tree[0];
    }

    int result = tree[0];
    tree[0] = tree[total_nodes - 1];
    total_nodes--;
    max_heapify(0);
    return result;
}
void MaxHeap::max_heapify(int i) {
    int left = left_child(i);
    int right = right_child(i);
    int largest = i;
    if (left < total_nodes && tree[left] > tree[largest])
        largest = left;
    if (right < total_nodes && tree[right] > tree[largest])
        largest = right;
    if (largest != i) {
        int tmp = tree[largest];
        tree[largest] = tree[i];
        tree[i] = tmp;
        max_heapify(largest);
    }
}
int MaxHeap::peek()
{
    if (!isEmpty())
        return tree[0];
    return -1;
}

int MaxHeap::size()
{
    return total_nodes;
}

void MaxHeap::traverse()
{
    for (int i = 0; i < total_nodes; i++)
    {
        cout << tree[i] << " ";
    }
    cout << endl;
}