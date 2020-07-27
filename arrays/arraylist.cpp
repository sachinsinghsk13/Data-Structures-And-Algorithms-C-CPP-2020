#include "arraylist.h"
#include <iostream>

ArrayList::ArrayList() : MAX(10)
{
    storage = new int[MAX];
    size = 0;
}

ArrayList::ArrayList(int capacity) : MAX(capacity)
{
    storage = new int[MAX];
    size = 0;
}
ArrayList::~ArrayList() {}

bool ArrayList::isEmpty()
{
    return size == 0;
}

bool ArrayList::isFull()
{
    return size == MAX;
}

void ArrayList::insert(int data)
{
    if (!isFull())
    {
        storage[size] = data;
        size++;
    }
    else
    {
        std::cout << "List is Full." << std::endl;
    }
}

void ArrayList::insert(int position, int data)
{
    if (!isFull())
    {
        if (position >= 0 && position <= size)
        {
            for (int i = size; i > position; i--)
                storage[i] = storage[i - 1];
            storage[position] = data;
            size++;
        }
        else
        {
            std::cout << "Invalid position" << std::endl;
        }
    }
    else
    {
        std::cout << "List is Full." << std::endl;
    }
}

void ArrayList::display()
{
    for (int i = 0; i < size; i++)
    {
        std::cout << storage[i] << " ";
    }
    std::cout << std::endl;
}

int ArrayList::remove()
{
    if (!isEmpty())
    {
        size--;
        storage[size] = 0; // assign default value
    }
    else
    {
        std::cout << "List is Empty" << std::endl;
    }
}

int ArrayList::remove(int position)
{
    if (!isEmpty())
    {
        if (position >= 0 && position < size)
        {
            while (position < size - 1)
            {
                storage[position] = storage[position + 1];
                position++;
            }
            size--;
            storage[size] = 0; // assign default value
        }
        else
        {
            std::cout << "Invalid position" << std::endl;
        }
    }
    else
    {
        std::cout << "List is Empty" << std::endl;
    }
}
