#pragma once
#include "degree.h"
#include <iostream>
#include <string>
using std::string;
using std::cout;


//create the student class
class Student
{
public:
	const static int numDaysArray = 3;

private:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		DegreeProgram degreeType;
		int age;
		double numDays[numDaysArray];

public:
		//constructor
		Student();
		Student(string studentID, string firstName, string lastName, string emailAddress, int age, double numDays[], DegreeProgram degreeType);

		//accessors - gets the value
		string getStudentID();
		string getFirstName();
		string getLastName();
		string getEmail();
		int getAge();
		double* getNumDays();
		DegreeProgram getDegree();

	//mutators: sets the value
	void setStudentID(string studentID);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setEmailAddress(string emailAddress);
	void setAge(int age);
	void setNumDays(double days[]);
	void setDegree(DegreeProgram degreeType);

	static void printHeader();
	void print();

	
	//destructor
	~Student();

};


