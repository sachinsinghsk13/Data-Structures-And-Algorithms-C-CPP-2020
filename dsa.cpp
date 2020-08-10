#include <iostream>
#include "tree/binary-search-tree.h"
using namespace std;
#include <queue>
int main()
{
   BinarySearchTree bst;
   bst.insert(50);
   bst.insert(40);
   bst.insert(60);
   bst.insert(30);
   bst.insert(45);
   bst.insert(55);
   bst.insert(70);
   bst.insert(24);
   bst.insert(33);
   bst.insert(48);
   bst.insert(65);
   bst.inorder();
   bst.remove(50);
   bst.inorder();
   return 0;
}
