#include "predicl.hpp"

class Node
{
public:
	int data;
	Node *next, *prev;
	Edge *prededge, *succedge;		// Predecessor для вершин - множество дуг, которые направлены
									// в вершину
									// Successor - соответственно множество дуг, из вершины
	Node ( int data);
	~Node ();

};
