// CLASS: StartTreatment
// REMARKS: What is the purpose of this class?
//	To represent an StartTreatment event in the ED.
//-----------------------------------------
#ifndef STARTTREATMENT_HPP_
#define STARTTREATMENT_HPP_

#include "Event.hpp"
#include "ListItem.hpp"
namespace std
{

class StartTreatment : public Event
{
public:
	StartTreatment(Patient *p, int t);
	// Arrival();

	virtual void process(); //virtual to make clear
							// virtual void print();
};

} /* namespace std */

#endif /* STARTTREATMENT_HPP_ */
