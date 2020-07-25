#include "node.h"

#ifndef LINKEDLIST_H_
#define LINKEDLIST_H_

class LinkedList {
private:
	Node* head;
	int size;
	void displayRecursivly(Node*);
	void displayReverse(Node*);
public:
	LinkedList();
	virtual ~LinkedList();
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