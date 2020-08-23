#include <iostream>
#include "tree/splay-tree.h"
using namespace std;

int main()
{
	splay_tree t;
	t.insert(24, 10);
	t.insert(13, 11);
	t.insert(17, 12);
	t.insert(25, 13);
	t.insert(34, 14);
	t.insert(22, 15);

	t.insert(20, 16);

	t.insert(14, 17);
	t.insert(29, 18);

	cout << t.get_top() << endl; // 29
	cout << t.search(25) << endl;
	cout << t.get_top() << endl;
	return 0;
}