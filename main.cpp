#include <iostream>
#include <tree/binary-search-tree.h>
int main() {
	BinarySearchTree bst;
	bst.insert(20);
	bst.bfs();
	return 0;
}