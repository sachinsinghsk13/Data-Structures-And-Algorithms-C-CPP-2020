#ifndef _DOUBLY_LINKED_LIST_
#define _DOUBLY_LINKED_LIST_

class DoublyNode {
    public:
        int data;
        DoublyNode *next, *prev;
        DoublyNode();
        DoublyNode(int data);
        ~DoublyNode();
};

class DoublyLinkedList {
    private:
        DoublyNode *head, *tail;
        int size;
    public:
        DoublyLinkedList();
        ~DoublyLinkedList();
        bool isEmpty();
        void insert(int position, int data);
        int remove(int position);
        void display();
        int length();
};
#endif