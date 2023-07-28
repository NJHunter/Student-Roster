#pragma once
#include "student.h"

////create the roster class
class Roster {


public:
	int rosterIndex = -1;
	const static int totalStudents = 5;
	//array of students
	Student* classRosterArray[totalStudents]; 


public:
	//constructor
	Roster();

	void parse(string textData);
	void add(string studentID, string firstName, string lastName, string emailAddress,
		int age, double numDays1, double numDays2, double numDays3, DegreeProgram degreeType);
	void printAll();

	void printByDegreeProgram(DegreeProgram degreeType);
	void printInvalidEmails();
	void printAverageDaysInCourse(string studentID);

	void remove(string studentID);

	//destructor
	~Roster();


};
