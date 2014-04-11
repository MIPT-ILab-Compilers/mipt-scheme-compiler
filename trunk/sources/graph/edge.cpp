/**
 * @file: edge.cpp
 * Implementation of Graph
 */
/**
 * Copyright (C) 2013  MIPT Scheme Compiler team
 */

#include "edge.hpp"

Edge::Edge(Node *in_pred_node, Node *in_succ_node)
{
	if ( (in_pred_node <= 0)||(in_succ_node <= 0) )
			std::cout << "Wrong arguments of Edge constructor";
			//throw some exception here?
	else
	{
		Edge::next = NULL;
		Edge::prev = NULL;
		Edge::pred_node = in_pred_node;
		Edge::succ_node = in_succ_node;

		if ( Edge::succ_node->getPred() == NULL )
		{
			Edge::succ_node->setPred( this );
			Edge::next_pred_edge = NULL;
			Edge::prev_pred_edge = NULL;
		}
		else
		{
			Edge::next_pred_edge = succ_node->getPred();
			Edge::prev_pred_edge = NULL;
			Edge::succ_node->getPred()->prev_pred_edge = this;
			Edge::succ_node->setPred( this );
		}

		if ( Edge::pred_node->getSucc() == NULL )
		{
			Edge::pred_node->setSucc( this );
			Edge::next_succ_edge = NULL;
			Edge::prev_succ_edge = NULL;
		}
		else
		{
			Edge::next_succ_edge = pred_node->getSucc();
			Edge::prev_succ_edge = NULL;
			Edge::pred_node->getSucc()->prev_succ_edge = this;
			Edge::pred_node->setSucc( this );
		}
	}
}
