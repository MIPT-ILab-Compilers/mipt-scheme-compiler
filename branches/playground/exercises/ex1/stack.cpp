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
	Stack <int> my_stack;
	for ( int i = 0; i < 5; i++ )
		my_stack.push( i);
	cout << my_stack << endl;
	for ( int i = 0; i < 4; i++ )
	{	
		int x = my_stack.pop();
		cout << x << ' ' << 4 - i << ' ' << i << endl;
		ASSERT ( 4 - i == x );
	}
	cout << my_stack.pop() << endl;
	my_stack.push(7);
	cout << my_stack.get(0) << endl;
	int a = my_stack.pop();
	ASSERT( a == 7 );
//	ASSERT( a == 4 );
	Stack <char*> str;
	str.push((char *)"Vadim\n");
	str.push((char *)"name is ");
	str.push((char *)"Hi, my ");
	char * s;
	cout << str.get(1) << endl;
	cout << str << endl;
	while ( ( s = str.pop() ) != 0 )
		cout << s;	
	
	cout << a << endl;

}
