/**
 * @file: edge.hpp
 * Declaration of Edge
 */
/**
 * Copyright (C) 2013  MIPT Scheme Compiler team
 */

#pragma once

#include "graph_iface.hpp"


class Edge
{
public:										//to be private
	Edge *next, *prev;
	Edge *next_succ_edge, *prev_succ_edge, //for the list in the node where the edge begins
		 *next_pred_edge, *prev_pred_edge; //for the list in the node where the edge ends

	Node *pred_node, *succ_node;
public:
	Edge ( Node *pred_node, Node *succ_node);
	~Edge () {};
	Edge* nextSuccEdge(){
		return next_succ_edge;
	};
	Edge* prevSuccEdge(){
		return prev_succ_edge;
	};
	Edge* nextPredEdge(){
		return next_pred_edge;
	};
	Edge* prevPredEdge(){
		return prev_pred_edge;
	};

};
