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
public:									//to be private
	int data;
	Node *next, *prev;
	Edge *pred_edge, *succ_edge;		// Predecessors - edges "to" here
										// Successors - edges "from" here
public:
	Node ( int data);
	~Node () {};
	Edge* getPred()
	{
		return pred_edge;
	};
	Edge* getSucc(){
		return succ_edge;
	}
};
