
#include "roster.h"
#include "degree.h"

using std::cout;
using std::cerr;

int main() {
    cout << "Scripting and Programming - Applications – C867\n";
    cout << "Programming Language Used: C++\n";
    cout << "Student ID: 001364350\n";
    cout << "Name: David Canonigo\n";
    cout << "\n";

    Roster * classRoster = new Roster(numStudents);
    cout << "Creating table with students from array...\n";

    for (int i = 0; i < numStudents; i++) {
            classRoster->add(studentData[i]);
    }

    cout << "Students Table Below:\n";
    cout << "\n";

    classRoster->printAll();
    cout << "\n";

    classRoster->printAverageDaysInCourse("A5");
    cout << "\n";

    classRoster->printInvalidEmails();
    cout << "\n";

    classRoster->printByDegreeType(SOFTWARE);
    cout << "\n";

    cout << "Remo ving A3:\n";
    cout << "\n";

    if (classRoster->remove("A3")) {
        classRoster->printAll();
        cout << "\n";
        }
        else cout << "Student not found!\n";

    cout << "Removing student with student ID A3...\n";
    cout << "\n";

    if (classRoster->remove("A3")) {
        classRoster->printAll();
        }
        else cout << "Student A3 was not found!\n";

    return 0;
}



StudentNetwork::StudentNetwork() {
    setDegreeType(NETWORK);
}

StudentNetwork::StudentNetwork(string StudentID, string firstName, string lastName, string email, string age, int * days, DegreeType degreetype) {
    setDegreeType(NETWORK);
}

DegreeType StudentNetwork::getDegreeType() {
    return NETWORK;
}

void StudentNetwork::setDegreeType(DegreeType d) {
    this->type = NETWORK;
}

void StudentNetwork::print() {
    this->Student::print();
    cout << "NETWORK\n";
}

StudentNetwork::~StudentNetwork() {
    Student::~Student();
}

StudentSecurity::StudentSecurity(){
    setDegreeType(SECURITY);
}

StudentSecurity::StudentSecurity(string StudentID, string firstName, string lastName, string email, string age, int * days, DegreeType degreetype) {
    setDegreeType(SECURITY);
}

DegreeType StudentSecurity::getDegreeType() {
    return SECURITY;
}

void StudentSecurity::setDegreeType(DegreeType d) {
    this->type = SECURITY;
}

void StudentSecurity::print() {
    this->Student::print();
    cout << "SECURITY\n";
}

StudentSecurity::~StudentSecurity() {
    Student::~Student();
}

StudentSoftware::StudentSoftware(){
    setDegreeType(SOFTWARE);
}

StudentSoftware::StudentSoftware(string StudentID, string firstName, string lastName, string email, string age, int * days, DegreeType degreetype) {
    setDegreeType(SOFTWARE);
}

DegreeType StudentSoftware::getDegreeType() {
    return SOFTWARE;
}

void StudentSoftware::setDegreeType(DegreeType d) {
    this->type = SOFTWARE;
}

void StudentSoftware::print() {
    this->Student::print();
    cout << "SOFTWARE\n";
}

StudentSoftware::~StudentSoftware() {
    Student::~Student();
}


Roster::Roster() {
    this->limit = 5;
    this->lastIndex = -1;
    this->classRosterArray = nullptr;
}

Roster::Roster(int limit) {
    this->limit = limit;
    this->lastIndex = -1;
    this->classRosterArray = new Student*[limit];
}

