/**
 * @file parser_utest.cpp
 * Unit test for parsing functionality
 */

#include <boost/test/unit_test.hpp>
#include "dump_reader.hpp"
#include <string>
#include <sstream>
#include <iostream>

BOOST_AUTO_TEST_CASE( dump_reader)
{
    /**
     * Just check that it can read without crash.
     */
    std::string str("( sym[0]. ( ( n[1]. ( n[2]. ( \"abcd\". ()))). ()))");
    
    BOOST_TEST_MESSAGE( "Testing DumpReader with string" + str);
    
    std::stringstream str_stream( str);
    
    parser::DumpReader dr( str_stream);
    
    parser::Nodep ast;

    /**
     * Try to read dump. If something goes wrong boost utest will catch it.
     */
    ast = dr.read();
}
