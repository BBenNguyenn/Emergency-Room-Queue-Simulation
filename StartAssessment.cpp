// CLASS: StartAssessment
// REMARKS: What is the purpose of this class?
//	To represent an StartAssessment event in the ED.
//-----------------------------------------
#include <iostream>
#include <assert.h>
#include "StartAssessment.hpp"
#include "CompleteAssessment.hpp"
#include "Const.hpp"
#include "EDSimulation.hpp"
#include "FileHandler.hpp"

namespace std
{

StartAssessment::StartAssessment(Patient *p, int t) : Event(p, t) {}
// StartAssessment::StartAssessment(){ }

void StartAssessment::process()
{
	EDSimulation::eventsList->enqueue(new CompleteAssessment(
		getPatient(), getEventTime() + getPatient()->getAssessmentTime()));

	EDSimulation::numAssessmentNurses--;
	assert(EDSimulation::numAssessmentNurses >= 0);

	EDSimulation::triageQueue->dequeue();

	//document wait time
	getPatient()->nurseWaitTime = getEventTime() - getPatient()->getArrivalTime();

	cout << "Time: \t" << getEventTime()
		 << "\t Patient: " << getPatient()->getPatientID()
		 << " begins assessment of length "
		 << getPatient()->getAssessmentTime()
		 << "." << endl;
}

} /* namespace std */
