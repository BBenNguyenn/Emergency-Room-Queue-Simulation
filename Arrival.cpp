// CLASS: Arrival
// REMARKS: What is the purpose of this class?
//	To represent an arrival event in the ED.
//-----------------------------------------
#include <iostream>
#include "Arrival.hpp"
#include "Const.hpp"
#include "EDSimulation.hpp"
#include "FileHandler.hpp"
#include "StartAssessment.hpp"

namespace std
{

Arrival::Arrival(Patient *p, int t) : Event(p, t) {}

//------------------------------------------------------
// process
//
// PURPOSE: process an Arrival as described in A2.
// PARAMETERS: none
// Returns: void
//------------------------------------------------------
void Arrival::process()
{
	Patient *nextPatient = NULL;

	if (EDSimulation::numAssessmentNurses > 0)
	{
		EDSimulation::eventsList->enqueue(new StartAssessment(getPatient(), getEventTime()));

		cout << "Time: \t" << getEventTime()
			 << "\t Patient: " << getPatient()->getPatientID()
			 << " arrives in ED. Assessment nurse is free; (patient assessment begins)."
			 << endl;
	}
	else
	{
		cout << "Time: \t" << getEventTime()
			 << "\t Patient: " << getPatient()->getPatientID()
			 << " arrives in ED. Assessment nurses busy; (patient is queued)."
			 << endl;
	}

	EDSimulation::triageQueue->enqueue(getPatient());

	nextPatient = FileHandler::obtainNextPatient();
	if (nextPatient)
		EDSimulation::eventsList->enqueue(
			new Arrival(nextPatient, nextPatient->getArrivalTime()));

	//else input file done, no more arrivals
}

} /* namespace std */
