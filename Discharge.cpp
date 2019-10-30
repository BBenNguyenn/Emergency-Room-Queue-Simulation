// CLASS: Discharge
// REMARKS: What is the purpose of this class?
//	To represent an Discharge event in the ED.
//-----------------------------------------
#include <iostream>
#include <assert.h>

#include "Discharge.hpp"
#include "Const.hpp"
#include "EDSimulation.hpp"

#include "StartTreatment.hpp"

namespace std
{

Discharge::Discharge(Patient *p, int t) : Event(p, t) {}

//------------------------------------------------------
// process
//
// PURPOSE: process an Discharge as described in A2.
// PARAMETERS: none
// Returns: void
//------------------------------------------------------
void Discharge::process()
{
	Patient *nextPatient = NULL;

	cout << "Time: \t" << getEventTime()
		 << "\t Patient: " << getPatient()->getPatientID()
		 << " discharged at time  "
		 << getEventTime()
		 << "." << endl;

	EDSimulation::numDoctors++;
	assert(EDSimulation::numDoctors <= Const::numDoctors);

	// setup next patient in xrayQueue
	nextPatient = dynamic_cast<Patient *>(EDSimulation::treatmentQueue->peek());

	if (nextPatient)
		EDSimulation::eventsList->enqueueFront(
			new StartTreatment(nextPatient, getEventTime()));

	EDSimulation::treatmentStation->numPatients++;
	EDSimulation::treatmentStation->serviceTime = EDSimulation::treatmentStation->serviceTime + getPatient()->getTreatmentTime();

	EDSimulation::nurseStation->waitTime = EDSimulation::nurseStation->waitTime + getPatient()->nurseWaitTime;
	EDSimulation::bloodStation->waitTime = EDSimulation::bloodStation->waitTime + getPatient()->bloodWaitTime;
	EDSimulation::xrayStation->waitTime = EDSimulation::xrayStation->waitTime + getPatient()->xrayWaitTime;
	EDSimulation::treatmentStation->waitTime = EDSimulation::treatmentStation->waitTime + getPatient()->treatWaitTime;

	// calling patient destructor
	delete getPatient();
}

} /* namespace std */
