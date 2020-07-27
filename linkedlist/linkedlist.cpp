#include "linkedlist.h"
#include <iostream>

LinkedList::LinkedList() {
	head = nullptr;
	size = 0;
}

LinkedList::~LinkedList() {}
// Time :  O(n), Space O(1): 
void LinkedList::insertAtLast(int item) {
	if (head == nullptr) {
		head = new Node(item);
		return;
	}
	Node* temp = head;
	while (temp->next != nullptr) {
		temp = temp->next;
	}
	temp->next = new Node(item);

}
// Time :  O(n), Space O(1): 
void LinkedList::insert(int position, int item) {
	if (head == nullptr) {
		head = new Node(item);
		size++;
		return;
	}
	if (position == 1) {
		Node* node = new Node(item);
		node->next = head;
		head = node;
		size++;
	}
	else {
		int i = 1;
		Node* temp = head;
		bool flag = false;
		while (i != position - 1) {
			temp = temp->next;
			if (temp == nullptr) {
				flag = true;
				break;
			}
			i++;
		}
		if (!flag) {
			Node* node = new Node(item);
			node->next = temp->next;
			temp->next = node;
			size++;
		}
		else {
			std::cout << "Position Not Valid !" << std::endl;
		}
	}
}

int LinkedList::length() {
	return this->size;
}

void LinkedList::display() {
	Node* temp = head;
	if (temp == nullptr) {
		std::cout << "List is Empty " << std::endl;
	}
	else {
		while (temp != nullptr) {
			std::cout << temp->item << " ";
			temp = temp->next;
			temp->item;
		}
		std::cout << std::endl;
	}
}

bool LinkedList::isEmpty() {
	return head == nullptr;
}
// Time O(n), Sapce O(1)
int LinkedList::remove(int position) {
	if (head != nullptr) {
		if (position == 1) {
			Node* nodeToBeDeleted = head;
			head = head->next;
			int value = nodeToBeDeleted->item;
			delete nodeToBeDeleted; // free memory
			return value;
		}
		else {
			int count = 1;
			Node *current = head, *prev = head;
			bool flag = false;
			while (count < position) {
				prev = current;
				current = current->next;
				if (current == nullptr) {
					flag = true;
					break;
				}
				count++;
			}
			if (!flag) {
				prev->next = current->next;
				int value = current->item;
				delete current; // free memory
				return value;
			}
			else
				std::cout << "Position not valid." << std::endl;
		}
	}
	return -1;
}

int LinkedList::get(int position) {
	if (head != nullptr) {
		int count = 1;
		Node* temp = head;
		bool flag = false;
		while (count < position) {
			temp = temp->next;
			if (temp == nullptr) {
				flag = true;
				break;
			}
			count++;
		}

		if (!flag)
			return temp->item;
		else
			std::cout << "Position Not Valid " << std::endl;
	}
	return -1;
}

void LinkedList::displayRecursivly() {
	displayRecursivly(head);
	std::cout << std::endl;
}

void LinkedList::displayRecursivly(Node* head) {
	if (head != nullptr) {
		std::cout << head->item << " ";
		displayRecursivly(head->next);
	}
}

void LinkedList::displayReverse() {
	displayReverse(head);
	std::cout << std::endl;
}

void LinkedList::displayReverse(Node* head) {
	if (head != nullptr) {
		displayRecursivly(head->next);
		std::cout << head->item << " ";
	}
}