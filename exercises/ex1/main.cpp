/**
 * @file: ex1/main.cpp
 * Test cpp file for the exercise 1
 * @author Boris Shurygin
 */
#include "list.h"
#include "stack.h"

int main( int argc, char** argv)
{
	testList();
	testStack();
	cout << "Exercise 1 test complete in " << BUILD_MODE << " mode!" << endl;
	return 0;
}