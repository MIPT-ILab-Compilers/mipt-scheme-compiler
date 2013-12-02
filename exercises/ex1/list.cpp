/**
 * @file: ex1/list.cpp 
 * Implementation of List class(es) for exercise 1
 * @author Boris Shurygin
 */
#include "list.h"
#include <iostream>

#ifdef MY_LOGS
#  define LOG(S) (S)
#else
#  define LOG(S)
#endif



template <class T> Dlist<T>::Dlist()
{
	next = this;
	prev = this;
}

template <class T> Dlist<T>::Dlist( T value)
{
	data = value;
	next = this;
	prev = this;
}

template <class T> Dlist<T>::Dlist( T value, Dlist<T>* current_elem)   
{   
	next = current_elem->next;
	prev = current_elem;
	(current_elem->next)->prev = this;
	current_elem->next = this;
	this->data = value;
}	

template <class T> Dlist<T>::~Dlist()
{
	next->prev = prev;
	prev->next = next;
}	

template <class T> 
Dlist<T>* Dlist<T>::add( T value, Dlist<T> *current_elem)               //Added object after "*current_elem" with data          
{                                                                       // data with the value "value"
	    Dlist<T> *ins_elem = new Dlist<T>;                     
	    if ( current_elem == NULL )                       
	    {   
		    ins_elem->data = value;
		    ins_elem->prev = ins_elem;
		    ins_elem->next = ins_elem;
	        LOG(cout << "Added" << endl);
	        return ins_elem;                         
	    }else                                              
	    {   
			(current_elem->next)->prev = ins_elem;
			ins_elem->next = current_elem->next;
			current_elem->next = ins_elem;
			ins_elem->prev = current_elem;
			ins_elem->data = value;
			LOG(cout << "Added" << endl);
			return ins_elem;
	    }
}

template <class T> 
Dlist<T>* Dlist<T>::add( Dlist<T> *ins_elem) 
{
	if ( this == NULL )                       
	{   
		ins_elem->prev = ins_elem;
		ins_elem->next = ins_elem;
    	LOG(cout << "Added" << endl);
    	return ins_elem;
	}else 
	{
		(this->next)->prev = ins_elem;
		ins_elem->next = this->next;
		this->next = ins_elem;
		ins_elem->prev = this;
		LOG(cout << "Added" << endl);
		return ins_elem;
	}
}		

template <class T> 
Dlist<T>* Dlist<T>::add( T value) 
{
	Dlist<T> *ins_elem = new Dlist<T>;
	if ( this == NULL )                       
	{   
		ins_elem->data = value;
		ins_elem->prev = ins_elem;
		ins_elem->next = ins_elem;
    	LOG(cout << "Added" << endl);
    	return ins_elem;
	}else 
	{
		(this->next)->prev = ins_elem;
		ins_elem->next = this->next;
		this->next = ins_elem;
		ins_elem->prev = this;
		ins_elem->data = value;
		LOG(cout << "Added" << endl);
		return ins_elem;
	}
}
				     
template <class T> void Dlist<T>::print( Dlist<T> *current_elem)
{   
	Dlist<T> *temp;
	temp = current_elem; 
    if ( current_elem == NULL)
    {
	    LOG(cout << "empty list" << endl);
	    return;
	} else 
    {
	    do{   	
     	cout << temp->data << endl;	        
		temp = temp->next;
        }
        while ( temp != current_elem ); 
    }  
    return;
}

template <class T> typename Dlist<T>::Iterator Dlist<T>::begin()
{
	Iterator iter;
	iter.current = this;
	iter.first = true;
	return iter;
}

template <class T> typename Dlist<T>::Iterator Dlist<T>::end()
{
	Iterator iter;
	iter.current = this;
	iter.first = false;
	return iter;
}
	
	

template <class T> Dlist<T>* Dlist<T>::find( T value, Dlist<T> *current_elem)
{
	 Dlist<T> *temp;
	 temp = current_elem;
     do 
     {
		 if ( temp->data == value)
		{ 
			LOG(cout << "founded" << endl);
            return temp;
        } else 
            temp = temp->next;   
	}
    while ( temp != current_elem );
    LOG(cout << "not found" << endl);
	return current_elem;	 
}

template <class T> 
typename Dlist<T>::Iterator Dlist<T>::Iterator::operator++ ()           //++it
{   
	this->current = (this->current)->next;
	if ( this->first ) 
	    this->first = false; 
	return *this;
}
	
template <class T> 
typename Dlist<T>::Iterator Dlist<T>::Iterator::operator++ ( int)       //it++
{   
	Dlist<T>::Iterator temp = *this;
	++(*this);
	return temp;
}	

template <class T> 
typename Dlist<T>::Iterator Dlist<T>::Iterator::operator-- ()           //--it
{   
	this->current = (this->current)->prev;
	if ( this->first ) 
	    this->first = false;
	return *this;
}

template <class T> 
typename Dlist<T>::Iterator Dlist<T>::Iterator::operator-- ( int)       //it--
{   
	Dlist<T>::Iterator temp = *this;
	--(*this);
	return temp;
}	
    
template <class T> 
T Dlist<T>::Iterator::operator* ()
{
	return (this->current)->data;
}

template <class T> 
bool Dlist<T>::Iterator::operator== ( Iterator iter)
{
	return ( (this->current == iter.current) && (this->first == iter.first));
}

template <class T> 
bool Dlist<T>::Iterator::operator!= ( Iterator iter)
{
	return ( !((this->current == iter.current) && (this->first == iter.first)));
}

template <class T> 
bool Dlist<T>::Iterator::operator== ( Dlist<T> elem)
{
	return ( this->current == elem);
}

template <class T> 
void Dlist<T>::Iterator::operator= ( Iterator iter) 
{   
	if ( this == &iter)
	    return;
	this->current = new Dlist<T>;   
	this->current = iter.current;
	this->first = iter.first;
}
	
template <class T> 
void Dlist<T>::Iterator::operator= ( Dlist<T> elem)
{   
	if ( this->current == &elem)
	    return;
	this->current = new Dlist<T>;   
	this->current = &elem;
}	

void testList()
{   
	int i;
	Dlist<int>::Iterator iter1, iter2;
	Dlist<int> dlist1(1);
	for ( i = 2; i <= 5; i++)
	    dlist1.add(i);
	for ( iter1 = dlist1.begin(), iter2 = dlist1.end(); iter1 != iter2; --iter1)
	    cout << *iter1 << endl;
}    
