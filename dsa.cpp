#include <iostream>
#include <fstream>
using namespace std;

class record {
	public:
		string name;
};

int main() {
	record a, b, c;
	c.name = "sachin singh";
	a.name = "akanksha sharma";
	b.name = "shivam sharma";

	fstream f;
	f.open("student.dat");
	// f.write((char*) &a, sizeof(a));
	// f.write((char*) &b, sizeof(b));
	// f.write((char*) &c, sizeof(c));
	f.close();
	return 0;
}