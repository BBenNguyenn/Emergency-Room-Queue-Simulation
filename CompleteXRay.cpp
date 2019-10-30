// CLASS: CompleteXRay
// REMARKS: What is the purpose of this class?
//	To represent an CompleteXRay event in the ED.
//-----------------------------------------
#include <iostream>
#include <assert.h>

#include "CompleteXRay.hpp"
#include "Const.hpp"
#include "EDSimulation.hpp"

#include "StartXRay.hpp"
#include "StartBloodWork.hpp"
#include "StartTreatment.hpp"

namespace std
{

CompleteXRay::CompleteXRay(Patient *p, int t) : Event(p, t) {}

//------------------------------------------------------
// process
//
// PURPOSE: process an CompleteXRay as described in A2.
// PARAMETERS: none
// Returns: void
//------------------------------------------------------
void CompleteXRay::process()
{
	Patient *nextPatient = NULL;

	cout << "Time: \t" << getEventTime()
		 << "\t Patient: " << getPatient()->getPatientID()
		 << " completes X-Ray";

	if (getPatient()->needBloodWork)
		EDSimulation::setupBloodWork(getPatient(), getEventTime());
	else
		EDSimulation::setupTreatment(getPatient(), getEventTime());

	getPatient()->qStartTime = getEventTime();

	EDSimulation::numXRayTech++;
	assert(EDSimulation::numXRayTech <= Const::numXRayTech);

	// setup next patient in xrayQueue
	nextPatient = dynamic_cast<Patient *>(EDSimulation::xrayQueue->peek());

	if (nextPatient)
		EDSimulation::eventsList->enqueue(
			new StartXRay(nextPatient, getEventTime()));

	EDSimulation::xrayStation->numPatients++;
	EDSimulation::xrayStation->serviceTime = EDSimulation::xrayStation->serviceTime + Const::XRayTime;
}

} /* namespace std */
