// CLASS: Station
// REMARKS: What is the purpose of this class?
//	To represent a specific department/station in the ED
//  which holds stats for a station.
//-----------------------------------------
#include <iostream>
#include "Station.hpp"

namespace std
{

Station::Station(string n) : name(n), numPatients(0), serviceTime(0), waitTime(0) {}

void Station::printStationStats()
{
	float avgServiceTime = (float)serviceTime / (float)numPatients;
	float avgWaitTime = (float)waitTime / (float)numPatients;

	cout << name << " \t" << numPatients
		 << " \t" << serviceTime << " \t" << avgServiceTime
		 << " \t" << waitTime << " \t" << avgWaitTime << endl;
}

} /* namespace std */
