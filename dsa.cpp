#include <iostream>
using namespace std;
#include "linkedlist/linkedlist.h"

int main() {
    LinkedList list;
    list.insertAtLast(10);
    list.insertAtLast(20);
    list.insertAtLast(30);
    list.displayReverse();
    return 0;
}