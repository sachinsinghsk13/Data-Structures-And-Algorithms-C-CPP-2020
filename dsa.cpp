#include <iostream>
#include "hashing/hash-table-chaining.h"
using namespace std;

int main()
{
	HashTable hash(10);
	hash.put(34, 2000);
	hash.put(56, 100);
	hash.put(67, 234);
	hash.put(167, 1500);
	cout << hash.get(67) << endl;
	return 0;
}