#include "node.h"
#ifndef _CIRCULAR_LINKED_LIST_
#define _CIRCULAR_LINKED_LIST_

class CircularLinkedList
{
private:
    Node *tail;

public:
    CircularLinkedList();
    ~CircularLinkedList();
    void insert(int, int);
    int get(int);
    int remove(int);
    void insertAtLast(int);
    void display();
    void displayRecursivly();
    void displayReverse();
    int length();
    bool isEmpty();
};

#endif