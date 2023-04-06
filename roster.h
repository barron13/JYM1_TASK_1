#include <string>
#include <vector>

using namespace std;

#include "student.h"

class roster {
    public:
        vector<student*> classRosterArray;
        
    public:
        //Parse function
        void parse(string row);
        //Add function
        void add(string studentID,
                string firstName,
                string lastName,
                string emailAddress,
                int Age,
                int days1,
                int days2,
                int days3,
                DegreeProgram degreeProgram);

        //Constructor & Destructor functions
        roster();
        ~roster();
        
        //Remove function by student ID
        bool remove(string studentID);

        //Print functions
        void printAll();
        void printAverageDaysInCourse(string studentID);
        void printInvalidEmails();
        void printByDegreeProgram(DegreeProgram degreeProgram);
};
