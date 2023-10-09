#include <iostream>
#include <string>
#include "roster.h"
using namespace std;

int main() {

	cout << "C867-Scripting & Programming: Applications" << endl;
	cout << "Language: C++" << endl;
	cout << "Student ID : 010807373" << endl;
	cout << "Name: Christopher Torregrosa-Percy" << endl;
	cout << endl;

	const string studentData[] = {
	"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Chris,Percy,ctor329@wgu.edu,27,7,14,30,SOFTWARE" };
		
	Roster classRoster;

	for (int i = 0; i < 5; i++) {
		classRoster.parse(studentData[i]);
	}

	classRoster.printAll();

	classRoster.printInvalidEmails();

	classRoster.printAverageDaysInCourse("A1");
	classRoster.printAverageDaysInCourse("A2");
	classRoster.printAverageDaysInCourse("A3");
	classRoster.printAverageDaysInCourse("A4");
	classRoster.printAverageDaysInCourse("A5");

	cout << endl;

	DegreeProgram SOFTWARE = DegreeProgram::SOFTWARE;
	DegreeProgram NETWORK = DegreeProgram::NETWORK;
	DegreeProgram SECURITY = DegreeProgram::SECURITY;

	classRoster.printByDegreeProgram(SOFTWARE);

	classRoster.remove("A3");

	classRoster.printAll();

	classRoster.remove("A3");
};









	

