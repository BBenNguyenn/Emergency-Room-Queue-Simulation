// CLASS: Queue
// REMARKS: What is the purpose of this class?
//	Linked list queue data structure.
//-----------------------------------------
#ifndef QUEUE_H
#define QUEUE_H
#include "ListItem.hpp"

//#include "Node.h"
//we do NOT need to include node here - we're not making an instance
//or using any of its methods; we just have a pointer to node so
//C++ must recognize the type at this point...we use a forward
//reference
using namespace std;
class Node; //forward reference for node so it knows the symbol

class Queue
{
protected:
	Node *front;
	Node *end;

public:
	Queue(); //constructor
	virtual ~Queue();

	void print();
	virtual void enqueue(ListItem *newItem);
	ListItem *dequeue();
	ListItem *peek();
	bool isEmpty();
};
#endif