void Roster::add(string row) {
    if (lastIndex < limit) {
            lastIndex++;
            int darray[Student::daysArraySize];

            if (row[4] == 'o') {
                this->classRosterArray[lastIndex] = new StudentSecurity();
                classRosterArray[lastIndex]->setDegreeType(SECURITY);
            }

                else if (row[4] == 'r') {
                    this->classRosterArray[lastIndex] = new StudentSecurity();
                    classRosterArray[lastIndex]->setDegreeType(SECURITY);
                }

                else if (row[4] == 'u') {
                    this->classRosterArray[lastIndex] = new StudentNetwork();
                    classRosterArray[lastIndex]->setDegreeType(NETWORK);
                }

                else {
                    this->classRosterArray[lastIndex] = new StudentSoftware();
                    classRosterArray[lastIndex]->setDegreeType(SOFTWARE);
                }

            int rhs = studentData[lastIndex].find(",");
            classRosterArray[lastIndex]->setID(studentData[lastIndex].substr(0, rhs));

            int lhs = rhs + 1;
            rhs = studentData[lastIndex].find(",", lhs);
            classRosterArray[lastIndex]->setFirstName(studentData[lastIndex].substr(lhs, rhs - lhs));

            lhs = rhs + 1;
            rhs = studentData[lastIndex].find(",", lhs);
            classRosterArray[lastIndex]->setLastName(studentData[lastIndex].substr(lhs, rhs - lhs));

            lhs = rhs + 1;
            rhs = studentData[lastIndex].find(",", lhs);
            classRosterArray[lastIndex]->setEmail(studentData[lastIndex].substr(lhs, rhs - lhs));

            lhs = rhs + 1;
            rhs = studentData[lastIndex].find(",", lhs);
            classRosterArray[lastIndex]->setAge(studentData[lastIndex].substr(lhs, rhs - lhs));

            lhs = rhs + 1;
            rhs = studentData[lastIndex].find(",", lhs);
            darray[0] = stod(studentData[lastIndex].substr(lhs, rhs - lhs));

            lhs = rhs + 1;
            rhs = studentData[lastIndex].find(",", lhs);
            darray[1] = stod(studentData[lastIndex].substr(lhs, rhs - lhs));

            lhs = rhs + 1;
            rhs = studentData[lastIndex].find(",", lhs);
            darray[2] = stod(studentData[lastIndex].substr(lhs, rhs - lhs));

            classRosterArray[lastIndex]->setDays(darray);
    }
}

// Printing functions
void Roster::printAll() {
    for (int i = 0; i <= this->lastIndex; i++) (this->classRosterArray)[i]->print();
}

// Functions being removed
bool Roster::remove(string studentID) {
    bool found = false;
    for (int i = 0; i <= lastIndex; i++) {
            if (this->classRosterArray[i]->getID() == studentID) {
                found = true;
                Student* stu = classRosterArray[i];
                this->classRosterArray[i] = this->classRosterArray[lastIndex];
                (classRosterArray[lastIndex]) = stu;
                    lastIndex--;
            }
    }
    return found;
}

// Averaging Student ID days in course
void Roster::printAverageDaysInCourse(string studentID) {
    bool found = false;
    for (int i = 0; i <= lastIndex; i++) {
        if (this->classRosterArray[i]->getID() == studentID) {
            found = true;
            int* d = classRosterArray[i]->getDays();
            cout << "Student ID: " << studentID << ", averages " << (d[0] + d[1] + d[2]) / 3 << " days in a course.\n";
          }
    }
    if (!found) cout << "Student not found!\n";
}

// Validating email
void Roster::printInvalidEmails() {
    cout << "Displaying invalid emails:\n";
    cout << "\n";
    for (int i = 0; i < 5; i++) {
    bool foundAt = false;
    bool foundPeriod = false;
    bool foundSpace = false;
        string email = "";
        email = (*classRosterArray[i]).getEmail();
        for (char &c : email) {
                    if (c == '@') {
                        foundAt = true;
                    }
                    if (c == '.') {
                        foundPeriod = true;
                    }
                    if (c == ' ') {
                        foundSpace = true;
                    }
        }
                if (foundAt == false) {
                    cout << (*classRosterArray[i]).getEmail() << " - missing an @ symbol.\n";
                }
                if (foundPeriod == false) {
                    cout << (*classRosterArray[i]).getEmail() << " - missing a period.\n";
                }
                if (foundSpace == true) {
                    cout << (*classRosterArray[i]).getEmail() << " - no spaces allowed.\n";
        }
    }
}

// Getting Degree Type
void Roster::printByDegreeType(DegreeType d) {
    cout << "Showing students in degree program: " << degreeTypeStrings[d] << "\n";
    cout << "\n";

    for (int i = 0; i <= lastIndex; i++) {
            if (this->classRosterArray[i]->getDegreeType() == d) this->classRosterArray[i]->print();
    }
}

// Calling Desctructor
Roster::~Roster() {
    for (int i = 0; i < numStudents; i++) {
            delete this->classRosterArray[i];
    }
    delete this;
}
