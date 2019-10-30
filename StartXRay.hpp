// CLASS: StartXRay
// REMARKS: What is the purpose of this class?
//	To represent an StartXRay event in the ED.
//-----------------------------------------
#ifndef STARTXRAY_HPP_
#define STARTXRAY_HPP_

#include "Event.hpp"
#include "ListItem.hpp"
namespace std
{

class StartXRay : public Event
{
public:
	StartXRay(Patient *p, int t);
	// Arrival();

	virtual void process(); //virtual to make clear
};

} /* namespace std */

#endif /* STARTXRAY_HPP_ */
