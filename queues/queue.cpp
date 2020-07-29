#include "queue.h"
#include <iostream>

Queue::Queue() : MAX(10)
{
    size = 0;
    storage = new int[MAX];
    front = rear = -1;
}

Queue::Queue(int capacity) : MAX(capacity)
{
    size = 0;
    storage = new int[MAX];
    front = rear = -1;
}

Queue::~Queue()
{
}

bool Queue::isEmpty()
{
    return front == -1;
}

bool Queue::isFull()
{
    return rear == MAX - 1;
}

void Queue::enqueue(int data)
{
    if (!isFull()) {
        rear = rear + 1;
        storage[rear] = data;
        if (front == -1)
            front = 0;
        size++;
    }
    else {
        std::cout << "Queue is full." << std::endl;        
    }
}

int Queue::dequeue() {
    if (!isEmpty()) {
        int data = storage[front];
        if (front == rear)
            front = rear = -1;
        else
            front = front + 1;
        size--;
        return data;
    }
    else {
        std::cout << "Queue is empty." << std::endl;
        return -1;
    }
}

int Queue::peek() {
    if (!isEmpty()) {
        int data = storage[front];
        return data;
    }
    else {
        std::cout << "Queue is empty." << std::endl;
        return -1;
    }
}


int Queue::length() {
    return size;
}

void Queue::display() {
    if (!isEmpty()) {
        std::cout << "front --> ";
        for (int i = front; i <= rear; i++)
            std::cout << storage[i] << " ";
        std::cout << " <-- rear" << std::endl;
    }
    else {
        std::cout << "Queue is empty." << std::endl;
    }
}