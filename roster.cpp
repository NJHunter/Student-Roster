#pragma once
#include "roster.h"
#include "student.h"
#include <iostream>
#include <string>
using namespace std;


Roster::Roster() {}

void Roster::parse(string studentInfo)
{
    //checks the last character of degreeType to determine which degree the student has
    DegreeProgram degreeType = NONE;
    if (studentInfo.back() == 'Y')
        degreeType = SECURITY;
    else if (studentInfo.back() == 'K')
        degreeType = NETWORK;
    else if (studentInfo.back() == 'E')
        degreeType = SOFTWARE;
    
    //parses out the information. it is finding a comma then stores the string up to that comma(not including) in its variable.
    int rhs = studentInfo.find(",");
    string studentID = studentInfo.substr(0, rhs);

    int lhs = rhs + 1;
    rhs = studentInfo.find(",", lhs);
    string firstName = studentInfo.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentInfo.find(",", lhs);
    string lastName = studentInfo.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentInfo.find(",", lhs);
    string emailAddress = studentInfo.substr(lhs, rhs - lhs);

    lhs = rhs + 1;
    rhs = studentInfo.find(",", lhs);
    int age = stoi(studentInfo.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentInfo.find(",", lhs);
    double numDays1 = stod(studentInfo.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentInfo.find(",", lhs);
    double numDays2 = stod(studentInfo.substr(lhs, rhs - lhs));

    lhs = rhs + 1;
    rhs = studentInfo.find(",", lhs);
    double numDays3 = stod(studentInfo.substr(lhs, rhs - lhs));

    add(studentID, firstName, lastName, emailAddress, age, numDays1, numDays2, numDays3, degreeType);
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, double numDays1, double numDays2, double numDays3, DegreeProgram degreeType)
{
    double numDays[3] = { numDays1,numDays2,numDays3 };
    classRosterArray[++rosterIndex] = new Student(studentID, firstName, lastName, emailAddress, age, numDays, degreeType);
}

//outputs all student information inside the class roster.

void Roster::printAll()
{
    Student::printHeader();
    for (int i = 0; i <= rosterIndex; i++)
    {
        classRosterArray[i]->print();
    }
}

void Roster::printAverageDaysInCourse(string studentID)
{
    for (int i = 0; i <= rosterIndex; i++)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            cout << "Student ID: " << studentID << ",";
            cout << " averages ";
            cout << (classRosterArray[i]->getNumDays()[0] +
                classRosterArray[i]->getNumDays()[1] +
                classRosterArray[i]->getNumDays()[2]) / 3;
            cout << " days in a course." << endl;
        }
    }
}

void Roster::printInvalidEmails()
{
    bool fakeEmail = false;

    for (int i = 0; i <= rosterIndex; i++)
    {
        string emailAddress = classRosterArray[i]->getEmail();
        if (emailAddress.find("@") == string::npos || emailAddress.find(".") == string::npos || emailAddress.find(" ") != string::npos)
        {
            fakeEmail = true;
            cout << emailAddress << ": " << classRosterArray[i]->getEmail() << endl;
        }
    }

    if (!fakeEmail)
        cout << "NONE" << endl;
}

void Roster::printByDegreeProgram(DegreeProgram degreeType)
{
    Student::printHeader();
    for (int i = 0; i <= rosterIndex; i++)
    {
        if (classRosterArray[i]->getDegree() == degreeType)
            classRosterArray[i]->print();
    }
    cout << endl;
}

//removes a student from the class roster by id #
void Roster::remove(string studentID)
{
    bool found = false;

    for (int i = 0; i <= rosterIndex; i++)
    {
        if (classRosterArray[i]->getStudentID() == studentID)
        {
            found = true;
            if (i < rosterIndex)
            {
                Student* temp = classRosterArray[i];
                classRosterArray[i] = classRosterArray[rosterIndex];
                classRosterArray[rosterIndex] = temp;
            }

            delete classRosterArray[rosterIndex];
            classRosterArray[rosterIndex] = nullptr;
            rosterIndex--;
            
            printAll();
            break;
        }
    }
    if (!found)
        cout << studentID << " was not found." << endl;
}

//deconstructor and memory cleanup
Roster::~Roster()
{
    for (int i = 0; i <= rosterIndex; i++)
    {
        delete classRosterArray[i];
        classRosterArray[i] = nullptr;
    }
}
