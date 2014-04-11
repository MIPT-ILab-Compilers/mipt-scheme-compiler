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
private:
	void setPred( Edge* edge ){
		Node::first_pred_edge = edge;
	};
	void setSucc( Edge* edge ){
		Node::first_succ_edge = edge;
	};

	friend class Edge;
	//friend Edge::Edge ( Node *pred_node, Node *succ_node);

	void setNext( Node* node ){
		Node::next = node;
	};
	void setPrev( Node* node ){
		Node::prev = node;
	};
	friend class Graph;
	//friend Node* Graph::addNode ();
	//friend void Graph::rmNode ( Node *node);
	//friend void Graph::rmEdge ( Edge *edge);

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
