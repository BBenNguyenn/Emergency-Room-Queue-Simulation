// CLASS: CompleteBloodWork
// REMARKS: What is the purpose of this class?
//	To represent an CompleteBloodWork event in the ED.
//-----------------------------------------
#ifndef COMPLETEBLOODWORK_HPP_
#define COMPLETEBLOODWORK_HPP_

#include "Event.hpp"
#include "ListItem.hpp"
namespace std
{

class CompleteBloodWork : public Event
{
public:
	CompleteBloodWork(Patient *p, int t);
	virtual void process(); //virtual to make clear
};

} /* namespace std */

#endif /* COMPLETEBLOODWORK_HPP_ */
