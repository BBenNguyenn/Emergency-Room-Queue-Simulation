// CLASS: Event
// REMARKS: What is the purpose of this class?
//	To represent the abstract object Event which is
//  inherited by all events in the simulation
//-----------------------------------------
#ifndef EVENT_HPP_
#define EVENT_HPP_

#include "ListItem.hpp"
#include "Patient.hpp"

namespace std
{

class Event : public ListItem
{
private:
	Patient *patient;

public:
	Event(Patient *p, int t);
	virtual ~Event();
	virtual void process() = 0;
	virtual void print();

	int getEventTime();
	Patient *getPatient();
};

} /* namespace std */

#endif /* EVENT_HPP_ */
