/**
 * @file: ex1/list.cpp 
 * Implementation of List class(es) for exercise 1
 * @author Boris Shurygin
 */
#include "list.h"
#include <iostream>



Elem* Dlist::add( int num, Elem *current_elem)            
{                                                         
	    Elem *ins_elem = new Elem;                     
	    if ( current_elem == NULL )                       
	    {   
		    ins_elem->prev = ins_elem;
		    ins_elem->next = ins_elem;
		    ins_elem->num = num;
	        cout << "Added" << endl;
	        return ins_elem;                         
	    }else                                              
	    {   
			(current_elem->next)->prev = ins_elem;
			ins_elem->next = current_elem->next;
			current_elem->next = ins_elem;
			ins_elem->prev = current_elem;
			ins_elem->num = num;
			cout << "Added" << endl;
			return ins_elem;
	    }
}
    
 
 
void Dlist::print( Elem *current_elem)
{   
	Elem *temp;
	temp = current_elem; 
    if ( current_elem == NULL)
    {
	    cout << "empty list" << endl;
	    return;
	} else 
    {
	    do{   	
     	cout << temp->num << endl;	        
		temp = temp->next;
        }
        while ( temp != current_elem ); 
    }  
    return;
}	
   	
 
Elem* Dlist::del( Elem *current_elem)
{   
	if ( current_elem == NULL )
	    cout << "Incorrect data" << endl;  
	else
	{
		Elem *temp;
        (current_elem->prev)->next = current_elem->next;
        (current_elem->next)->prev = current_elem->prev;
        temp = current_elem->prev;
        delete current_elem;	
        cout << "deleted" << endl;
        return temp;
    }      
}
      
Elem* Dlist::find( int num, Elem *current_elem)
{
	 Elem *temp;
	 temp = current_elem;
     do 
     {
		 if ( temp->num == num)
		{ 
			cout << "founded" << endl;
            return temp;
        } else 
            temp = temp->next;   
	}
    while ( temp != current_elem );
    cout << "not found" << endl;
	return current_elem;	 
}
   
void testList()
{
	Dlist l;
    Elem *current_elem ;
	current_elem = l.add( 2 , NULL);
	l.add( 3 , current_elem);
	l.add( 1 , current_elem);
    l.add( 5 , current_elem);
	l.print(current_elem);
	current_elem = l.del(l.find( 3 , current_elem));
	l.find( 11 , current_elem);
	l.print(current_elem);
}



