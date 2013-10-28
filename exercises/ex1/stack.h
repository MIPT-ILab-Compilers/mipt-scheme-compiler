/**
 * @file: ex1/stack.h 
 * Definition of Stack class(es) for exercise 1
 * @author Boris Shurygin
 */
/*
 * Stack interface exercise 1
 * Copyright (C) 2009  Boris Shurygin
 */
#pragma once
#include "misc.h"
#include<iostream>
#include<iomanip>

using namespace std;

const int N = 4;

// BORIS: no comments here? Example below (comments in autodoc style):
/**
 * Stack representation template. Stores data in internal array. 
 * The size of internal array must be defined at time of stack construction.
 * Note: Stored objects are copied into internal array so a valid copy constructotr
 *       must be provided for the type 'Type'
 * 
 * @param Type Type of the stored data
 */
template <class Type> class Stack
{
private:
	Type * arr;					 // arbitrary types of data
	int size, top;               //stack size//// top is index of the last element
public:
	Stack();					 // constructor by default
	Stack(int);					 // constructor with parameters
	~Stack();					 // destructor
	void push(Type);			 
	Type pop();
	void toStream( std::ostream& stream) const; // Print stack to given stream

/*	Type getarr_i(int i)
	{
		return arr[i];
	}*/
	
};

// BORIS: operator << should not be member function. Operators declared as member
//        functions are called as a function of its LEFT argument. Here left argument is std::ostream
template <class Type> 
std::ostream&
operator << (std::ostream& stream, const Stack <Type> &ob)
{
	ob.toStream( stream);
	return stream;
}

template <class Type> 
void
Stack<Type>::toStream( std::ostream& stream) const
{
	stream << "Stack contents: ";
	for( int i = top; i >= 0; i--)
		stream << setw(5) << arr[i];
}

template <class Type> Stack<Type>::Stack()		// makes size of stack equal const N defined at the begining of this file
{
	size = N;					//stack is empty when top == -1	
	arr = new Type[size];
	top = -1;
}

template <class Type> Stack<Type>::Stack(int n)
{
	size = n;					// makes size of stack equal n which defines in parameters of new object 
	arr = new Type[size];
	top = -1;
}

template <class Type> Stack<Type>::~Stack()
{
	delete[] arr;					// stupidly free the memory
}



template <class Type> void Stack<Type>::push(Type data)
{
	if ( top == size - 1 )
	{
		cout << "Stack is full" << endl;	// no memory for new elements
		return;
	}
	top++;
	arr[top] = data;
}

template <class Type> Type Stack<Type>::pop()
{
	if ( top == -1 )
	{	
		cout << "Empty stack" << endl;
		return 0;
	}
	top--;
	return arr[top + 1];
}

