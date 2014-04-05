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
		Graph::last_node->next = new_node;
	new_node->prev = last_node;
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
		if ( node->prev > 0 )
			node->prev->next = node->next;
		else
			if ( Graph::first_node == node )
				Graph::first_node = node->next;
			else std::cout << "some error in graph structure in rmNode\n";

		if ( node->next > 0 )
			node->next->prev = node->prev;
		else
			if ( Graph::last_node == node )
				Graph::last_node = node->prev;
			else std::cout << "some error in graph structure in rmNode\n";


		while ( node->first_pred_edge != NULL )
			Graph::rmEdge( node->first_pred_edge);
		while ( node->first_succ_edge != NULL )
			Graph::rmEdge( node->first_succ_edge);

		delete node;
	}
};

Edge* Graph::addEdge ( Node *prednode, Node *succnode)
{
	if ( (prednode <= 0)||(succnode <= 0))
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
			Graph::last_edge->next = new_edge;
		new_edge->prev = Graph::last_edge;
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
		if ( edge->prev > 0 )
			edge->prev->next = edge->next;
		else
			if ( Graph::first_edge == edge )
				Graph::first_edge = edge->next;
			else std::cout << "some error in graph structure\n";

		if ( edge->next > 0 )
			edge->next->prev = edge->prev;
		else
			if ( Graph::last_edge == edge )
				Graph::last_edge = edge->prev;
			else std::cout << "some error in graph structure\n";

		if ( edge->prev_pred_edge > 0 )  //see from here
			edge->prev_pred_edge->next_pred_edge = edge->next_pred_edge;
		else
			edge->succ_node->first_pred_edge = edge->next_pred_edge;
		if ( edge->next_pred_edge > 0 )
			edge->next_pred_edge->prev_pred_edge = edge->prev_pred_edge;

		if ( edge->prev_succ_edge > 0 )
			edge->prev_succ_edge->next_succ_edge = edge->next_succ_edge;
		else
			edge->pred_node->first_succ_edge = edge->next_succ_edge;
		if ( edge->next_succ_edge > 0 )
			edge->next_succ_edge->prev_succ_edge = edge->prev_succ_edge;

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
