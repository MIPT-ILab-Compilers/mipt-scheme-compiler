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
	Node *node0, *node1;
	Edge *edge01, *edge11, *edge10;

	node0 = g1.addNode();
	BOOST_CHECK_EQUAL( node0, g1.getFirstNode());
	BOOST_CHECK_EQUAL( node0->getData(), 0);
	BOOST_CHECK_EQUAL( node0->getNext(), null);
	BOOST_CHECK_EQUAL( node0->getPrev(), null);
	BOOST_CHECK_EQUAL( node0->getPred(), null);
	BOOST_CHECK_EQUAL( node0->getSucc(), null);
	BOOST_CHECK_EQUAL( g1.getFirstNode(), g1.getLastNode());

	node1 = g1.addNode();
	BOOST_CHECK_EQUAL( node1, g1.getLastNode());
	BOOST_CHECK_EQUAL( node1->getData(), 1);
	BOOST_CHECK_EQUAL( node0->getNext(), node1);
	BOOST_CHECK_EQUAL( node1->getPrev(), node0);
	BOOST_CHECK_EQUAL( node1->getNext(), null);
	BOOST_CHECK_EQUAL( node1->getPred(), null);
	BOOST_CHECK_EQUAL( node1->getSucc(), null);


	edge01 = g1.addEdge( node0, node1);
	BOOST_CHECK_EQUAL( edge01, g1.getFirstEdge());
	BOOST_CHECK_EQUAL( node0->getPred(), null);
	BOOST_CHECK_EQUAL( node0->getSucc(), edge01);
	BOOST_CHECK_EQUAL( node1->getPred(), edge01);
	BOOST_CHECK_EQUAL( node1->getSucc(), null);
	BOOST_CHECK_EQUAL( g1.getFirstEdge(), g1.getLastEdge());
	BOOST_CHECK_EQUAL( edge01->getNext(), null);
	BOOST_CHECK_EQUAL( edge01->getPrev(), null);

	edge11 = g1.addEdge( node1, node1);
	BOOST_CHECK_EQUAL( edge11, g1.getLastEdge());
	BOOST_CHECK_EQUAL( node1->getPred(), edge11);
	BOOST_CHECK_EQUAL( node1->getSucc(), edge11);
	BOOST_CHECK_EQUAL( edge01->getNext(), edge11);
	BOOST_CHECK_EQUAL( edge11->getPrev(), edge01);
	BOOST_CHECK_EQUAL( edge01->getPrev(), null);


	g1.rmEdge( edge11);
	BOOST_CHECK_EQUAL( node0->getPred(), null);
	BOOST_CHECK_EQUAL( node0->getSucc(), edge01);
	BOOST_CHECK_EQUAL( node1->getPred(), edge01);
	BOOST_CHECK_EQUAL( node1->getSucc(), null);
	BOOST_CHECK_EQUAL( edge01, g1.getFirstEdge());
	BOOST_CHECK_EQUAL( g1.getFirstEdge(), g1.getLastEdge());
	BOOST_CHECK_EQUAL( edge01->getNext(), null);
	BOOST_CHECK_EQUAL( edge01->getPrev(), null);

	edge10 = g1.addEdge( node1, node0);
	BOOST_CHECK_EQUAL( edge10, g1.getLastEdge());
	BOOST_CHECK_EQUAL( node0->getPred(), edge10);
	BOOST_CHECK_EQUAL( node0->getSucc(), edge01);
	BOOST_CHECK_EQUAL( node1->getPred(), edge01);
	BOOST_CHECK_EQUAL( node1->getSucc(), edge10);
	BOOST_CHECK_EQUAL( edge01->getNext(), edge10);
	BOOST_CHECK_EQUAL( edge10->getPrev(),edge01);
	BOOST_CHECK_EQUAL( edge01->getPrev(), null);


	for ( int i = 0; i < 10; i++)
		g1.addNode();
	int count = 0;
	for ( Node* N = g1.getFirstNode(); N!= 0; N = N->getNext())
	{
		BOOST_CHECK_EQUAL( N->getData(), count);
		count ++;
	}

	BOOST_CHECK_EQUAL( count, 12);

	g1.rmEdge( edge01);
	BOOST_CHECK_EQUAL( edge10, g1.getLastEdge());
	BOOST_CHECK_EQUAL( node0->getSucc(), null);
	BOOST_CHECK_EQUAL( node0->getPred(), edge10);
	BOOST_CHECK_EQUAL( node1->getSucc(), edge10);
	BOOST_CHECK_EQUAL( node1->getPred(), null);
	BOOST_CHECK_EQUAL( g1.getFirstEdge(), g1.getLastEdge());
	BOOST_CHECK_EQUAL( edge10->getNext(), null);
	BOOST_CHECK_EQUAL( edge10->getPrev(), null);
}



BOOST_AUTO_TEST_SUITE_END()

}
