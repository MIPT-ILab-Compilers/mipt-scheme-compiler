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
	Edge *next_succ_edge, *prev_succ_edge, //для списка в вершине, из которого выходит дуга
		 *next_pred_edge, *prev_pred_edge; //для списка в вершине, в который входит дуга

	Node *pred_node, *succ_node;
public:
	Edge ( Node *pred_node, Node *succ_node);
	~Edge () {};
	Edge* incSuccEdge(){
		return next_succ_edge;
	};
	Edge* decSuccEdge(){
		return prev_succ_edge;
	};
	Edge* incPredEdge(){
		return next_pred_edge;
	};
	Edge* decPredEdge(){
		return prev_pred_edge;
	};

};
