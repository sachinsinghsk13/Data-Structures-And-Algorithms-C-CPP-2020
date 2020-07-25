#include "node.h"

Node::Node() {
	this->item = 0;
	this->next = nullptr;
}
Node::Node(int item) {
	this->item = item;
	this->next = nullptr;
}
Node::~Node() {}
