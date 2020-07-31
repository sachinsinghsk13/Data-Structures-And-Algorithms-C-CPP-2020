#include <iostream>
using namespace std;
#include "linkedlist/polynomial.h"
int main()
{
   Polynomial p;
   p.create();
   p.display();
   Polynomial q;
   q.create();
   q.display();
   Polynomial r = p.multiply(q);
   r.display();   
   return 0;
}