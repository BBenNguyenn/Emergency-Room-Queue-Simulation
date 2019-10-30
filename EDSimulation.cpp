// CLASS: EDSimulation
// REMARKS: What is the purpose of this class?
//	To represent and hold the actual ED, including all of its
//  data members like Stations and Queues.
//-----------------------------------------
#include <iostream> // for definition of NULL
#include "Const.hpp"
#include "EDSimulation.hpp"

#include "Arrival.hpp" //using constructor
#include "Patient.hpp"
#include "FileHandler.hpp"

#include "StartBloodWork.hpp"
#include "StartXRay.hpp"
#include "StartTreatment.hpp"

//private pointer
Event *EDSimulation::currentEvent = NULL;
//static simulation variables
PriorityQueue *EDSimulation::eventsList = new PriorityQueue();
Queue *EDSimulation::triageQueue = new Queue();

PriorityQueue *EDSimulation::bloodQueue = new PriorityQueue();
PriorityQueue *EDSimulation::xrayQueue = new PriorityQueue();
PriorityQueue *EDSimulation::treatmentQueue = new PriorityQueue();

Station *EDSimulation::nurseStation = new Station("Assessment");
Station *EDSimulation::bloodStation = new Station("Blood Work");
Station *EDSimulation::xrayStation = new Station("     X-Ray");
Station *EDSimulation::treatmentStation = new Station(" Treatment");

// setting parameters to manipulate from A2Const
int EDSimulation::numAssessmentNurses = Const::numAssessmentNurses;
int EDSimulation::numBloodTech = Const::numBloodTech;
int EDSimulation::numXRayTech = Const::numXRayTech;
int EDSimulation::numDoctors = Const::numDoctors;

//------------------------------------------------------
// initiate
//
// PURPOSE:
// Gets the first patient to process first arrival and keep processing events as long
// as there are still events ie as long as eventsList is not empty
// PARAMETERS: none
// Returns: void
//------------------------------------------------------
void EDSimulation::initiate()
{
	Patient *firstPatient = FileHandler::obtainNextPatient();
	if (firstPatient)
		eventsList->enqueue(new Arrival(firstPatient, firstPatient->getArrivalTime()));

	// dequeue event from events list and process it until list is empty
	while (!eventsList->isEmpty())
	{
		// eventsList->print();
		currentEvent = dynamic_cast<Event *>(eventsList->dequeue());
		currentEvent->process();
		delete currentEvent; // calling destructor
	}
} // end initiate

//------------------------------------------------------
// setupBloodWork
//
// PURPOSE: checks availability sets up eventList and queue
// PARAMETERS: patient pointer and int event time.
// Returns: void
//------------------------------------------------------
void EDSimulation::setupBloodWork(Patient *p, int t)
{
	if (numBloodTech > 0)
	{
		// setup bloodWork
		eventsList->enqueueFront(new StartBloodWork(p, t));
		cout << ", scheduled for blood work." << endl;
	}
	else
		cout << ", queued for blood work." << endl;

	bloodQueue->enqueue(p);
}

//------------------------------------------------------
// setupXRay
//
// PURPOSE: checks availability sets up eventList and queue
// PARAMETERS: patient pointer and int event time.
// Returns: void
//------------------------------------------------------
void EDSimulation::setupXRay(Patient *p, int t)
{
	if (numXRayTech > 0)
	{
		// setup bloodWork
		eventsList->enqueue(new StartXRay(p, t));
		cout << ", scheduled for X-ray." << endl;
	}
	else
		cout << ", queued for X-ray." << endl;

	xrayQueue->enqueue(p);
}

//------------------------------------------------------
// setupTreatment
//
// PURPOSE: checks availability sets up eventList and queue
// PARAMETERS: patient pointer and int event time.
// Returns: void
//------------------------------------------------------
void EDSimulation::setupTreatment(Patient *p, int t)
{
	if (numDoctors > 0)
	{
		// setup bloodWork
		eventsList->enqueue(new StartTreatment(p, t));
		cout << ", scheduled for treatment." << endl;
	}
	else
		cout << ", queued for treatment." << endl;

	treatmentQueue->enqueue(p);
}

//------------------------------------------------------
// printStats
//
// PURPOSE: Prints final stats
// PARAMETERS: none
// Returns: void
//------------------------------------------------------
void EDSimulation::printStats()
{
	cout << "Final Summary:" << endl;
	cout << "--------------------------------------" << endl;
	nurseStation->printStationStats();
	bloodStation->printStationStats();
	xrayStation->printStationStats();
	treatmentStation->printStationStats();
} // end printStats
