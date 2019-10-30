// CLASS: CompleteXRay
// REMARKS: What is the purpose of this class?
//	To represent an CompleteXRay event in the ED.
//-----------------------------------------
#ifndef COMPLETEXRAY_HPP_
#define COMPLETEXRAY_HPP_

#include "Event.hpp"
#include "ListItem.hpp"
namespace std
{

class CompleteXRay : public Event
{
public:
	CompleteXRay(Patient *p, int t);
	virtual void process(); //virtual to make clear
};

} /* namespace std */

#endif /* COMPLETEXRAY_HPP_ */
