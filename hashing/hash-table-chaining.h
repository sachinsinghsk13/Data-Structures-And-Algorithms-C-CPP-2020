#ifndef __HASH_TABLE__
#define __HASH_TABLE__

class Node {
    public:
        Node();
        Node(int key, int value);
        ~Node();
        int key;
        int value;
        Node *next;
};

class HashTable {
    private:
        Node **buckets;
        const int table_size;
        int hash_function(int key);
    public:
        HashTable(int size);
        void put(int key, int value);
        int get(int key);
        void remove(int key);
};

#endif