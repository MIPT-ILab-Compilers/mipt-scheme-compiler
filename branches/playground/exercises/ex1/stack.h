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


using namespace std;

//void testStack();

typedef struct my1_stack
{
	int value;
	struct my1_stack * previous;
} stack;


class Stack
{
public:
	Stack()
	{
		last = NULL;
		number_of_elements = 0;
	}
	//~Stack();    
	void push (int);
	int pop ();
private:
	stack * last;
	int number_of_elements;
};


void Stack::push (int a)
{
	stack * temp = new stack;
	temp->previous = last;
	temp->value = a;
	last = temp;
	number_of_elements++;
}

int Stack::pop ()
{
	if (last == NULL)
	{
		cout << "Empty stack" << endl;
		return -1;
	}
	int a = last->value;
	stack * temp = last->previous;
	delete last;
	last = temp;
	number_of_elements--;
	return a;
}
