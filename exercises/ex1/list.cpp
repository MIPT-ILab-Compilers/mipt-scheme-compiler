/**
 * @file: ex1/list.cpp 
 * Implementation of List class(es) for exercise 1
 * @author Boris Shurygin
 */
#include "list.h"
#include <iostream>
 void Dlist::add(int a)
{
	 Elem *temp = new Elem;
	 temp->num = a;
	 temp->next = start;
	 if (start == NULL){
		 temp->prev = temp;
		 temp->next = temp;
	     start = temp;
	     last = start;
	     
		  
	}
	 else
	 {   temp->prev = last;	
		 last->next = temp;
		 temp->next = start;
		 last = temp;
		 start->prev = last;
	 }
 }
 Dlist::Dlist()
{
	last = NULL;
	start = NULL;
} 
 void Dlist::print (int a)
 {   Elem *temp;
	 temp = last ;
	 int b;
	 if ((start == NULL) &&(last == NULL))
	 {
	 cout<< "empty list"<< endl;
	 return;}
	 b = last->num;
	 while(1)
	 {
		 if( last->num == a)
		 {   do { 
			 cout << last->num<< endl;
			 last = last->next;}
			 while( last->num != a);
		 last = temp;
		 return;}
		  else { last = last->next;
		            if ( last->num == b)
		                {cout << "not found" << endl;
		                 last = temp;
		                 return;}
		                   }}
					   }
 
void Dlist::del(int a)
{ 
	 Elem *temp;
	 int b;
	  if ((start == NULL) &&(last == NULL))
	 {
	 cout<< "empty list"<< endl;
	 return;}
	 b = last->num;
	 temp = last;
	 if (start == last)
	 {   delete start;
		 start = NULL;
         last = start;
      return;} 
     while(1)
	 {
		 if( last->num == a)
		 { 
	        if (last->next == last->prev)
	        {
	          delete last;
	          start->next = start;
	          start->prev = start;
	          last = start;
	          cout << "deleted"<< endl;
		      return;}
	          
	     (last->prev)->next = last->next;
	     (last->next)->prev  = last->prev;
		  delete last;
		  cout << "deleted"<< endl;
		  return;}
			else { last = last->next;
		            if ( last->num == b)
		                {cout << "not found" << endl;
		                 last = temp;
		                 return;}}
      }
  }
      
Elem* Dlist::find(int a)
{
	 Elem *temp = new Elem;
	 temp = last ;
	 int b;
	 if ((start == NULL) &&(last == NULL))
	 {
	 cout<< "empty list"<< endl;
	 return NULL;}
	 b = last->num;
	 while(1)
	 {	 
		 if( last->num == a)
		 { last = temp;
		  cout << "found"<< endl;
		  return temp;}
			else { last = last->next;
		            if ( last->num == b)
		                {cout << "not found" << endl;
		                 last = temp;
		                 return NULL;}}
   	  }}
   
void testList()
{    Dlist a;
	 a.print(1);
	 a.add(1);
	 a.print(1);
	 a.del(1);
	 a.print(1);
	 a.add(3);
	 a.add(5);
	 a.add(9);
	 a.print(5);
	 a.del(5);
	 a.print(9);
	 a.del(9);
	 a.find(9);
	 a.print(3);
	 a.del(3);
	 a.print(3);
}
