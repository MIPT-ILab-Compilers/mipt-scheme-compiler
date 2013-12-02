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
public:
	Edge *next, *prev;
	Edge *next_succ_edge, *prev_succ_edge, //для списка в вершине, из которого выходит дуга
		 *next_pred_edge, *prev_pred_edge; //для списка в вершине, в который входит дуга

	Node *pred_node, *succ_node;

	Edge ( Node *pred_node, Node *succ_node);
	~Edge () {};

};
