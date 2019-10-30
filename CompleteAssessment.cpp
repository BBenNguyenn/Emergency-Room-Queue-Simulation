// CLASS: CompleteAssessment
// REMARKS: What is the purpose of this class?
//	To represent an CompleteAssessment event in the ED.
//-----------------------------------------
#include <iostream>
#include <assert.h>

#include "CompleteAssessment.hpp"
#include "StartAssessment.hpp"
#include "Const.hpp"
#include "EDSimulation.hpp"

#include "StartBloodWork.hpp"
#include "StartXRay.hpp"
#include "StartTreatment.hpp"

namespace std
{

CompleteAssessment::CompleteAssessment(Patient *p, int t) : Event(p, t) {}
// CompleteAssessment::CompleteAssessment(){ }

// static choice maker
bool CompleteAssessment::chooseBloodWork = true;

//------------------------------------------------------
// process
//
// PURPOSE: process an CompleteAssessment as described in A2.
// PARAMETERS: none
// Returns: void
//------------------------------------------------------
void CompleteAssessment::process()
{
	Patient *nextPatient = NULL;

	EDSimulation::numAssessmentNurses++;
	assert(EDSimulation::numAssessmentNurses <= Const::numAssessmentNurses);

	// setup next patient in triageQueue
	nextPatient = dynamic_cast<Patient *>(EDSimulation::triageQueue->peek());

	if (nextPatient)
		EDSimulation::eventsList->enqueue(
			new StartAssessment(nextPatient, getEventTime()));

	cout << "Time: \t" << getEventTime()
		 << "\t Patient: " << getPatient()->getPatientID()
		 << " completes assessment, assigned priority of "
		 << getPatient()->getPriority();

	// a little long and verbose to make logic clear
	// this might seem like repeated code, but is needed for efficiency and clarity
	// thank you for your regards. :)
	if (getPatient()->needBloodWork && getPatient()->needXRay)
	{
		if (EDSimulation::numBloodTech > 0)
		{
			// setup bloodWork
			EDSimulation::eventsList->enqueue(new StartBloodWork(getPatient(), getEventTime()));
			EDSimulation::bloodQueue->enqueue(getPatient());
			cout << ", scheduled for blood work." << endl;
		}
		else if (EDSimulation::numXRayTech > 0)
		{
			// setup xray
			EDSimulation::eventsList->enqueue(new StartXRay(getPatient(), getEventTime()));
			EDSimulation::xrayQueue->enqueue(getPatient());
			cout << ", scheduled for X-ray." << endl;
		}
		else
		{
			// queue for bloodwork or x-ray arbitrarily
			if (chooseBloodWork)
			{
				// queue for bloodwork
				EDSimulation::bloodQueue->enqueue(getPatient());
				cout << ", queued for blood work." << endl;
				chooseBloodWork = false;
			}
			else
			{
				// queue for X-Ray
				EDSimulation::xrayQueue->enqueue(getPatient());
				cout << ", queued for X-ray." << endl;
				chooseBloodWork = true;
			}
		}
		// getPatient()->qStartTime = getEventTime();
	}
	else if (getPatient()->needBloodWork)
		EDSimulation::setupBloodWork(getPatient(), getEventTime());

	else if (getPatient()->needXRay)
		EDSimulation::setupXRay(getPatient(), getEventTime());

	else // everyone needs treatment
		EDSimulation::setupTreatment(getPatient(), getEventTime());

	getPatient()->qStartTime = getEventTime();

	EDSimulation::nurseStation->numPatients++;
	EDSimulation::nurseStation->serviceTime = EDSimulation::nurseStation->serviceTime + getPatient()->getAssessmentTime();
}

} /* namespace std */
