// CLASS: EDSimulation
// REMARKS: What is the purpose of this class?
//	To represent and hold the actual ED, including all of its
//  data members like Stations and Queues.
//-----------------------------------------
#ifndef EDSIMULATION_HPP_
#define EDSIMULATION_HPP_

#include "Queue.hpp"
#include "PriorityQueue.hpp"
#include "Event.hpp"
#include "Station.hpp"

class EDSimulation
{
private:
	static Event *currentEvent;

public:
	static void initiate();
	static void printStats();

	//prevent repeated code
	static void setupBloodWork(Patient *p, int t);
	static void setupXRay(Patient *p, int t);
	static void setupTreatment(Patient *p, int t);

	static PriorityQueue *eventsList;

	static Queue *triageQueue;
	static PriorityQueue *bloodQueue;
	static PriorityQueue *xrayQueue;
	static PriorityQueue *treatmentQueue;

	static Station *nurseStation;
	static Station *bloodStation;
	static Station *xrayStation;
	static Station *treatmentStation;

	static int numAssessmentNurses;
	static int numBloodTech;
	static int numXRayTech;
	static int numDoctors;
};

#endif /* EDSIMULATION_HPP_ */
