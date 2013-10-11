/**
 * @file: ex1/stack.cpp 
 * Implementation of Stack class(es) for exercise 1
 * @author Boris Shurygin
 */
#include "stack.h"

/**
 * Unit testing of Stack
 */
void testStack()
{
	Stack my_stack;
	for ( int i = 0; i < 5; i++ )
		my_stack.push(i);
	for ( int i = 0; i < 5; i++ )
		cout << my_stack.pop() << endl;
	cout << my_stack.pop() << endl;
	my_stack.push(7);
	int a = my_stack.pop();
	cout << a << endl;
}
