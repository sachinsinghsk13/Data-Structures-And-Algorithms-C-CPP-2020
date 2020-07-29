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
    size = 0;
}

DoublyLinkedList::~DoublyLinkedList()
{
    // release memeory
    DoublyNode *temp;
    while (head != nullptr)
    {
        temp = head;
        head = head->next;
        delete temp;
    }
}

void DoublyLinkedList::insert(int position, int data)
{
    if (position > 0 && position <= size + 1)
    {
        DoublyNode *node = new DoublyNode(data);
        if (head != nullptr)
        {
            if (position == 1) // add at begining
            {
                head->prev = node;
                node->next = head;
                head = node;
            }
            else
            {
                int count = 1;
                bool flag = false;
                DoublyNode *temp = head;
                while (count != position - 1)
                {
                    temp = temp->next;
                    count++;
                }
                if (temp != tail)
                {
                    (temp->next)->prev = node;
                    node->next = temp->next;
                    node->prev = temp;
                    temp->next = node;
                }
                else
                { // add at end
                    node->prev = tail;
                    tail->next = node;
                    tail = node;
                }
            }
        }
        else // add first node
        {
            head = tail = node;
        }
        size++;
    }
    else
    {
        std::cout << "Position not valid " << std::endl;
    }
}

int DoublyLinkedList::remove(int position)
{
    if (position > 0 && position <= size)
    {
        DoublyNode *current = head;

        if (position == 1)
        {
            if (head == tail)
            {
                head = tail = nullptr;
            }
            else
            {
                (head->next)->prev = nullptr;
                head = head->next;
            }
        }
        else
        {

            int count = 1;
            while (count != position)
            {
                current = current->next;
                count++;
            }
            if (current == tail)
            {
                (tail->prev)->next = nullptr;
                tail = tail->prev;
            }
            else
            {
                (current->next)->prev = current->prev;
                (current->prev)->next = current->next;
            }
        }
        int data = current->data;
        delete current;
        size--;
        return data;
    }
    else
    {
        std::cout << "Invalid position." << std::endl;
        return -1;
    }
}

bool DoublyLinkedList::isEmpty()
{
    return head == nullptr;
}

int DoublyLinkedList::length()
{
    return size;
}

void DoublyLinkedList::display()
{
    if (!isEmpty())
    {
        DoublyNode *temp = head;
        while (temp != nullptr)
        {
            std::cout << temp->data << " ";
            temp = temp->next;
        }
        std::cout << std::endl;
    }
    else
    {
        std::cout << "List is Empty" << std::endl;
    }
}