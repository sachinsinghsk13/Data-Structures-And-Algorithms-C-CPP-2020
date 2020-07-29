#include "linkedqueue.h"
#include <iostream>

QueueNode::QueueNode() {
    data = 0;
    next = nullptr;
}

QueueNode::QueueNode(int data) {
    this->data = data;
    next = nullptr;
}

QueueNode::~QueueNode() {}

LinkedQueue::LinkedQueue() {
    front = rear = nullptr;
    size = 0;
}

LinkedQueue::~LinkedQueue() {}

bool LinkedQueue::isEmpty() {
    return front == nullptr;
}

void LinkedQueue::enqueue(int data) {
    QueueNode *node = new QueueNode(data);
    if (rear == nullptr) {
        rear = front = node;
    }
    else {
        rear->next = node;
        rear = node;
    }
    size++;
}

int LinkedQueue::dequeue() {
    if (!isEmpty()) {
        int data = front->data;
        if (front == rear)
            front = rear = nullptr;
        else {
            QueueNode *temp = front;
            front = front->next;
            delete temp;
        }
        size--;
        return data;
    }
    else
    {
        std::cout << "Queue is Empty." << std::endl;
        return -1;
    }
}

int LinkedQueue::peek() {
    if (!isEmpty()) {
        return front->data;
    }
    else {
        std::cout << "Queue is Empty." << std::endl;
        return -1;
    }
}

int LinkedQueue::length() {
    return size;
}