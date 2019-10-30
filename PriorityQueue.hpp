// CLASS: PriorityQueue
// REMARKS: What is the purpose of this class?
//	Extension on our Queue class which adds functionality.
//-----------------------------------------
#ifndef PRIORITYQUEUE_H_
#define PRIORITYQUEUE_H_

#include "Queue.hpp"
#include "Node.hpp"

using namespace std;

class Queue;

class PriorityQueue : public Queue
{
public:
	PriorityQueue();
	virtual ~PriorityQueue();

	virtual void enqueue(ListItem *newItem);
	void enqueueFront(ListItem *newItem);
};

#endif /* PRIORITYQUEUE_HPP_ */
