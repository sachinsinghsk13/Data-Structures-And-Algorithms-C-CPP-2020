#include <iostream>
#include "tree/red-black-tree.h"
using namespace std;

int main()
{
    RBTree t;
    t.insert(10);
    t.insert(20);
    t.insert(30);
    t.insert(15);
    t.inorder();
    return 0;
}
