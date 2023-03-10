#include <string>

using namespace std;

#include "degree.h"

class Student {
    //Declare size of array for daysComplete
    public:
    const static int days = 3;

    //Declare each variable for Student class
    private:
        string studentID, firstName, lastName, emailAddress;
        int age;
        int daysComplete[days] ;
        DegreeProgram degreeProgram;

    public:
    //Accessor functions
        string getID();
        string getFName();
        string getLName();
        string getEmail();
        int getAge();
        int* getDays();
        DegreeProgram getDegree();

    //Mutator functions
        void setID(string studentID);
        void setFName(string firstName);
        void setLName(string lastName);
        void setEmail(string emailAddress);
        void setAge(int Age);
        void setDays(int daysComplete[]);
        void setDegree(DegreeProgram degreeProgram);

    //Constructor functions
        Student(); //Sets parameters to default values
        Student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysComplete[], DegreeProgram degreeProgram);
        
    //Print function
        void print();
};