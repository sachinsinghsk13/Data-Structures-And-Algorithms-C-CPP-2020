#ifndef _DOUBLY_NODE_
#define _DOUBLY_NODE_

class DoublyNode {
    public:
        int data;
        DoublyNode *next, *prev;
        DoublyNode();
        DoublyNode(int data);
        ~DoublyNode();
};

#endif