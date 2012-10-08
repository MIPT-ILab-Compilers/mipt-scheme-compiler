/**
 * @file ir/ir_utest.cpp
 * Unit testing of IR
 */
#include "ir_iface.hpp"
#include <boost/test/unit_test.hpp>

BOOST_AUTO_TEST_SUITE( IR)

BOOST_AUTO_TEST_CASE( ir_basic)
{
	BOOST_CHECK( 2 * 2 == 4);
}

BOOST_AUTO_TEST_SUITE_END()