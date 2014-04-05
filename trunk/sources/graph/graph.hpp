/**
 * @file: graph.hpp
 * Declaration of Graph
 */
/**
 * Copyright (C) 2013  MIPT Scheme Compiler team
 */

#pragma once

#include "graph_iface.hpp"

class Graph
{
public:							//to be private
	Node *first_node, *last_node;
	Edge *first_edge, *last_edge;
	int node_id;
public:
	Node* addNode ();
	void rmNode ( Node *node);
	Edge* addEdge ( Node *prednode, Node *succnode);
	void rmEdge ( Edge *edge);

	Graph ();
	~Graph ();

	Node *getFirstNode() {
		return first_node;
	};
	Node *getLastNode() {
		return last_node;
	};
	Edge *getFirstEdge() {
		return first_edge;
	};
	Edge *getLastEdge() {
		return last_edge;
	};
};
