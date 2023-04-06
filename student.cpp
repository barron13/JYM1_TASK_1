#include <iostream>
#include <string>

using namespace std;

#include "student.h"

//Accessor functions
string student::getID() {return studentID;}
string student::getFName() {return firstName;}
string student::getLName() {return lastName;}
string student::getEmail() {return emailAddress;}
int student::getAge() {return age;}
vector<int> student::getDays() {return daysComplete;}
DegreeProgram student::getDegree(){return degreeProgram;}

//Mutator functions
void student::setID(string studentID){this->studentID = studentID;}
void student::setFName(string firstName) {this->firstName = firstName;}
void student::setLName(string lastName){this->lastName = lastName;}
void student::setEmail(string emailAddress){this->emailAddress = emailAddress;}
void student::setAge(int Age){ this->age = age;}
void student::setDays(vector<int> daysComplete) {this ->daysComplete = daysComplete;}
void student::setDegree(DegreeProgram degreeProgram) {this ->degreeProgram = degreeProgram;}

//Default values for blank constructor function
student::student() {

    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    this->daysComplete;
    this->degreeProgram = UNDETERMINED;
}

//Constructor function
student::student(string studentID, string firstName, string lastName, string emailAddress, int age, vector<int> daysComplete, DegreeProgram degreeProgram)
{
    //(pointer_name)->(variable_name)
    this->studentID = studentID;
    this->firstName = firstName;
    this->lastName = lastName;
    this->emailAddress = emailAddress;
    this->age = age;
    for (int i = 0; i < days; i++) this ->daysComplete[i] = daysComplete[i];
    this ->degreeProgram = degreeProgram;
};

//Print function
void student::print()
{
    cout << this->getID() << '\t';//tab delimited
    cout << this->getFName() << '\t';
    cout << this->getLName() << '\t';
    cout << this->getEmail() << '\t';
    cout << this->getAge() << '\t';
    cout << this->getDays()[0] << ',';
    cout << this->getDays()[1] << ',';
    cout << this->getDays()[2] << '\t';
    cout << degreeStrings[this->getDegree()] << '\n';
};
