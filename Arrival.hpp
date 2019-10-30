// CLASS: Arrival
// REMARKS: What is the purpose of this class?
//	To represent an arrival event in the ED.
//-----------------------------------------
#ifndef ARRIVAL_HPP_
#define ARRIVAL_HPP_

#include "Event.hpp"
#include "ListItem.hpp"
namespace std
{

class Arrival : public Event
{
public:
	Arrival(Patient *p, int t);
	virtual void process(); //virtual to make clear
};

} /* namespace std */

#endif /* ARRIVAL_HPP_ */
