#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

using namespace std;

#include "roster.h"

void roster::parse(string row)
{
    
    int rhs = row.find(',');//find the comma, return index
    string sID = row.substr(0, rhs);//extract substring in front of comma
    
    int lhs = rhs + 1;//move past previous comma
    rhs = row.find(',', lhs);
    string sFName = row.substr(lhs, rhs - lhs);//first name
    
    lhs = rhs + 1;//continue
    rhs = row.find(',', lhs);
    string sLName = row.substr(lhs, rhs - lhs);//last name
    
    lhs = rhs + 1; //continue
    rhs = row.find(",", lhs);
    string sEmail = row.substr(lhs, rhs -lhs);
    
    lhs = rhs + 1; //continue
    rhs = row.find(",", lhs);
    int sAge = stoi(row.substr(lhs, rhs -lhs));
    
    lhs = rhs + 1; //continue
    rhs = row.find(",", lhs);
    int d1 = stod(row.substr(lhs, rhs-lhs));//first number of days
    
    lhs = rhs + 1; //continue
    rhs = row.find(",", lhs);
    int d2 = stod(row.substr(lhs, rhs-lhs));
    
    lhs = rhs + 1; //continue
    rhs = row.find(",", lhs);
    int d3 = stod(row.substr(lhs, rhs-lhs));
    
    lhs = rhs + 1;
    rhs = row.find(",", lhs);

    DegreeProgram degreeProgram  = SECURITY;
    
    if (row.at(lhs) == 'S' && row.at(lhs + 1) == 'E') degreeProgram = SECURITY;
    else if (row.at(lhs) == 'S' && row.at(lhs + 1) == 'O') degreeProgram = SOFTWARE;
    else if (row.at(lhs) == 'N') degreeProgram = NETWORK;
    
    add(sID, sFName, sLName, sEmail, sAge, d1, d2, d3, degreeProgram);

}

void roster::add(
        string studentID,
        string firstName,
        string lastName,
        string emailAddress,
        int Age,
        int days1,
        int days2,
        int days3,
        DegreeProgram degreeProgram) {

        std::vector<int> addDaysInCourse{ days1, days2, days3};
	student* addStudent = new student( studentID, firstName, lastName, emailAddress, Age, addDaysInCourse, degreeProgram );
	classRosterArray.push_back(addStudent);
};

bool roster::remove(string studentID) {

    	bool foundItem = false;
	cout << "--Attempting to delete student ID: " << studentID << " from list--" << endl;
	for (size_t i = 0; i < classRosterArray.size(); i++)
	{
		if (studentID == classRosterArray.at(i)->getID()) {
			cout << "  Successfully Removed student " << studentID << "." << endl << endl;
			delete classRosterArray.at(i);
			classRosterArray.erase(classRosterArray.begin() + i);
			foundItem = true;
		}
	}
	if (!foundItem) {
		cout << "  No students found with that ID" << endl << endl;
	}
};

void roster::printAll(){
    cout << "ID" << '\t' << "First Name" << '\t' <<"Last Name" << '\t' << "Email Address" << '\t' << "Age" << '\t'<< "Days to Complete" << '\t'<< "Degree" << endl;

    for (int i = 0; classRosterArray.at(i); i++) roster::classRosterArray[i]->print();
};

void roster::printAverageDaysInCourse(string studentID) {
	bool foundItem = false;
	float avgDaysResult = 0.00;
	cout << "The average days in course for student " << studentID << " is: ";
	for (size_t i = 0; i < classRosterArray.size(); i++) {
		if (studentID == classRosterArray.at(i)->getID()) {
			vector<int> avgDaysVec = classRosterArray.at(i)->getDays();
			for (size_t i = 0; i < avgDaysVec.size(); i++) {
				avgDaysResult = avgDaysResult + avgDaysVec.at(i);
			}
			cout << setprecision(2) << avgDaysResult / avgDaysVec.size() << endl;
			foundItem = true;
		}
	}
	if (!foundItem) {
		cout << "Error" <<  " - No students found with that ID" << endl << endl;
        }
};

void roster::printInvalidEmails() {
	bool foundItem = false;
	cout << "Displaying invalid emails:" << endl << endl;

	for (size_t i = 0; i < classRosterArray.size(); i++) {
               string email = (classRosterArray[i]->getEmail());
        if ((email.find("@") == string::npos) || (email.find(" ") != string::npos) || (email.find(".") == string::npos)){
            foundItem = true;
            cout << email << ":" << classRosterArray[i]->getFName() << endl;
        }
	}
	if (!foundItem) {
		cout << "No invalid email addresses found" << endl;
	}
	cout << endl;
};

void roster::printByDegreeProgram(DegreeProgram degreeProgram) {
    cout << "ID" << '\t' << "First Name" << '\t' <<"Last Name" << '\t' << "Email Address" << '\t' << "Age" << '\t'<< "Days to Complete" << '\t'<< "Degree" << endl;

        for (int i = 0; classRosterArray.at(i); i++) {
        if (classRosterArray.at(i)->getDegree() == degreeProgram) classRosterArray.at(i)->print();
    }
    cout << endl;
};
