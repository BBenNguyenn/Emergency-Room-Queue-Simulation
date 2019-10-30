// CLASS: StartAssessment
// REMARKS: What is the purpose of this class?
//	To represent an StartAssessment event in the ED.
//-----------------------------------------
#ifndef STARTASSESSMENT_HPP_
#define STARTASSESSMENT_HPP_

#include "Event.hpp"
#include "ListItem.hpp"
namespace std
{

class StartAssessment : public Event
{
public:
	StartAssessment(Patient *p, int t);
	// Arrival();

	virtual void process(); //virtual to make clear
							// virtual void print();
};

} /* namespace std */

#endif /* STARTASSESSMENT_HPP_ */
