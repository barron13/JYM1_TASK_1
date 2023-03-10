#include <string>

using namespace std;

//Define DegreeProgram class
enum DegreeProgram {SECURITY, NETWORK, SOFTWARE, UNDETERMINED};

//Define array used to retrieve string value of DegreeProgram class
static const std::string degreeStrings[] = { "SECURITY", "NETWORK", "SOFTWARE", "UNDETERMINED"};