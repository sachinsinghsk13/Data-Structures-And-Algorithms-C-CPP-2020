#include "stack.h"
#include <iostream>
using namespace std;

Stack::Stack() : MAX(10)
{
    top = -1;
    storage = new int[MAX];
}

Stack::Stack(int capacity) : MAX(capacity)
{
    top = -1;
    storage = new int[MAX];
}
Stack::~Stack() {}
bool Stack::isEmpty()
{
    return top == -1;
}

bool Stack::isFull()
{
    return top == MAX - 1;
}

void Stack::push(int data)
{
    if (!isFull())
    {
        top++;
        storage[top] = data;
    }
    else
        cout << "Stack Overflow!" << endl;
}

int Stack::pop()
{
    if (!isEmpty())
    {
        int data = storage[top];
        top--;
        return data;
    }
    else
        cout << "Stack Underflow!" << endl;
    return -1;
}

int Stack::peek()
{
    if (!isEmpty())
    {
        int data = storage[top];
        return data;
    }
    else
        cout << "Stack Underflow!" << endl;
    return -1;
}

void Stack::display()
{
    if (!isEmpty()) {
        for (int i = 0; i <= top; i++)
            cout << storage[i] << " ";
        cout << " <-- top" << endl;
    }   
    else
        cout << "Stack is Empty" << endl;
}

int Stack::size() {
    return top + 1;
}