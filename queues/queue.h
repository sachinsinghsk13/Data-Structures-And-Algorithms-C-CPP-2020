#ifndef __QUEUE_H__
#define __QUEUE_H__

class Queue {
    private:
        const int MAX;
        int size;
        int *storage;
        int front, rear;
    public:
        Queue();
        Queue(int capacity);
        ~Queue();
        void enqueue(int data);
        int dequeue();
        int peek();
        int length();
        bool isFull();
        bool isEmpty();
        void display();
};

#endif