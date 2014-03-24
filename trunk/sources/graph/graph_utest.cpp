/**
 * @file graph/graph_utest.cpp
 * Unit testing of Graph
 */
#include <boost/test/unit_test.hpp>
#include "graph_iface.hpp"

namespace graph
{

BOOST_AUTO_TEST_SUITE( GRAPH)

BOOST_AUTO_TEST_CASE( graph_basic)
{
    BOOST_CHECK( 2*2 == 4);
	Graph g1;
	void* null = NULL;

	g1.addNode( 1 );
	BOOST_CHECK_EQUAL( g1.first_node->data, 1);
	BOOST_CHECK_EQUAL( g1.last_node->data, 1);
	BOOST_CHECK_EQUAL( g1.first_node, g1.last_node);
	BOOST_CHECK_EQUAL( g1.first_edge, null);
	BOOST_CHECK_EQUAL( g1.last_edge, null);
	BOOST_CHECK_EQUAL( g1.first_node->next, null);
	BOOST_CHECK_EQUAL( g1.first_node->prev, null);
	BOOST_CHECK_EQUAL( g1.first_node->pred_edge, null);
	BOOST_CHECK_EQUAL( g1.first_node->succ_edge, null);

	g1.addNode( 2 );
	BOOST_CHECK_EQUAL( g1.first_node->data, 2);
	BOOST_CHECK_EQUAL( g1.last_node->data, 1);
	BOOST_CHECK_EQUAL( g1.first_edge, null);
	BOOST_CHECK_EQUAL( g1.last_edge, null);
	BOOST_CHECK_EQUAL( g1.first_node->prev, null);
	BOOST_CHECK_EQUAL( g1.first_node->next, g1.last_node);
	BOOST_CHECK_EQUAL( g1.last_node->next, null);
	BOOST_CHECK_EQUAL( g1.last_node->prev, g1.first_node);
	BOOST_CHECK_EQUAL( g1.first_node->pred_edge, null);
	BOOST_CHECK_EQUAL( g1.first_node->succ_edge, null);
	BOOST_CHECK_EQUAL( g1.last_node->pred_edge, null);
	BOOST_CHECK_EQUAL( g1.last_node->succ_edge, null);


	g1.addEdge( g1.first_node, g1.last_node );
	BOOST_CHECK_EQUAL( g1.first_node->data, 2);
	BOOST_CHECK_EQUAL( g1.last_node->data, 1);
	BOOST_CHECK_EQUAL( g1.first_node->prev, null);
	BOOST_CHECK_EQUAL( g1.first_node->next, g1.last_node);
	BOOST_CHECK_EQUAL( g1.last_node->next, null);
	BOOST_CHECK_EQUAL( g1.last_node->prev, g1.first_node);
	BOOST_CHECK_EQUAL( g1.first_node->pred_edge, null);
	BOOST_CHECK_EQUAL( g1.first_node->succ_edge, g1.first_edge);
	BOOST_CHECK_EQUAL( g1.last_node->pred_edge, g1.first_edge);
	BOOST_CHECK_EQUAL( g1.last_node->succ_edge, null);
	BOOST_CHECK_EQUAL( g1.first_edge, g1.last_edge);
	BOOST_CHECK_EQUAL( g1.first_edge->next, null);
	BOOST_CHECK_EQUAL( g1.first_edge->prev, null);

	g1.addEdge( g1.last_node, g1.last_node );
	BOOST_CHECK_EQUAL( g1.last_node->data, 1);
	BOOST_CHECK_EQUAL( g1.first_node->prev, null);
	BOOST_CHECK_EQUAL( g1.first_node->next, g1.last_node);
	BOOST_CHECK_EQUAL( g1.last_node->next, null);
	BOOST_CHECK_EQUAL( g1.last_node->prev, g1.first_node);
	BOOST_CHECK_EQUAL( g1.first_node->pred_edge, null);
	BOOST_CHECK_EQUAL( g1.first_node->succ_edge, g1.last_edge);
	BOOST_CHECK_EQUAL( g1.last_node->pred_edge, g1.first_edge);
	BOOST_CHECK_EQUAL( g1.last_node->succ_edge, g1.first_edge);
	BOOST_CHECK_EQUAL( g1.first_edge->next, g1.last_edge);
	BOOST_CHECK_EQUAL( g1.last_edge->prev, g1.first_edge);
	BOOST_CHECK_EQUAL( g1.first_edge->prev, null);


	g1.rmEdge( g1.first_edge );
	BOOST_CHECK_EQUAL( g1.first_node->data, 2);
	BOOST_CHECK_EQUAL( g1.last_node->data, 1);
	BOOST_CHECK_EQUAL( g1.first_node->prev, null);
	BOOST_CHECK_EQUAL( g1.first_node->next, g1.last_node);
	BOOST_CHECK_EQUAL( g1.last_node->next, null);
	BOOST_CHECK_EQUAL( g1.last_node->prev, g1.first_node);
	BOOST_CHECK_EQUAL( g1.first_node->pred_edge, null);
	BOOST_CHECK_EQUAL( g1.first_node->succ_edge, g1.first_edge);
	BOOST_CHECK_EQUAL( g1.last_node->pred_edge, g1.first_edge);
	BOOST_CHECK_EQUAL( g1.last_node->succ_edge, null);
	BOOST_CHECK_EQUAL( g1.first_edge, g1.last_edge);
	BOOST_CHECK_EQUAL( g1.first_edge->next, null);
	BOOST_CHECK_EQUAL( g1.first_edge->prev, null);

	g1.addEdge( g1.last_node, g1.first_node );
	BOOST_CHECK_EQUAL( g1.first_node->data, 2);
	BOOST_CHECK_EQUAL( g1.last_node->data, 1);
	BOOST_CHECK_EQUAL( g1.first_node->prev, null);
	BOOST_CHECK_EQUAL( g1.first_node->next, g1.last_node);
	BOOST_CHECK_EQUAL( g1.last_node->next, null);
	BOOST_CHECK_EQUAL( g1.last_node->prev, g1.first_node);
	BOOST_CHECK_EQUAL( g1.first_node->pred_edge, g1.first_edge);
	BOOST_CHECK_EQUAL( g1.first_node->succ_edge, g1.last_edge);
	BOOST_CHECK_EQUAL( g1.last_node->pred_edge, g1.last_edge);
	BOOST_CHECK_EQUAL( g1.last_node->succ_edge, g1.first_edge);
	BOOST_CHECK_EQUAL( g1.first_edge->next, g1.last_edge);
	BOOST_CHECK_EQUAL( g1.last_edge->prev, g1.first_edge);
	BOOST_CHECK_EQUAL( g1.first_edge->prev, null);

	g1.rmEdge( g1.last_edge );
	BOOST_CHECK_EQUAL( g1.first_node->data, 2);
	BOOST_CHECK_EQUAL( g1.last_node->data, 1);
	BOOST_CHECK_EQUAL( g1.first_node->prev, null);
	BOOST_CHECK_EQUAL( g1.first_node->next, g1.last_node);
	BOOST_CHECK_EQUAL( g1.last_node->next, null);
	BOOST_CHECK_EQUAL( g1.last_node->prev, g1.first_node);
	BOOST_CHECK_EQUAL( g1.first_node->succ_edge, null);
	BOOST_CHECK_EQUAL( g1.first_node->pred_edge, g1.first_edge);
	BOOST_CHECK_EQUAL( g1.last_node->succ_edge, g1.first_edge);
	BOOST_CHECK_EQUAL( g1.last_node->pred_edge, null);
	BOOST_CHECK_EQUAL( g1.first_edge, g1.last_edge);
	BOOST_CHECK_EQUAL( g1.first_edge->next, null);
	BOOST_CHECK_EQUAL( g1.first_edge->prev, null);

}



BOOST_AUTO_TEST_SUITE_END()

}
