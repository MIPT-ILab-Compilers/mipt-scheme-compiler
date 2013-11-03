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


    
template <class T> Dlist<T>* Dlist<T>::add( Dlist<T> *ins_elem , Dlist<T> *current_elem) //Added "ins_elem" after "*current_elem"
{
	if ( current_elem == NULL )                       
	{   
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



void testList()
{
	Dlist<int> dlist1(5),dlist2(7);
    Dlist<int> *current_elem;
	current_elem = dlist1.add( 1 , &dlist1);
    dlist1.print(&dlist1);
    delete current_elem;
	current_elem = dlist1.add( &dlist2 , &dlist1);
    dlist1.add( 3 , current_elem);
    dlist1.print(&dlist1);
    Dlist<double> Dlist_d1(3.14);
    Dlist<double>  *Dlist_d2;
    Dlist_d2 = &Dlist_d1;
    Dlist_d2->add(2.73, Dlist_d2);
    Dlist_d2->add(1.38, Dlist_d2);
    Dlist_d2->print(Dlist_d2);
    
   
}    
