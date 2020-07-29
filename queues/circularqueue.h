#ifndef __CIRCULAR_QUEUE_H__
#define __CIRCULAR_QUEUE_H__

class CircularQueue
{
private:
    const int MAX;
    int size;
    int *storage;
    int rear, front;

public:
    CircularQueue();
    CircularQueue(int capacity);
    ~CircularQueue();
    void enqueue(int data);
    int dequeue();
    int peek();
    int length();
    bool isFull();
    bool isEmpty();
    void display();
};

#endif