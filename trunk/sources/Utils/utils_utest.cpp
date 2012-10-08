/**
 * @file: utils_utest.cpp 
 * Implementation of testing of utils
 */
/*
 * Copyright (C) 2012  MIPT Scheme Compiler team
 */
#include "utils_iface.h"
#include <boost/test/unit_test.hpp>

/** Sample class */
class A
{
    int a;
    /** private constructors, assignment and destructor */
    A(){};
    A( const A&){};
    A& operator =( const A&){};
    ~A(){};
    /** Needed for singleton creation */
    friend class Single< A>;
};

/** Typedef for A encapsulated in singleton */
typedef Single< A> SingleA;

BOOST_AUTO_TEST_SUITE( simple_utils)
/**
 * Test simple singleton
 */
BOOST_AUTO_TEST_CASE( singleton)
{
    SingleA::init();

    A* a1 = SingleA::instance();
    A* a2 = SingleA::instance();
    BOOST_CHECK( areEqP( a1, a2));
    SingleA::deinit();
}

BOOST_AUTO_TEST_SUITE_END()

