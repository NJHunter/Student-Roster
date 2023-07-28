#pragma once
#include "roster.h"
#include "student.h"


int main()
{
	/*-----Student Information-----*/
	cout << "C867-Scripting & Programming: Applications" << std::endl;
	cout << "Language: C++" << std::endl;
	cout << "Student ID: 010584633" << std::endl;
	cout << "Name: Nick Hunter" << std::endl;
	cout << std::endl;


	const string studentData[] =
	{
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Nick,Hunter,nhun105@wgu.edu      ,37,11,26,39,SOFTWARE" //extra spaces to match up the lines
	};


	const int totalStudents = 5;
	Roster classRoster;

	for (int i = 0; i < totalStudents; i++) classRoster.parse(studentData[i]);

	cout << "Displaying all students: " << std::endl;
	classRoster.printAll();
	cout << std::endl;



	cout << "Displaying invalid Emails:" << std::endl;
	cout << std::endl;
	classRoster.printInvalidEmails();
	cout << std::endl;



	cout << "Average days to finish a course: " << std::endl;
	cout << std::endl;
		for (int i = 0; i < totalStudents; i++){
			classRoster.printAverageDaysInCourse(classRoster.classRosterArray[i]->getStudentID());
			}


	cout << std::endl;
	cout << "Showing students in the degree program: " << degreeString[2] << std::endl;
	cout << std::endl;
	classRoster.printByDegreeProgram(SOFTWARE);

	cout << std::endl;


	cout << "Removing A3" << std::endl;
	classRoster.remove("A3");
	cout << std::endl;


	cout << "The student with the ID: ";
	classRoster.remove("A3");
	cout << std::endl;


	system("pause");
	return 0;


}
