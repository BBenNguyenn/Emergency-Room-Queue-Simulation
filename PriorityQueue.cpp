// CLASS: PriorityQueue
// REMARKS: What is the purpose of this class?
//	Extension on our Queue class which adds functionality
//-----------------------------------------
#include <iostream> // for definition of NULL
#include "PriorityQueue.hpp"

#include "Event.hpp"

using namespace std;

//constructor
PriorityQueue::PriorityQueue() : Queue() {}
//destructor
PriorityQueue::~PriorityQueue() {}

void PriorityQueue::enqueueFront(ListItem *newItem)
{
	Node *curr = NULL;
	Node *prev = NULL;
	// Node *newNode = new Node(newItem, NULL);

	if (front == NULL && end == NULL)
	{ // if list is empty
		Queue::enqueue(newItem);
		// front = newNode;
		// end = newNode;
	}
	else
	{
		curr = front;
		while (curr != NULL && curr->getItem()->getPriority() < newItem->getPriority())
		{
			prev = curr;
			curr = curr->getLink();
		}

		if (curr == NULL)
		{ // last node edge case
			prev->setLink(new Node(newItem, NULL));
			end = prev->getLink();
		}
		else if (prev != NULL) // normal case
			prev->setLink(new Node(newItem, curr));

		else if (curr == front)
		{ // first node edge case
			prev = new Node(newItem, front);
			front = prev;
		}
	}
}

void PriorityQueue::enqueue(ListItem *newItem)
{
	Node *curr = NULL;
	Node *prev = NULL;
	// Node *newNode = new Node(newItem, NULL);

	if (front == NULL && end == NULL)
	{ // if list is empty
		Queue::enqueue(newItem);
		// front = newNode;
		// end = newNode;
	}
	else
	{
		curr = front;
		while (curr != NULL && curr->getItem()->getPriority() <= newItem->getPriority())
		{
			prev = curr;
			curr = curr->getLink();
		}

		if (curr == NULL)
		{ // last node edge case
			prev->setLink(new Node(newItem, NULL));
			end = prev->getLink();
		}
		else if (prev != NULL) // normal case
			prev->setLink(new Node(newItem, curr));

		else if (curr == front)
		{ // first node edge case
			prev = new Node(newItem, front);
			front = prev;
		}
	}
}
