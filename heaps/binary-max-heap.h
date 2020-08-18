#ifndef __BINARY_MAX_HEAP__
#define __BINARY_MAX_HEAP__
#define MAX 100
class MaxHeap
{
private:
    int tree[MAX];
    int total_nodes;
    const int capacity;
    int parent(int node);
    int left_child(int node);
    int right_child(int node);
    void max_heapify(int i);
public:
    MaxHeap(int level);
    ~MaxHeap();
    bool isEmpty();
    bool isFull();
    void insert(int key);
    int peek();
    int pop();
    int size();
    void traverse();
};

#endif