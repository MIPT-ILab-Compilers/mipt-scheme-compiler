/**
 * @file: list_utest.cpp 
 * Implementation of testing for lists 
 */
/*
 * Copyright (C) 2012  MIPT Scheme Compiler team
 */
#include "utils_iface.h"

#include <boost/test/unit_test.hpp>

static const int LIST_TEST_NUM_NODES = 10000000;


/** Define the  lists we use */
enum TestListType
{
    LIST_ONE,
    LIST_TWO,
    LIST_THREE,
    LISTS_NUM
};

static const TestListType TEST_LIST_ID = LIST_THREE; 

/** Derive class of linked objects */
class ClassAList: public MListIface< ClassAList, LISTS_NUM>
{

};

/** Derive class from A */
class B: public ClassAList
{

};

BOOST_AUTO_TEST_SUITE( lists)
/**
 * Test simple singleton
 */
BOOST_AUTO_TEST_CASE( multi_list)
/** MList testing */
//static bool uTestMList()
{
    B *obj1 = new B();
    B *obj2 = new B();
    B *obj3 = new B();
    obj1->attach( LIST_ONE, obj2);
    obj1->attach( LIST_TWO, obj3);
    BOOST_CHECK( areEqP( obj1->next( LIST_ONE), obj2));
    BOOST_CHECK( areEqP( obj1->next( LIST_TWO), obj3));
    BOOST_CHECK( isNullP( obj1->prev( LIST_ONE)));
    BOOST_CHECK( isNullP( obj1->prev( LIST_TWO)));
    BOOST_CHECK( areEqP( obj2->prev( LIST_ONE), obj1));
    BOOST_CHECK( areEqP( obj3->prev( LIST_TWO), obj1));
    BOOST_CHECK( isNullP( obj3->prev( LIST_ONE)));
    BOOST_CHECK( isNullP( obj2->prev( LIST_TWO)));
    BOOST_CHECK( isNullP( obj2->next( LIST_ONE)));
    BOOST_CHECK( isNullP( obj3->next( LIST_TWO)));
    obj2->detachAll();
    delete obj2;
    delete obj1;
    delete obj3;
//    return true;
}


struct MyMListDummy: public MListIface<MyMListDummy, LISTS_NUM>
{
public:
    long long i;
    long long j;
    MyMListDummy( MyMListDummy* ptr): MListIface<MyMListDummy, LISTS_NUM>( TEST_LIST_ID, ptr){};
};

struct MySListDummy: public SListIface<MySListDummy>
{
public:
    long long i;
    long long j;
    MySListDummy( MySListDummy* ptr): SListIface<MySListDummy>( ptr){};
};


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

TIMED_AUTO_TEST_CASE( my_mlist_one_perf)
{
    MyMListDummy *list = NULL;
    MyMListDummy *list_temp = NULL;
    /* Create */
    for ( int i = 0; i < LIST_TEST_NUM_NODES; i++)
    {
        list = new MyMListDummy( list);
    }
    /* Iterate and access data */
    list_temp = list;
    while ( isNotNullP( list_temp))
    {
        list_temp->i = 10;
        list_temp = list_temp->next( TEST_LIST_ID);
    }
    /* Iterate and access data */
    list_temp = list;
    while ( isNotNullP( list_temp))
    {
        MyMListDummy *next = list_temp->next( TEST_LIST_ID);
        delete list_temp;
        list_temp = next;
    }
}

TIMED_AUTO_TEST_CASE( my_slist_perf)
{
    MySListDummy *list = NULL;
    MySListDummy *list_temp = NULL;
    /* Create */
    for ( int i = 0; i < LIST_TEST_NUM_NODES; i++)
    {
        list = new MySListDummy( list);
    }
    /* Iterate and access data */
    list_temp = list;
    while ( isNotNullP( list_temp))
    {
        list_temp->i = 10;
        list_temp = list_temp->next();
    }
    /* Iterate and access data */
    list_temp = list;
    while ( isNotNullP( list_temp))
    {
        MySListDummy *next = list_temp->next();
        delete list_temp;
        list_temp = next;
    }
}


BOOST_AUTO_TEST_SUITE_END()
