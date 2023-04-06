#include <string>
#include <vector>

using namespace std;

#include "degree.h"

class student {
    //Declare size of array for daysComplete
    public:
    const static int days = 3;

    //Declare each variable for Student class
    private:
        string studentID, firstName, lastName, emailAddress;
        int age;
        vector<int> daysComplete;
        DegreeProgram degreeProgram;

    public:
    //Accessor functions
        string getID();
        string getFName();
        string getLName();
        string getEmail();
        int getAge();
        vector<int> getDays();
        DegreeProgram getDegree();

    //Mutator functions
        void setID(string studentID);
        void setFName(string firstName);
        void setLName(string lastName);
        void setEmail(string emailAddress);
        void setAge(int Age);
        void setDays(vector<int> daysComplete);
        void setDegree(DegreeProgram degreeProgram);

    //Constructor functions
        student(); //Sets parameters to default values
        student(string studentID, string firstName, string lastName, string emailAddress, int age, vector<int> daysComplete, DegreeProgram degreeProgram);
        
    //Print function
        void print();
};