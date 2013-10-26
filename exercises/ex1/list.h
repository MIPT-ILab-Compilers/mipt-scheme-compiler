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
	Elem* add( int num, Elem *current_elem);
    Elem* del( Elem *del_elem);
    Elem* find( int num, Elem *current_elem);	
    void print( Elem *current_elem);
};
