#include <iostream>
#include "tree/binary-search-tree.h"
using namespace std;

int main()
{
   BinarySearchTree bst;
   bst.insert(100);
   bst.insert(50);
   bst.insert(200);
   bst.insert(300);
   bst.insert(20);
   bst.insert(150);
   bst.insert(70);
   bst.insert(180);
   bst.insert(120);
   bst.insert(30);
   bst.insert(2003);
   bst.insert(12321);
   bst.inorder();
   cout << endl;
   bst.postorder();
   cout << endl;
   bst.preorder();
   cout << endl;
   return 0;
}
