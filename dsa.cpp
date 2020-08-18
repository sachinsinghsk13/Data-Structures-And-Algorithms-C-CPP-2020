#include <iostream>
#include "arrays/matrix.h"
using namespace std;

int main()
{
	Matrix a(3, 3);
	a.read_matrix();
	a.print_matrix();
	a.transpose_matrix()->print_matrix();
	return 0;
}
