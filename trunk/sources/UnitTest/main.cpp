/**
 * @file: UnitTest/main.cpp
 * Implementation and entry point for unit testing of scheme compiler project
 */
/*
 * Copyright (C) 2012  MIPT Scheme Compiler team
 */
#include "utest_impl.h"

#define BOOST_TEST_MODULE scheme_compiler
#include <boost/test/unit_test.hpp>

/** Fixture for singletons' init/deinit */
struct GlobalFixture {
    GlobalFixture();
    ~GlobalFixture();
};

/* Required global initializations should go here */
GlobalFixture::GlobalFixture()
{

}

/* Deinitializations of globals/singletons */
GlobalFixture::~GlobalFixture()
{  
    cout.flush();
    cerr.flush();
}

BOOST_GLOBAL_FIXTURE( GlobalFixture );

