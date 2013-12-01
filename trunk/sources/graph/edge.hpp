#include "predicl.hpp"

class Edge
{
public:
	Edge *next, *prev;
	Node *prednode, succnode;	// Predecessor у дуги - это узел, из которого выходит дуга.
								// Successor у дуги - это узел, в который направлена дуга.
	Edge ();
	~Edge ();

};
