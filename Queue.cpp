// CLASS: Queue
// REMARKS: What is the purpose of this class?
//	Linked list queue data structure.
//-----------------------------------------
#include <iostream> // for definition of NULL
#include "Queue.hpp"
#include "Node.hpp"
//we DO NOT need to #include ListItem.h here because we're not
//using any of its methods or defining any instance.
//we DO need to include Node because we're using one of
//its methods (top's print!) and we are creating a new node

using namespace std;
class ListItem;
//constructor
Queue::Queue() : front(NULL), end(NULL) {}
//destructor
Queue::~Queue() {}

void Queue::print()
{
	cout << "[ ";
	if (!isEmpty())
		front->print();
	cout << "]" << endl;
}

void Queue::enqueue(ListItem *newItem)
{

	Node *newNode = new Node(newItem, NULL);

	if (front == NULL && end == NULL)
	{
		front = newNode;
		end = newNode;
	}
	else
	{
		end->setLink(newNode);
		end = newNode;
	}

	// 	front = new Node(newItem, front);
} // end enqueue

ListItem *Queue::dequeue()
{
	ListItem *returnItem = NULL;
	Node *newFront = NULL;

	if (!isEmpty())
	{

		returnItem = front->getItem();

		if (front != end) //normal case
			newFront = front->getLink();
		else
		{ //last node edge case
			newFront = NULL;
			end = NULL;
		}

		delete front;
		front = newFront;
	}

	// if (front)
	// {
	// 	if (Event *e = dynamic_cast<Event *>(front->getItem()))
	// 	{

	// 		// old was safely casted to NewType
	// 		// e->doSomething();
	// 		cout<<"REM ";
	// 		print();
	// 	}
	// }
	// else
	// 	cout << "NULL FRONT" << endl;

	return returnItem;
} // end dequeue

ListItem *Queue::peek()
{
	ListItem *theItem = NULL;

	if (front)
		theItem = front->getItem();

	return theItem;
}

bool Queue::isEmpty() { return front == NULL; }