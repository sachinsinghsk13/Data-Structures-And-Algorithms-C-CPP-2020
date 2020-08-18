#include <iostream>
#include "heaps/binary-max-heap.h"
using namespace std;

int main()
{
	MaxHeap heap(5);
	for (int i = 0; i < 100; i++) {
		heap.insert(i);
	}
	while (!heap.isEmpty()) {
		heap.traverse();
		heap.pop();
	}
	return 0;
}
