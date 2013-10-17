/**
 * @file: ex1/list.h 
 * Definition of List class(es) for exercise 1
 * @author Boris Shurygin
 */
/*
 * List interface exercise 1
 * Copyright (C) 2009  Boris Shurygin
 */
#pragma once
#include "misc.h"


/** Unit testing of list */
void testList();

class Elem
{
public:
    int num;
	Elem *prev;
	Elem *next;

};

class Dlist 
{
	public:
	Elem *last;
	Elem *start;
	Dlist();
    void add(int a);
    void del(int b);
    Elem*find(int);	
    void print(int);
};
void testList();


