#ifndef __LINKED_QUEUE_H__
#define __LINKED_QUEUE_H__

class QueueNode
{
public:
    QueueNode();
    QueueNode(int data);
    ~QueueNode();
    int data;
    QueueNode *next;
};

class LinkedQueue
{
    private:
        QueueNode *front, *rear;
        int size;
    public:
        LinkedQueue();
        ~LinkedQueue();
        bool isEmpty();
        void enqueue(int data);
        int dequeue();
        int peek();
        int length();
};

#endif