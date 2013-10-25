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
	Stack <int> my_stack(3);
	for ( int i = 0; i < 5; i++ )
		my_stack.push(i);
//	cout << my_stack;// << endl;
	for ( int i = 0; i < 5; i++ )
		cout << my_stack.pop() << endl;
	cout << my_stack.pop() << endl;
	my_stack.push(7);
	int a = my_stack.pop();
	Stack <char*> str;
	str.push("Vadim\n");
	str.push("name is ");
	str.push("Hi, my ");
	char * s;
//	cout << str << endl;
	while ( ( s = str.pop() ) != 0 )
		cout << s;	
	
	cout << a << endl;
}
