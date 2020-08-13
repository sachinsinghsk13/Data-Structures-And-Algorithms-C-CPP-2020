#include <iostream>
#include "tree/avl-tree.h"

using namespace std;

int main()
{
    AVLTree t;
    t.insert(45);
    t.insert(36);
    t.insert(63);
    t.insert(27);
    t.insert(39);
    t.insert(72);
    t.insert(37);
    t.insert(41);
    t.remove(72);
    return 0;
}
