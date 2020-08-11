#include <iostream>
using namespace std;
#include "tree/threaded-binary-search-tree.h"

int main()
{
    ThreadedBST bst;
    bst.insert(50);
    bst.insert(40);
    bst.insert(60);
    bst.insert(45);
    bst.insert(55);
    bst.inorder();
    return 0;
}
