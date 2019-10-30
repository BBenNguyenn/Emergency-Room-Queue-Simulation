// CLASS: FileHandler
// REMARKS: What is the purpose of this class?
//	To hold any functions and data which processes the file.
//-----------------------------------------
#include <iostream>
#include <string>
#include <fstream>
#include <sstream>

#include "FileHandler.hpp"
#include "Patient.hpp"

using namespace std;

ifstream FileHandler::inFile; // static file member

//------------------------------------------------------
// openFile
//
// PURPOSE: opens the file to the variable inFile.
// PARAMETERS: char filename (string)
// Returns: void
//------------------------------------------------------
void FileHandler::openFile(char *filename)
{
    inFile.open(filename);
} // end openFile

//------------------------------------------------------
// obtainNextPatient
//
// PURPOSE: gets next patient in the file.
// PARAMETERS: none
// Returns: the next patient in the file, skipping spaces and comments
//------------------------------------------------------
Patient *FileHandler::obtainNextPatient()
{
    Patient *newPatient = NULL;

    //variables to create patient with
    string firstWord;
    int arrivalTime;
    int assessmentTime;
    int priority;
    string stationNeeds;
    int treatmentTime;

    if (inFile >> firstWord)
    {
        if (!(firstWord.find("#") != std::string::npos))
        {

            inFile >> assessmentTime >> priority >> stationNeeds >> treatmentTime;
            stringstream convert(firstWord);
            convert >> arrivalTime;

            newPatient = new Patient(
                arrivalTime,
                assessmentTime,
                priority,
                (stationNeeds.find("B") != std::string::npos),
                (stationNeeds.find("X") != std::string::npos),
                treatmentTime);
        }
        else
        {
            getline(inFile, firstWord);
            newPatient = obtainNextPatient();
        }
    }

    return newPatient;
} // end obtainNextPatient
