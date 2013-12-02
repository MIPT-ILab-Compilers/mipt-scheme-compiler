/**
 * @file: node.hpp
 * Declaration of Node
 */
/**
 * Copyright (C) 2013  MIPT Scheme Compiler team
 */

#pragma once

#include "graph_iface.hpp"

class Node
{
public:
	int data;
	Node *next, *prev;
	Edge *pred_edge, *succ_edge;		// Predecessors - edges "to" here
										// Successors - edges "from" here
	Node ( int data);
	~Node () {};
};
