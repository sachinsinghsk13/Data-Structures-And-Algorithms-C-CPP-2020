#include <iostream>
using namespace std;
#define MAX 10
pair<int, int> table[MAX];
int size = 0;
int generate_hash_code(int key, int count) {
	return (key + count) % MAX;
}

void put(int key, int value) {
	if (size < MAX) {
		int hash_index, count = 0;
		do
		{
			hash_index = generate_hash_code(key, count);
			count = count + 1;
		} while (table[hash_index].first != -1);
		
		table[hash_index] = make_pair(key, value);
		size++;
	}
	else
	{
		cout << "Hash table is full." << endl;
	}	
}

int get(int key) {
	if (size > 0) {
		int hash_index , count = 0;
		bool found = false;
		do
		{
			hash_index = generate_hash_code(key, count);
			if (table[hash_index].first == key)
			{
				found = true;
				break;
			}
			count = count + 1;
			if (count >= MAX - 1) break;
		} while (table[hash_index].first != -1);

		if (found)
			return table[hash_index].second;
		else	
			cout << "Key not found" << endl;		
		return -1;
	}
}

void remove(int key) {
	if (size > 0) {
		int hash_index , count = 0;
		bool found = false;
		do
		{
			hash_index = generate_hash_code(key, count);
			if (table[hash_index].first == key)
			{
				found = true;
				break;
			}
			count = count + 1;
			if (count >= MAX - 1) break;
		} while (table[hash_index].first != -1);

		if (found)
			table[hash_index] = make_pair(-1, 0);
		else	
			cout << "Key not found" << endl;
	}
}

int main(int argc, char *argv[]) {
	for (int i = 0; i < MAX; i++)
		table[i].first = -1;
	put(12, 22);
	put(22, 22);
	remove(22);

	cout << get(3245) << endl;
	return 0;
}