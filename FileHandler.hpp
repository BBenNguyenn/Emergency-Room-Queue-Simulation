// CLASS: FileHandler
// REMARKS: What is the purpose of this class?
//	To hold any functions and data which processes the file.
//-----------------------------------------
#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include "EDSimulation.hpp"
class Patient;

using namespace std;

class FileHandler
{
private:
  static ifstream inFile;

public:
  static void openFile(char *filename);
  static Patient *obtainNextPatient();
};
#endif