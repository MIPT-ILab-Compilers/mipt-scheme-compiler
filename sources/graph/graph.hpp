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
private:
	Node *first_node, *last_node;
	Edge *first_edge, *last_edge;
	int node_id;
public:
	Node* addNode ();									//friend to Node::setNext(), Node::setPrev() needed here
	void rmNode ( Node *node);							//friend to Node::setNext(), Node::setPrev() needed here
	Edge* addEdge ( Node *prednode, Node *succnode);	//friend to Edge::setNext(), Edge::setPrev() needed here
	void rmEdge ( Edge *edge);							//friend to Node::setNext(), Node::setPrev(), Edge::set*() needed here

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
