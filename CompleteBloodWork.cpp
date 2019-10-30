// CLASS: CompleteBloodWork
// REMARKS: What is the purpose of this class?
//	To represent an CompleteBloodWork event in the ED.
//-----------------------------------------
#include <iostream>
#include <assert.h>

#include "CompleteBloodWork.hpp"
#include "Const.hpp"
#include "EDSimulation.hpp"

#include "StartXRay.hpp"
#include "StartBloodWork.hpp"
#include "StartTreatment.hpp"

namespace std
{

CompleteBloodWork::CompleteBloodWork(Patient *p, int t) : Event(p, t) {}

//------------------------------------------------------
// process
//
// PURPOSE: process an CompleteBloodWork as described in A2.
// PARAMETERS: none
// Returns: void
//------------------------------------------------------
void CompleteBloodWork::process()
{
	Patient *nextPatient = NULL;

	cout << "Time: \t" << getEventTime()
		 << "\t Patient: " << getPatient()->getPatientID()
		 << " completes blood work";

	if (getPatient()->needXRay)
		EDSimulation::setupXRay(getPatient(), getEventTime());
	else
		EDSimulation::setupTreatment(getPatient(), getEventTime());

	getPatient()->qStartTime = getEventTime();

	EDSimulation::numBloodTech++;
	assert(EDSimulation::numBloodTech <= Const::numBloodTech);

	// setup next patient in bloodQueue
	nextPatient = dynamic_cast<Patient *>(EDSimulation::bloodQueue->peek());

	if (nextPatient)
		EDSimulation::eventsList->enqueue(
			new StartBloodWork(nextPatient, getEventTime()));

	EDSimulation::bloodStation->numPatients++;
	EDSimulation::bloodStation->serviceTime = EDSimulation::bloodStation->serviceTime + Const::bloodWorkTime;
}

} /* namespace std */
