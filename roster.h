
#pragma once
#include <string>
#include <iostream>
#include "student.h"

using std::string;

int numStudents = 5;

string studentData[5] = {
    "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
    "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
    "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
    "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", 
    "A5,David,Canonigo,dcanon1@wgu.edu,23,15,24,11,SOFTWARE"
};

class StudentSecurity : public Student {

public:
    StudentSecurity();
    StudentSecurity(string StudentID, string firstName, string lastName, string emailAddress, string studentAge, int* daysInCourse, DegreeType degreetype);
        
    DegreeType getDegreeType();
    void setDegreeType(DegreeType d);
    void print();

    ~StudentSecurity();
};

class StudentSoftware : public Student {

public:
    StudentSoftware();
    StudentSoftware(string StudentID, string firstName, string lastName, string emailAddress, string studentAge, int* daysInCourse, DegreeType degreetype);
        
    DegreeType getDegreeType();
    void setDegreeType(DegreeType d);
    void print();

    ~StudentSoftware();
};

class StudentNetwork : public Student {
public:
    StudentNetwork();
    StudentNetwork(string StudentID, string firstName, string lastName, string emailAddress, string studentAge, int* daysInCourse, DegreeType degreetype);
    
    DegreeType getDegreeType();
    void setDegreeType(DegreeType d);
    void print();

    ~StudentNetwork();
};


class Roster {
public:
    int lastIndex;
    int limit;
    
    Student** classRosterArray;
    
    Roster();
    Roster(int limit);
    
    void add(string datarow);
    void printAll();
    bool remove(string studentID);
    void printAverageDaysInCourse(string studentID);
    void printInvalidEmails();
    void printByDegreeType(DegreeType d);
    
    ~Roster();
};
