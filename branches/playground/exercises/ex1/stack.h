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
#include <iostream>
#include <iomanip>
#include <vector>

using namespace std;

/**
 * Stack representation template. Stores data in internal array (vector). 
 * The size of internal array increases automatically as needed.
 * 
 * @param Type Type of the stored data
 */

template <class T> class Iterator;

template <class Type> class Stack
{
private:
	vector<Type> arr;					 // arbitrary types of data
	int top;
public:
	Stack();					 // constructor by default
	~Stack();					 // destructor
	void push( Type);			 
	Type pop();
	void toStream( std::ostream& stream) const; // Print stack to given stream
	int get_top()					// iterator
	{
		return top;
	}
	Type get( int);	
	template <typename T> friend class Iterator;
};



template
<class T>
class Iterator
{
	Stack<T> * ptr;
	int i;
public:
	Iterator( Stack<T> * ob_ptr)
	{
		i = 0;
		ptr = ob_ptr;
	}	
	T operator * ()
	{
		return ptr->get( i);
	}
	void make_i( int a)
	{
		i = a;
	}
	int get_i()
	{
		return i;
	}
	void * get_ptr()
	{
		return ptr;
	}
	void operator ++()
	{
		i++;
	};
	void operator --()
	{
		i--;
	}
	bool operator <= (Iterator& iter)
	{
		if ( i <= iter.get_i() )
			return true;
		return false;
	}
	bool operator ==(Iterator& iter)
	{
		if ( ( i == iter.get_i ) && ( ptr == iter.get_ptr ) )
			return true;
		return false;
	}
	Iterator begin()
	{
		Iterator iter(ptr);
		return iter;
	}
	Iterator end()
	{
		Iterator iter( ptr);
		int top = ptr->get_top();
		iter.make_i( top);
		return iter;
	}
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

template <class Type>
Stack<Type>::Stack()		
{
	top = -1;
}


template <class Type>
Stack<Type>::~Stack()
{
	arr.resize( 0);
}



template <class Type>
void
Stack<Type>::push( Type data)
{
	int size = arr.max_size();
	if ( top + 1 == size )
		arr.resize( size + 1); 
	top++;
	arr.push_back( data);
}

template
<class Type>
Type Stack<Type>::pop()
{
	if ( top == -1 )
	{	
		cout << "Empty stack" << endl;
		return 0;
	}
	Type data = arr[top];
	top--;
	arr.pop_back();
	return data;
}
template
<class Type>
Type Stack<Type>::get( int i)
{
	if ( i <= top )
		return arr[i];
	return 0;
}
