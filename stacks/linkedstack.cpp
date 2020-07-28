#include "linkedstack.h"
#include <iostream>
using namespace std;

StackNode::StackNode()
{
    data = 0;
    next = nullptr;
}

StackNode::~StackNode()
{
}

LinkedStack::LinkedStack()
{
    top = nullptr;
    stackSize = 0;
}

LinkedStack::~LinkedStack()
{
}

bool LinkedStack::isEmpty()
{
    return top == nullptr;
}

void LinkedStack::push(int data)
{
    StackNode *node = new StackNode();
    node->data = data;
    node->next = top;
    top = node;
    stackSize++;
}

int LinkedStack::pop()
{
    if (!isEmpty())
    {
        StackNode *temp = top;
        int data = temp->data;
        top = top->next;
        delete temp;
        stackSize--;
        return data;
    }
    cout << "Stack is Empty" << endl;
    return -1;
}

int LinkedStack::peek()
{
    if (!isEmpty())
    {
        return top->data;
    }
    cout << "Stack is Empty" << endl;
    return -1;
}

int LinkedStack::size()
{
    return stackSize;
}

void LinkedStack::display()
{
    if (!isEmpty())
    {
        StackNode *temp = top;
        cout << "top --> ";
        while (temp != nullptr)
        {
            cout << temp->data << " ";
            temp = temp->next;
        }

        cout << endl;
    }
    else
        cout << "Stack is empty" << endl;
}