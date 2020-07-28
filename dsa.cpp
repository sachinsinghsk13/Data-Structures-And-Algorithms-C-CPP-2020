#include <iostream>
#include "stacks/linkedstack.h"
using namespace std;

int main()
{
   LinkedStack stack;
   stack.display();
   stack.push(290);
   stack.display();
   stack.push(10);
   stack.push(20);
   stack.push(30);
   stack.display();
   while (!stack.isEmpty())
      cout << stack.pop() << " ";
   cout << endl;
   return 0;
}