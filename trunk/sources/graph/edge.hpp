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


private:
	Edge *next, *prev;
	Edge *next_succ_edge, *prev_succ_edge, //for the list in the node where the edge begins
		 *next_pred_edge, *prev_pred_edge; //for the list in the node where the edge ends

	Node *pred_node, *succ_node;
	void setNextSuccEdge( Edge* edge ){
		Edge::next_succ_edge = edge;
	};
	void setPrevSuccEdge( Edge* edge ){
		Edge::prev_succ_edge = edge;
	};
	void setNextPredEdge( Edge* edge ){
		Edge::next_pred_edge = edge;
	};
	void setPrevPredEdge( Edge* edge ){
		Edge::prev_pred_edge = edge;
	};
	void setNext( Edge* edge ){
		Edge::next = edge;
	}
	void setPrev( Edge* edge ){
		Edge::prev = edge;
	}
	void setPredNode( Node* node ){
		Edge::pred_node = node;
	}
	void setSuccNode( Node* node ){
		Edge::succ_node = node;
	}
	friend class Graph;
	//friend Edge* Graph::addEdge ( Node *prednode, Node *succnode);
	//friend void Graph::rmEdge ( Edge *edge);
public:
	Edge ( Node *pred_node, Node *succ_node);		//friend to Node::setSucc(), Node::setPred() needed here
	~Edge () {};
	Edge* getNextSuccEdge(){
		return next_succ_edge;
	};
	Edge* getPrevSuccEdge(){
		return prev_succ_edge;
	};
	Edge* getNextPredEdge(){
		return next_pred_edge;
	};
	Edge* getPrevPredEdge(){
		return prev_pred_edge;
	};
	Edge* getNext(){
		return next;
	}
	Edge* getPrev(){
		return prev;
	}
	Node* getPredNode(){
		return pred_node;
	}
	Node* getSuccNode(){
		return succ_node;
	}
};
