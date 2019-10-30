//-----------------------------------------
// REMARKS: What is the purpose of this program?
// To simulate an emergency department with event driven simulation
// and collect some data regarding service time and wait times.
//-----------------------------------------
#include <iostream>
#include <cstdlib>
#include "FileHandler.hpp"
#include "EDSimulation.hpp"

using namespace std;

//------------------------------------------------------
// PARAMETERS:
//     describe the purpose and expectations of parameters,
//     including whether the parameters are returning data
//     (via alteration of the parameters)
// Returns: describe the return value
//------------------------------------------------------
int main(int argc, char *argv[])
{

  if (argc < 2)
  {
    cout << "Usage: " << argv[0] << " <file name>\n";
    exit(1);
  }

  cout << "Simulation begins...\n";

  FileHandler::openFile(argv[1]); // NOT reading in all at once
  EDSimulation::initiate();

  cout << "\n...Simulation complete.\n\n";

  EDSimulation::printStats();

  cout << "\nEnd of processing.\n";
  return 0;

} // main
