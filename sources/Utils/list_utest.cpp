/**
 * @file: list_utest.cpp 
 * Implementation of testing for lists 
 */
/*
 * Copyright (C) 2012  MIPT Scheme Compiler team
 */
#include "utils_iface.h"

#include <boost/test/unit_test.hpp>

static const int LIST_TEST_NUM_NODES = 10000;
using boost::array;

BOOST_AUTO_TEST_SUITE( lists)

struct StdListDummy
{
public:
    long long i;
    long long j;
};

typedef std::list< StdListDummy*> DummyList;

TIMED_AUTO_TEST_CASE( std_list_perf)
{
    DummyList list;
    /* Create */
    for ( int i = 0; i < LIST_TEST_NUM_NODES; i++)
    {
        StdListDummy *ptr = new StdListDummy();
        list.push_front( ptr);
    }

    for ( DummyList::iterator it = list.begin(), end = list.end();
          it != end;
          ++it)
    {
        (*it)->i = 10;
    }
    for ( DummyList::iterator it = list.begin(), next = it, end = list.end();
          it != end;
          )
    {
        next = it;
        next++;
        delete (*it);
        list.erase( it);
        it = next;
    }
}

class ListAList{};
class ListBList1{};
class ListBList2{};

class ListA: public ListItem< ListA, ListAList>
{
    int a;
};

class ListB: public ListA, public ListItem< ListB, ListBList1>, public ListItem< ListB, ListBList2>
{
    typedef ListItem< ListB, ListBList1> List1;
	typedef ListItem< ListB, ListBList2> List2;
public:
    int i;

    ListB( ListB* ptr): ListItem< ListB, ListBList1>( ptr){};

    ListB *nextB(){ return static_cast< ListB *>( List1::next() );}
    ListB *prevB(){ return static_cast< ListB *>( List1::prev() );}

	ListB *nextBInList2(){ return static_cast< ListB *>( List2::next() );}
    ListB *prevBInList2(){ return static_cast< ListB *>( List2::prev() );}

	void attachInList2( ListB *peer)
	{
		List2::attach( peer);
	}
};

TIMED_AUTO_TEST_CASE( my_list_perf)
{
    ListB *list = NULL;
    ListB *list_temp = NULL;
	boost::array< ListB *, LIST_TEST_NUM_NODES> items;
    /* Create */
    for ( int i = 0; i < LIST_TEST_NUM_NODES; i++)
    {
        list = new ListB( list);
		items[ i] = list;
		if ( i % 100 == 0 && i > 100)
		{
			list->attachInList2( items[i - 100]);
		}
    }
    /* Iterate and access data */
    list_temp = list;
    while ( isNotNullP( list_temp))
    {
        list_temp->i = 10;
        list_temp = list_temp->nextB();
    }
    /* Iterate and access data */
    list_temp = list;
    while ( isNotNullP( list_temp))
    {
        ListB *next = list_temp->nextB();
        delete list_temp;
        list_temp = next;
    }
}


BOOST_AUTO_TEST_SUITE_END()
