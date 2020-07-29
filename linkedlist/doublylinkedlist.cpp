#include <iostream>
#include "doublylinkedlist.h"

DoublyNode::DoublyNode()
{
    data = 0;
    next = prev = nullptr;
}

DoublyNode::DoublyNode(int data)
{
    this->data = data;
    next = prev = nullptr;
}

DoublyNode::~DoublyNode()
{
}

DoublyLinkedList::DoublyLinkedList()
{
    head = tail = nullptr;
}

DoublyLinkedList::~DoublyLinkedList()
{
}

DoublyNode *DoublyLinkedList::getNode()
{
    int data;
    std::cout << "Enter Data : ";
    std::cin >> data;
    DoublyNode *node = new DoublyNode(data);
    return node;
}

void DoublyLinkedList::append(DoublyNode *node)
{
    if (head == nullptr)
    {
        head = tail = node;
    }
    else
    {
        tail->next = node;
        node->prev = tail;
        tail = node;
    }
}

void DoublyLinkedList::create()
{
    char ch;
    while (true)
    {
        std::cout << "Any more node to be added (y/n)  : ";
        std::cin >> ch;
        if (ch == 'n')
            break;
        DoublyNode *node = getNode();
        append(node);
    }
}

void DoublyLinkedList::traverse()
{
    DoublyNode *link = head;
    while (link != nullptr)
    {
        std::cout << link->data << " ";
        link = link->next;
    }
    std::cout << std::endl;
}

void DoublyLinkedList::deleteNode(int val)
{
    DoublyNode *current, *temp;
    current = head;
    while (current != nullptr)
    {
        if (current->data == val)
            break;
        current = current->next;
    }

    if (current != nullptr)
    {
        if (current == head)
        {
            head->prev = nullptr;
            head = head->next;
            delete current;
        }

        else if (current == tail)
        {
            tail = current->prev;
            (current->prev)->next = nullptr;
            delete current;
        }

        else
        {
            (current->prev)->next = current->next;
            (current->next)->prev = current->prev;
            delete current;
        }

        if (head == nullptr)
            tail = nullptr;
    }
    else
    {
        std::cout << "Node with value " << val << " is not found." << std::endl;
    }
}

void DoublyLinkedList::deleteByPosition(int pos)
{
}