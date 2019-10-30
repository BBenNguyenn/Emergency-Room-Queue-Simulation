// CLASS: Discharge
// REMARKS: What is the purpose of this class?
//	To represent an Discharge event in the ED.
//-----------------------------------------
#ifndef DISCHARGE_HPP_
#define DISCHARGE_HPP_

#include "Event.hpp"
#include "ListItem.hpp"
namespace std
{

class Discharge : public Event
{
public:
	Discharge(Patient *p, int t);
	virtual void process(); //virtual to make clear
};

} /* namespace std */

#endif /* DISCHARGE_HPP_ */
