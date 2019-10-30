// CLASS: Event
// REMARKS: What is the purpose of this class?
//	To represent the abstract object Event which is
//  inherited by all events in the simulation
//-----------------------------------------
#include <iostream>
#include "Event.hpp"

namespace std
{

//constructor
Event::Event(Patient *p, int t) : patient(p), ListItem(t) {}
//destructor for all events
Event::~Event() {}

} /* namespace std */

void Event::process() {}

// TESTING PURPOSES ONLY
void Event::print() { cout << "(" << getEventTime() << " " << getPatient()->getPatientID() << "), "; }

// GETTERS FOR EVENT
int Event::getEventTime() { return priority; }
Patient *Event::getPatient() { return patient; }