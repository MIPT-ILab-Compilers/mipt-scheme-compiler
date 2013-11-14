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

template <class T> Dlist<T>* Dlist<T>::add( T value, Dlist<T> *current_elem)   //Added object after "*current_elem" with data          
{                                                                              // data with the value "value"
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

template <class T> Dlist<T>* Dlist<T>::add( Dlist<T> *ins_elem) 
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

template <class T> DlistIter<T> Dlist<T>::myIter()
{   
	DlistIter<T> *iter = new DlistIter<T>;
	iter->current = this;
	return *iter;
}

template <class T> DlistIter<T> DlistIter<T>::operator++ ()             //++it
{   
	this->current = (this->current)->next;
	return *this;
}
	
template <class T> DlistIter<T> DlistIter<T>::operator++ ( int)         //it++
{   
	DlistIter temp = *this;
	++(*this);
	return temp;
}	

template <class T> DlistIter<T> DlistIter<T>::operator-- ()             //--it
{   
	this->current = (this->current)->prev;
	return *this;
}

template <class T> DlistIter<T> DlistIter<T>::operator-- ( int)         //it--
{   
	DlistIter  temp = *this;
	--(*this);
	return temp;
}	
    
template <class T> T DlistIter<T> ::operator*()
{
	return (this->current)->data;
}

template <class T> void DlistIter<T>::operator= ( DlistIter<T> iter) 
{   
	if ( this == &iter)
	    return;
	this->current = new Dlist<T>;   
	this->current = iter.current;
}	

template <class T> bool DlistIter<T>::operator== ( DlistIter<T> iter)
{
	return ( this->current == iter.current);
}
	
void testList()
{   
	DlistIter<int> iter1, iter2;
	Dlist<int> dlist1(5),dlist(7);
	iter1 = dlist1.myIter();
	dlist1.add( 1 , &dlist1);      // 5 1 7 5 7 5
	dlist1.add(&dlist);
	iter2 = iter1;
	if ( iter1 == iter2 ) 
	    cout << "iter 1 is equal to iter 2" << endl;
	else
	    cout << "iter 1 is not equal to iter 2" << endl; 
	iter1++;
	if ( iter1 == iter2 ) 
	    cout << "iter 1 is equal to iter 2" << endl;
	else
	    cout << "iter 1 is not equal to iter 2" << endl;
	iter1 = iter2++;    
	cout << "iter 1 is " << *iter1 << endl;
    cout << "iter 2 is " << *iter2 << endl;
    ++iter2;
    cout << "iter 2 is "<< *iter2 << endl;
}    
