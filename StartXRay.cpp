// CLASS: StartXRay
// REMARKS: What is the purpose of this class?
//	To represent an StartXRay event in the ED.
//-----------------------------------------
#include <iostream>
#include <assert.h>
#include "StartXRay.hpp"
#include "CompleteXRay.hpp"
#include "Const.hpp"
#include "EDSimulation.hpp"
#include "FileHandler.hpp"

namespace std
{

StartXRay::StartXRay(Patient *p, int t) : Event(p, t) {}
// StartXRay::StartXRay(){ }

void StartXRay::process()
{
	EDSimulation::eventsList->enqueue(new CompleteXRay(
		getPatient(), getEventTime() + Const::XRayTime));

	EDSimulation::numXRayTech--;
	// assert(EDSimulation::numXRayTech >= 0);
	EDSimulation::xrayQueue->dequeue();

	//document wait time
	getPatient()->xrayWaitTime = getEventTime() - getPatient()->qStartTime;
	getPatient()->needXRay = false;

	cout << "Time: \t" << getEventTime()
		 << "\t Patient: " << getPatient()->getPatientID()
		 << " begins X-Ray." << endl;
}

// void StartXRay::print(){
// 	cout << "StartXRay with priority" << priority <<" ";
// }

} /* namespace std */
