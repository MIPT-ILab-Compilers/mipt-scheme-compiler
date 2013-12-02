/**
 * @file: node.cpp
 * Implementation of Node
 */
/**
 * Copyright (C) 2013  MIPT Scheme Compiler team
 */

#include "node.hpp"

Node::Node(int data)
{
	Node::data = data;
	Node::next = NULL;
	Node::prev = NULL;
	Node::succ_edge = NULL;
	Node::pred_edge = NULL;
}
