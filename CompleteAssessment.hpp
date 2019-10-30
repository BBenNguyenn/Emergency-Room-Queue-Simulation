// CLASS: CompleteAssessment
// REMARKS: What is the purpose of this class?
//	To represent an CompleteAssessment event in the ED.
//-----------------------------------------
#ifndef COMPLETEASSESSMENT_HPP_
#define COMPLETEASSESSMENT_HPP_

#include "Event.hpp"
#include "ListItem.hpp"
namespace std
{

class CompleteAssessment : public Event
{
private:
	static bool chooseBloodWork;

public:
	CompleteAssessment(Patient *p, int t);
	virtual void process(); //virtual to make clear
};

} /* namespace std */

#endif /* CompleteASSESSMENT_HPP_ */
