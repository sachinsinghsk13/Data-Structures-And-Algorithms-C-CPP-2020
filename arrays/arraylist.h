#ifndef __ARRAY_LIST__
#define __ARRAY_LIST__

class ArrayList
{
private:
    const int MAX;
    int size;
    int *storage;

public:
    ArrayList();
    ArrayList(int capacity);
    ~ArrayList();
    void display();
    bool isFull();
    bool isEmpty();
    void insert(int, int);
    void insert(int);
    int remove();
    int remove(int);
};
#endif