#ifndef _DOUBLY_LINKED_LIST_
#define _DOUBLY_LINKED_LIST_
#include "doublynode.h"

class DoublyLinkedList {
    private:
        DoublyNode *head, *tail;
        int size;
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
        void create();
        DoublyNode *getNode();
        void append(DoublyNode *node);
        void traverse();
        void deleteNode(int val);
        void deleteByPosition(int pos);
};
#endif