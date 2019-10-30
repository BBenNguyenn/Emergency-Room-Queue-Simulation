// CLASS: StartBloodWork
// REMARKS: What is the purpose of this class?
//	To represent an StartBloodWork event in the ED.
//-----------------------------------------
#ifndef STARTBLOODWORK_HPP_
#define STARTBLOODWORK_HPP_

#include "Event.hpp"
#include "ListItem.hpp"
namespace std
{

class StartBloodWork : public Event
{
public:
	StartBloodWork(Patient *p, int t);
	// StartBloodWork(Patient *p, int t);
	// Arrival();

	virtual void process(); //virtual to make clear
							// virtual void print();
};

} /* namespace std */

#endif /* STARTBLOODWORK_HPP_ */
