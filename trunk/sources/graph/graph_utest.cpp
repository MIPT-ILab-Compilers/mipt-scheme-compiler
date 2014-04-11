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
	Graph g1;
	void* null = NULL;

	g1.addNode();
	BOOST_CHECK_EQUAL( g1.getFirstNode()->getData(), 0);
	BOOST_CHECK_EQUAL( g1.getLastNode()->getData(), 0);
	BOOST_CHECK_EQUAL( g1.getFirstNode(), g1.getFirstNode());
	BOOST_CHECK_EQUAL( g1.getFirstNode()->getNext(), null);
	BOOST_CHECK_EQUAL( g1.getFirstNode()->getPrev(), null);
	BOOST_CHECK_EQUAL( g1.getFirstNode()->getPred(), null);
	BOOST_CHECK_EQUAL( g1.getFirstNode()->getSucc(), null);

	g1.addNode();
	BOOST_CHECK_EQUAL( g1.getLastNode()->getData(), 1);
	BOOST_CHECK_EQUAL( g1.getFirstNode()->getData(), 0);
	BOOST_CHECK_EQUAL( g1.getFirstNode()->getPrev(), null);
	BOOST_CHECK_EQUAL( g1.getFirstNode()->getNext(), g1.getLastNode());
	BOOST_CHECK_EQUAL( g1.getLastNode()->getNext(), null);
	BOOST_CHECK_EQUAL( g1.getLastNode()->getPrev(), g1.getFirstNode());
	BOOST_CHECK_EQUAL( g1.getFirstNode()->getPred(), null);
	BOOST_CHECK_EQUAL( g1.getFirstNode()->getSucc(), null);
	BOOST_CHECK_EQUAL( g1.getLastNode()->getPred(), null);
	BOOST_CHECK_EQUAL( g1.getLastNode()->getSucc(), null);


	g1.addEdge( g1.getFirstNode(), g1.getLastNode() );
	BOOST_CHECK_EQUAL( g1.getFirstNode()->getPred(), null);
	BOOST_CHECK_EQUAL( g1.getFirstNode()->getSucc(), g1.getFirstEdge());
	BOOST_CHECK_EQUAL( g1.getLastNode()->getPred(), g1.getFirstEdge());
	BOOST_CHECK_EQUAL( g1.getLastNode()->getSucc(), null);
	BOOST_CHECK_EQUAL( g1.getFirstEdge(), g1.getLastEdge());
	BOOST_CHECK_EQUAL( g1.getFirstEdge()->getNext(), null);
	BOOST_CHECK_EQUAL( g1.getFirstEdge()->getPrev(), null);

	g1.addEdge( g1.getLastNode(), g1.getLastNode() );
	BOOST_CHECK_EQUAL( g1.getFirstNode()->getPred(), null);
	BOOST_CHECK_EQUAL( g1.getFirstNode()->getSucc(), g1.getFirstEdge());
	BOOST_CHECK_EQUAL( g1.getLastNode()->getPred(), g1.getLastEdge());
	BOOST_CHECK_EQUAL( g1.getLastNode()->getSucc(), g1.getLastEdge());
	BOOST_CHECK_EQUAL( g1.getFirstEdge()->getNext(), g1.getLastEdge());
	BOOST_CHECK_EQUAL( g1.getLastEdge()->getPrev(), g1.getFirstEdge());
	BOOST_CHECK_EQUAL( g1.getFirstEdge()->getPrev(), null);


	g1.rmEdge( g1.getLastEdge() );
	BOOST_CHECK_EQUAL( g1.getFirstNode()->getPred(), null);
	BOOST_CHECK_EQUAL( g1.getFirstNode()->getSucc(), g1.getLastEdge());
	BOOST_CHECK_EQUAL( g1.getLastNode()->getPred(), g1.getLastEdge());
	BOOST_CHECK_EQUAL( g1.getLastNode()->getSucc(), null);
	BOOST_CHECK_EQUAL( g1.getFirstEdge(), g1.getLastEdge());
	BOOST_CHECK_EQUAL( g1.getFirstEdge()->getNext(), null);
	BOOST_CHECK_EQUAL( g1.getFirstEdge()->getPrev(), null);

	g1.addEdge( g1.getLastNode(), g1.getFirstNode() );
	BOOST_CHECK_EQUAL( g1.getFirstNode()->getPred(), g1.getLastEdge());
	BOOST_CHECK_EQUAL( g1.getFirstNode()->getSucc(), g1.getFirstEdge());
	BOOST_CHECK_EQUAL( g1.getLastNode()->getPred(), g1.getFirstEdge());
	BOOST_CHECK_EQUAL( g1.getLastNode()->getSucc(), g1.getLastEdge());
	BOOST_CHECK_EQUAL( g1.getFirstEdge()->getNext(), g1.getLastEdge());
	BOOST_CHECK_EQUAL( g1.getLastEdge()->getPrev(), g1.getFirstEdge());
	BOOST_CHECK_EQUAL( g1.getFirstEdge()->getPrev(), null);


	for ( int i = 0; i < 10; i++ )
		g1.addNode();
	int count = 0;
	for ( Node* N = g1.getFirstNode(); N!= 0; N = N->getNext())
	{
		BOOST_CHECK_EQUAL( N->getData(), count);
		count ++;
	}

	BOOST_CHECK_EQUAL( count, 12 );

	g1.rmEdge( g1.getFirstEdge() );
	BOOST_CHECK_EQUAL( g1.getFirstNode()->getSucc(), null);
	BOOST_CHECK_EQUAL( g1.getFirstNode()->getPred(), g1.getLastEdge());
	BOOST_CHECK_EQUAL( g1.getFirstNode()->getNext()->getSucc(), g1.getLastEdge());
	BOOST_CHECK_EQUAL( g1.getLastNode()->getPred(), null);
	BOOST_CHECK_EQUAL( g1.getFirstEdge(), g1.getLastEdge());
	BOOST_CHECK_EQUAL( g1.getFirstEdge()->getNext(), null);
	BOOST_CHECK_EQUAL( g1.getFirstEdge()->getPrev(), null);
}



BOOST_AUTO_TEST_SUITE_END()

}
