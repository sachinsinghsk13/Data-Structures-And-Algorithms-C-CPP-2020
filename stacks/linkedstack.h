#ifndef __LINKED_STACK_H__
#define __LINKED_STACK_H__

class StackNode {
    public:
        int data;
        StackNode *next;
        StackNode();
        ~StackNode();
};

class LinkedStack
{
private:
    StackNode *top;
    int stackSize;
public:
    LinkedStack();
    ~LinkedStack();
    void push(int);
    int pop();
    int peek();
    bool isEmpty();
    void display();
    int size();
};

#endif