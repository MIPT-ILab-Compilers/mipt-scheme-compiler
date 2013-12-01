/**
 * @file graph/graph_utest.cpp
 * Unit testing of Graph
 */
#include <boost/test/unit_test.hpp>
#include "graph_iface.hpp"

namespace graph
{

BOOST_AUTO_TEST_SUITE( Graph)

BOOST_AUTO_TEST_CASE( graph_basic)
{
    BOOST_CHECK( 2*2 == 5);
}



BOOST_AUTO_TEST_SUITE_END()

}
