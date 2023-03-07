#include <iostream>
#include <string>

using namespace std;

#include "student.h"

//Accessor functions
string Student::getID() {return this->studentID;}
string Student::getFName() {return this->firstName;}
string Student::getLName() {return this->lastName;}
string Student::getEmail() {return this->emailAddress;}
int Student::getAge() {return this->age;}
int Student::getDays() {return this->daysComplete;}//array name is a pointer; you don't want to return prices individually but the reference to them
DegreeType Student::getDegree(){return this->degreeProgram;}

//Mutator functions
void Student::setID(string studentID){this->studentID = studentID;}
void Student::setFName(string fName) {this->fName = firstName;}
void Student::setLName(string lName){this->lName = lastName;}
void Student::setEmail(string email){this->email = emailAddress;}
void Student::setAge(int age){ this->age = age;}
void Student::setDays(int daysComplete[])//set each number of days individually
{
    for (int i = 0; i < days; i++) this ->daysComplete[i] = daysComplete[i];
}
void Student::setDegree(DegreeProgram degreeProgram) {this ->degreeProgram = degreeProgram;}

//Default values for blank constructor function
Student::Student() {

    this->studentID = "";
    this->firstName = "";
    this->lastName = "";
    this->emailAddress = "";
    this->age = 0;
    for (int i = 0; i < days; i++) this->daysComplete[i] = 0;//loops over array and sets default price to 0
    this->degreeProgram = DegreeProgram::UNDETERMINED;
}

//Constructor function
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysComplete[], DegreeProgram degreeProgram);
{
    //(pointer_name)->(variable_name)
    this->studentID = studentID;
    this->firstName = fName;
    this->lastName = lName;
    this->emailAddress = email;
    this->age = age;
    for (int i = 0; i < days; i++) this ->daysComplete[i] = daysComplete[i];
    this ->degreeType = degreeType;
}

//Print function
void Student::print()
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
}
