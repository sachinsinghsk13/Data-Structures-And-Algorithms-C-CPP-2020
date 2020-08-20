#include "hash-table-chaining.h"
#include <iostream>
using namespace std;

Node::Node()
{
    key = value = 0;
    next = nullptr;
}

Node::Node(int key, int value)
{
    this->key = key;
    this->value = value;
    next = nullptr;
}

Node::~Node() {}

HashTable::HashTable(int size) : table_size(size)
{
    buckets = new Node *[table_size];
    for (int i = 0; i < table_size; i++)
        buckets[i] = nullptr;
}

void HashTable::put(int key, int value)
{
    int hash_code = hash_function(key);
    if (buckets[hash_code] == nullptr)
    {
        buckets[hash_code] = new Node(key, value);
    }
    else
    {
        Node *ptr = buckets[hash_code];
        while (ptr->next != nullptr)
        {
            ptr = ptr->next;
        }
        ptr->next = new Node(key, value);
    }
}

int HashTable::get(int key)
{
    int hash_code = hash_function(key);
    Node *head = buckets[hash_code];
    if (head != nullptr)
    {
        Node *ptr = head;
        while (ptr != nullptr)
        {
            if (ptr->key == key)
                return ptr->value;
            ptr = ptr->next;
        }
    }
    cout << "key not found " << endl;
}

void HashTable::remove(int key)
{
    int hash_code = hash_function(key);
    if (buckets[hash_code] != nullptr)
    {
        if (buckets[hash_code]->key == key) {
            Node *tmp = buckets[hash_code];
            buckets[hash_code] = buckets[hash_code]->next;
            delete tmp;
        }
        else
        {
            Node *ptr = buckets[hash_code];
            bool flag = false;
            while (ptr->next != nullptr) {
                if (ptr->next->key == key) {
                    flag = true;
                    break;
                }
                ptr = ptr->next;
            }

            if (flag) {
                Node *tmp = ptr->next;
                ptr->next = ptr->next->next;
                delete tmp;
            }
        }
        
    }
}

int HashTable::hash_function(int key)
{
    return key % table_size;
}