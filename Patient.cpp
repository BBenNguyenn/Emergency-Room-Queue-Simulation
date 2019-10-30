// CLASS: Patient
// REMARKS: What is the purpose of this class?
//	To represent data about a Patient.
//-----------------------------------------
#include <iostream>
#include <string>
#include <sstream>
#include "Patient.hpp"
using namespace std;

//class ListItem;
int Patient::nextID = 0;
//Patient cosntructor
Patient::Patient(int ar, int as, int pr, bool bw, bool xr, int tr)
	: arrivalTime(ar),
	  assessmentTime(as),
	  ListItem(pr),
	  needBloodWork(bw),
	  needXRay(xr),
	  treatmentTime(tr),

	  qStartTime(0),
	  nurseWaitTime(0),
	  bloodWaitTime(0),
	  xrayWaitTime(0),
	  treatWaitTime(0)
{
	nextID++;
	patientID = nextID;
}

void Patient::print() { cout << "*" << patientID << "* "; }

//getters, note we do not need setters
int Patient::getPatientID() { return patientID; }
int Patient::getArrivalTime() { return arrivalTime; }
int Patient::getAssessmentTime() { return assessmentTime; }
int Patient::getPriority() { return priority; }
// bool Patient::getNeedBloodWork(){ return needBloodWork; }
// bool Patient::getNeedXRay(){ return needXRay; }
int Patient::getTreatmentTime() { return treatmentTime; }
