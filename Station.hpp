// CLASS: Station
// REMARKS: What is the purpose of this class?
//	To represent a specific department/station in the ED
//  which holds stats for a station.
//-----------------------------------------
#ifndef STATION_HPP_
#define STATION_HPP_

#include <string>

namespace std
{

class Station
{
private:
	string name;

public:
	Station(string n);
	int numPatients;
	int serviceTime;
	int waitTime;

	void printStationStats();
};

} /* namespace std */

#endif /* STATION_HPP_ */
