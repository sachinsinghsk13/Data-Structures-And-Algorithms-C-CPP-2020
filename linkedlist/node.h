#ifndef NODE_H_
#define NODE_H_

class Node {
public:
	int item;
	Node* next;
	Node();
	Node(int item);
	virtual ~Node();
};

#endif