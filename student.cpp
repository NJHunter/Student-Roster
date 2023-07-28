#include <iostream>
#include <string>
#include "student.h"
#include "degree.h"
using namespace std;

Student::Student() 
//constructor with no paramters to set the default value
{
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	this->degreeType = DegreeProgram::NONE;
	for (int i = 0; i < numDaysArray; i++) this->numDays[i] = 0;
}

//constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress, int age, double numDays[], DegreeProgram degreeType) 
	{
		this->studentID = studentID;
		this->firstName = firstName;
		this->lastName = lastName;
		this->emailAddress = emailAddress;
		this->age = age;
		this->degreeType = degreeType;
		for (int i = 0; i < numDaysArray; i++) this->numDays[i] = numDays[i];
	}

//destructor
Student::~Student() {}

//getters
string Student::getFirstName() {return this->firstName;}
string Student::getLastName() {return this->lastName;}
string Student::getStudentID() {return this->studentID;}
string Student::getEmail() {return this->emailAddress;}
DegreeProgram Student::getDegree() {return this->degreeType;}
int Student::getAge() {return this->age;}
double* Student::getNumDays() {return this->numDays;}

//setters
void Student::setFirstName(string firstName){this->firstName = firstName;}
void Student::setLastName(string lastName) {this->lastName = lastName;}
void Student::setStudentID(string studentID) {this->studentID = studentID;}
void Student::setEmailAddress(string emailAddress) {this->emailAddress = emailAddress;}
void Student::setAge(int age) {this->age = age;}
void Student::setNumDays(double numDays[])
{for (int i = 0; i < numDaysArray; i++) this->numDays[i] = numDays[i];}
void Student::setDegree(DegreeProgram degreeType) {this->degreeType = degreeType;}
void Student::printHeader(){cout << " " << endl;}
void Student::print()
{
	cout << this->getStudentID() << "\t";
	cout << "First Name: " << this->getFirstName() << "\t";
	cout << "Last Name: " << this->getLastName() << "\t";
	cout << "Email Address: " << this->getEmail() << "\t";
	cout << "Age: " << this->getAge() << "\t";
	cout << "Days in Course: " << numDays[0] << "," << numDays[1] << "," <<
		numDays[2] << "\t";
	cout << "Degree: " << degreeString[this->getDegree()] << endl;
}

