#include "circularqueue.h"
#include <iostream>
using namespace std;

CircularQueue::CircularQueue() : MAX(10)
{
    size = 0;
    storage = new int[MAX];
    rear = front = -1;
}

CircularQueue::CircularQueue(int capacity) : MAX(capacity)
{
    size = 0;
    storage = new int[MAX];
    rear = front = -1;
}

CircularQueue::~CircularQueue() {}

bool CircularQueue::isFull()
{
    return (front == 0 && rear == MAX - 1) || (rear == front - 1);
}

bool CircularQueue::isEmpty()
{
    return front == -1;
}

void CircularQueue::enqueue(int data)
{
    if (!isFull())
    {
        rear = (rear + 1) % MAX;
        storage[rear] = data;
        if (front == -1)
            front = 0;
    }
    else
        std::cout << "Queue is Full." << std::endl;
}

int CircularQueue::dequeue()
{
    if (!isEmpty())
    {
        int data = storage[front];
        if (front == rear)
            front = rear = -1;
        else
            front = (front + 1) % MAX;
        return data;
    }
    else
        std::cout << "Queue is Empty." << std::endl;
    return -1;
}

int CircularQueue::peek()
{
    if (!isEmpty())
    {
        int data = storage[front];
        return data;
    }
    else
    {
        std::cout << "Queue is empty." << std::endl;
        return -1;
    }
}

void CircularQueue::display()
{
}

int CircularQueue::length()
{
    return size;
}
