#include "doublynode.h"

DoublyNode::DoublyNode() {
    data = 0;
    next = prev = nullptr;
}

DoublyNode::DoublyNode(int data) {
    this->data = data;
    next = prev = nullptr;
}

DoublyNode::~DoublyNode() {
    
}