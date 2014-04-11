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
private:
	int data;
	Node *next, *prev;
	Edge *first_pred_edge, *first_succ_edge;		// Predecessors - edges "to" here
										// Successors - edges "from" here
public:									//to be private
	void setPred( Edge* edge ){
		Node::first_pred_edge = edge;
	};
	void setSucc( Edge* edge ){
		Node::first_succ_edge = edge;
	};
	void setNext( Node* node ){
		Node::next = node;
	};
	void setPrev( Node* node ){
		Node::prev = node;
	};

public:
	Node ( int data);
	~Node () {};
	Edge* getPred()
	{
		return first_pred_edge;
	};
	Edge* getSucc(){
		return first_succ_edge;
	}
	Node* getNext()
	{
		return next;
	};
	Node* getPrev(){
		return prev;
	}
	int getData(){
		return data;
	}

};
