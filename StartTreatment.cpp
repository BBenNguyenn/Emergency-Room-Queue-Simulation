// CLASS: StartTreatment
// REMARKS: What is the purpose of this class?
//	To represent an StartTreatment event in the ED.
//-----------------------------------------
#include <iostream>
#include <assert.h>
#include "StartTreatment.hpp"
#include "Discharge.hpp"
#include "Const.hpp"
#include "EDSimulation.hpp"
#include "FileHandler.hpp"

namespace std
{

StartTreatment::StartTreatment(Patient *p, int t) : Event(p, t) {}
// StartTreatment::StartTreatment(){ }

void StartTreatment::process()
{
	EDSimulation::eventsList->enqueue(new Discharge(
		getPatient(), getEventTime() + getPatient()->getTreatmentTime()));

	// cout << EDSimulation::numDoctors << endl;
	EDSimulation::numDoctors--;
	// cout << EDSimulation::numDoctors << endl;

	assert(EDSimulation::numDoctors >= 0);
	EDSimulation::treatmentQueue->dequeue();

	getPatient()->treatWaitTime = getEventTime() - getPatient()->qStartTime;

	cout << "Time: \t" << getEventTime()
		 << "\t Patient: " << getPatient()->getPatientID()
		 << " begins treatment of length "
		 << getPatient()->getTreatmentTime()
		 << "." << endl;
}

// void StartTreatment::print(){
// 	cout << "StartTreatment with priority" << priority <<" ";
// }

} /* namespace std */
