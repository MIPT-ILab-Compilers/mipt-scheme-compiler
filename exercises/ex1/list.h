/**
 * @file: ex1/list.cpp 
 * Implementation of List class(es) for exercise 1
 * @author Boris Shurygin
 */
//#define MY_LOGS //This define turns logging mechanism on/off

#include <iostream>
#include <stdio.h>


using namespace std;
void testList();

template <class T>  class DlistIter;

template <class T > 
class Dlist 
{
	Dlist<T> *prev;
    Dlist<T> *next;
    T data;
public:
    friend class DlistIter<T>;
    DlistIter<T> myIter();                                        
    Dlist<T>* add( T value, Dlist<T> *current_elem);
    Dlist<T>* add( Dlist<T> *ins_elem);
    Dlist<T>* del( Dlist<T> *del_elem);
    Dlist<T>* find( T value, Dlist<T> *current_elem);	
    void print( Dlist<T> *current_elem);
    ~Dlist();
    Dlist();
    Dlist( T value);
    Dlist( T value, Dlist<T> *current_elem);
    
};

template <class T> 
class DlistIter
{
	Dlist<T> *current;
public:
    friend Dlist<T>;
    DlistIter<T> operator++ ();                                         //++it
	DlistIter<T> operator++ ( int);                                     //it++
    DlistIter<T> operator-- ();                                         //--it
    DlistIter<T> operator-- ( int);                                     //it--
    T operator*();
    void operator= ( DlistIter<T> iter); 
	bool operator== ( DlistIter<T> iter);
};
