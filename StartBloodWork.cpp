// CLASS: StartBloodWork
// REMARKS: What is the purpose of this class?
//	To represent an StartBloodWork event in the ED.
//-----------------------------------------
#include <iostream>
#include <assert.h>

#include "StartBloodWork.hpp"
#include "CompleteBloodWork.hpp"
#include "Const.hpp"
#include "EDSimulation.hpp"
#include "FileHandler.hpp"

namespace std
{

StartBloodWork::StartBloodWork(Patient *p, int t) : Event(p, t) {}
// StartBloodWork::StartBloodWork(Patient *p, int t) : Event(p, t) {}
// StartBloodWork::StartBloodWork(){ }

void StartBloodWork::process()
{

	EDSimulation::eventsList->enqueue(new CompleteBloodWork(
		getPatient(), getEventTime() + Const::bloodWorkTime));

	EDSimulation::numBloodTech--;
	assert(EDSimulation::numBloodTech >= 0);
	EDSimulation::bloodQueue->dequeue();

	//document wait time
	getPatient()->bloodWaitTime = getEventTime() - getPatient()->qStartTime;
	getPatient()->needBloodWork = false;

	cout << "Time: \t" << getEventTime()
		 << "\t Patient: " << getPatient()->getPatientID()
		 << " begins blood work." << endl;
}

// void StartBloodWork::print(){
// 	cout << "StartBloodWork with priority" << priority <<" ";
// }

} /* namespace std */
