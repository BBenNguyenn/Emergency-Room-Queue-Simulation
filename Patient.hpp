// CLASS: Patient
// REMARKS: What is the purpose of this class?
//	To represent data about a Patient.
//-----------------------------------------
#ifndef PATIENT_H
#define PATIENT_H
#include "ListItem.hpp"
//we require listitem because we're inheriting from it
using namespace std;

class Patient : public ListItem
{
private:
	static int nextID;
	int patientID;
	int arrivalTime;
	int assessmentTime;
	//	int priority;

	int treatmentTime;

public:
	Patient(int ar, int as, int pr, bool bw, bool xr, int tr);

	int qStartTime;
	int nurseWaitTime;
	int bloodWaitTime;
	int xrayWaitTime;
	int treatWaitTime;
	bool needBloodWork;
	bool needXRay;

	void print();
	int getPatientID();
	int getArrivalTime();
	int getAssessmentTime();
	virtual int getPriority(); // virtual just for clarity
	// bool getNeedBloodWork();
	// bool getNeedXRay();
	int getTreatmentTime();
};
#endif
