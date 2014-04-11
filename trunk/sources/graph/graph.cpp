/**
 * @file: graph.cpp
 * Implementation of Graph
 */
/**
 * Copyright (C) 2013  MIPT Scheme Compiler team
 */

#include "graph.hpp"


Node* Graph::addNode ()
{
	Node* new_node = new Node( node_id );
	if ( Graph::first_node == NULL )
		if ( Graph::last_node == NULL )
			Graph::first_node = new_node;
		else
			std::cout << "some error in graph structure in addNode\n";
	else
		Graph::last_node->setNext( new_node );
	new_node->setPrev( last_node );
	Graph::last_node = new_node;
	node_id++;
	return new_node;

};

void Graph::rmNode ( Node *node)
{
	if ( node <= 0 )
		std::cout << "Wrong arguments of rmNode\n";
	else
	{
		if ( node->getPrev() > 0 )
			node->getPrev()->setNext( node->getNext() );
		else
			if ( Graph::first_node == node )
				Graph::first_node = node->getNext();
			else std::cout << "some error in graph structure in rmNode\n";

		if ( node->getNext() > 0 )
			node->getNext()->setPrev( node->getPrev() );
		else
			if ( Graph::last_node == node )
				Graph::last_node = node->getPrev();
			else std::cout << "some error in graph structure in rmNode\n";


		while ( node->getPred() != NULL )
			Graph::rmEdge( node->getPred() );
		while ( node->getSucc() != NULL )
			Graph::rmEdge( node->getSucc() );

		delete node;
	}
};

Edge* Graph::addEdge ( Node *prednode, Node *succnode)
{
	if ( (prednode <= 0)||(succnode <= 0) )
		std::cout << "Wrong arguments of addEdge\n";
	else
	{
		Edge *new_edge = new Edge (prednode, succnode);
		if ( Graph::first_edge == NULL )
			if ( Graph::last_edge == NULL )
 				Graph::first_edge = new_edge;
			else
				std::cout << "some error in graph structure in addEdge\n";
		else
			Graph::last_edge->setNext( new_edge );
		new_edge->setPrev( Graph::last_edge );
		Graph::last_edge = new_edge;
		return new_edge;
	}
	return 0;

};

void Graph::rmEdge ( Edge *edge)
{
	if (edge <= 0)
		std::cout << "Wrong arguments of rmEdge\n";
	else
	{
		if ( edge->getPrev() > 0 )
			edge->getPrev()->setNext( edge->getNext() );
		else
			if ( Graph::first_edge == edge )
				Graph::first_edge = edge->getNext();
			else std::cout << "some error in graph structure\n";

		if ( edge->getNext() > 0 )
			edge->getNext()->setPrev( edge->getPrev() );
		else
			if ( Graph::last_edge == edge )
				Graph::last_edge = edge->getPrev();
			else std::cout << "some error in graph structure\n";

		if ( edge->getPrevPredEdge() > 0 )  //see from here
			edge->getPrevPredEdge()->setNextPredEdge( edge->getNextPredEdge() );
		else
			edge->getSuccNode()->setPred( edge->getNextPredEdge() );
		if ( edge->getNextPredEdge() > 0 )
			edge->getNextPredEdge()->setPrevPredEdge( edge->getPrevPredEdge() );

		if ( edge->getPrevSuccEdge() > 0 )
			edge->getPrevSuccEdge()->setNextSuccEdge( edge->getNextSuccEdge() );
		else
			edge->getPredNode()->setSucc( edge->getNextSuccEdge() );
		if ( edge->getNextSuccEdge() > 0 )
			edge->getNextSuccEdge()->setPrevSuccEdge( edge->getPrevSuccEdge() );

		delete edge;
	}
};

Graph::Graph ()
{
	Graph::first_edge = NULL;
	Graph::last_edge = NULL;

	Graph::first_node = NULL;
	Graph::last_node = NULL;

	Graph::node_id = 0;
};

Graph::~Graph ()
{
	while ( Graph::first_edge != NULL )
		Graph::rmEdge( Graph::first_edge);
	while ( Graph::first_node != NULL )
		Graph::rmNode( Graph::first_node);
};
