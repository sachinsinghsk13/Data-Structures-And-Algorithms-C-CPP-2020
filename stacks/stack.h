#ifndef __STACK_H__
#define __STACK_H__

class Stack {
    private:
        const int MAX;
        int top;
        int *storage;
    public:
        Stack();
        Stack(int capacity);
        ~Stack();
        void push(int);
        int pop();
        int peek();
        bool isFull();
        bool isEmpty();
        void display();
        int size();
};

#endif