#include <iostream>
#include <string>
#include "roster.h"
using namespace std;
												//Parse Function
void Roster::parse(string studentData) {

	size_t rhs = studentData.find(",");
	string studentID = studentData.substr(0, rhs);

	size_t lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string firstName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string lastName = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string emailAddress = studentData.substr(lhs, rhs - lhs);

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int age = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysToComplete0 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysToComplete1 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	int daysToComplete2 = stoi(studentData.substr(lhs, rhs - lhs));

	lhs = rhs + 1;
	rhs = studentData.find(",", lhs);
	string programString = studentData.substr(lhs, rhs - lhs);
												//STRING TO ENUM
	DegreeProgram degreeProgram{};
	if (programString == "SECURITY") {
		degreeProgram = DegreeProgram::SECURITY;
	}
	else if (programString == "NETWORK") {
		degreeProgram = DegreeProgram::NETWORK;
	}

	else if (programString == "SOFTWARE") {
		degreeProgram = DegreeProgram::SOFTWARE;
	}
												//Calling ADD Function
	add(studentID,
		firstName,
		lastName,
		emailAddress,
		age,
		daysToComplete0,
	daysToComplete1,
	daysToComplete2,
	degreeProgram);
}
												//Defining ADD Function
void Roster::add(
	string studentID,
	string firstName,
	string lastName,
	string emailAddress,
	int age,
	int daysToComplete0,
	int daysToComplete1,
	int daysToComplete2,
	DegreeProgram degreeProgram) {
	classRosterArray[index] = new Student(studentID, firstName, lastName, emailAddress, age, daysToComplete0, daysToComplete1,daysToComplete2,degreeProgram);
	index++;}
												//Print Average Days in Course
void Roster::printAverageDaysInCourse(string studentID) {
		cout << "Student ID: " << studentID << ", ";
		cout << "Average Days In Course is: ";

		for (int i = 0; i < 5; i++) {
			if (studentID == classRosterArray[i]->getStudentID()) {
				cout << (classRosterArray[i]->getDaysToComplete0() + classRosterArray[i]->getDaysToComplete1() + classRosterArray[i]->getDaysToComplete2()) / 3 << endl;
			}
		}
	}
												//PRINT INVALID EMAILS
void Roster::printInvalidEmails() {
	cout << "Displaying Invalid Emails:" << endl;
	cout << endl;
	for (int i = 0; i < 5; i++) {
		string emailAddress = classRosterArray[i]->getEmailAddress();

		size_t At = emailAddress.find("@");
		size_t dot = emailAddress.find(".");
		size_t space = emailAddress.find(" ");

		if (At == string::npos) {
			cout << emailAddress << endl;}
		if (dot == string::npos) {
			cout << emailAddress << endl;}
		if (space != string::npos) {
			cout << emailAddress << endl;}
	}
	cout << endl;
}
												//PRINT ALL STUDENTS
void Roster::printAll() {
	cout << "Displaying All Students:" << endl;
	cout << endl;
	if (classRosterArray[4] == temp) {
		for (int i = 0; i < 4; ++i) {
			classRosterArray[i]->print();
		}
	}
	else 
		for (int i = 0; i < 5; i++) {
			classRosterArray[i]->print();
		}
	cout << endl;
}
												//Print By Degree Program
void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
		if (degreeProgram == DegreeProgram::SOFTWARE) {
			cout << "Displaying students in degree program: SOFTWARE" << endl;
			cout << endl;
			classRosterArray[2]->print();
			classRosterArray[4]->print();
		}
		if (degreeProgram == DegreeProgram::NETWORK) {
			cout << "Displaying students in degree program: NETWORK" << endl;
			cout << endl;
			classRosterArray[1]->print();
		}
		if (degreeProgram == DegreeProgram::SECURITY) {
			cout << "Displaying students in degree program: SECURITY" << endl;
			cout << endl;
			classRosterArray[0]->print();
			classRosterArray[3]->print();
		}
		cout << endl;
}
												//Remove Student
void Roster::remove(string studentID) {
	if (studentID == classRosterArray[0]->getStudentID()) {
		classRosterArray[0] = classRosterArray[1];
		classRosterArray[1] = classRosterArray[2];
		classRosterArray[2] = classRosterArray[3];
		classRosterArray[3] = classRosterArray[4];
		classRosterArray[4] = temp;
		cout << "Student A1 has been removed." << endl;
	}
	else if (studentID == classRosterArray[1]->getStudentID()) {
		classRosterArray[1] = classRosterArray[2];
		classRosterArray[2] = classRosterArray[3];
		classRosterArray[3] = classRosterArray[4];
		classRosterArray[4] = temp;
		cout << "Student A2 has been removed." << endl;
	}
	else if (studentID == classRosterArray[2]->getStudentID()) {
		classRosterArray[2] = classRosterArray[3];
		classRosterArray[3] = classRosterArray[4];
		classRosterArray[4] = temp;
		cout << "Student A3 has been removed." << endl;
	}
	else if (studentID == classRosterArray[3]->getStudentID()) {
		classRosterArray[3] = classRosterArray[4];
		classRosterArray[4] = temp;
		cout << "Student A4 has been removed." << endl;
	}
	else if (studentID == classRosterArray[4]->getStudentID()) {
		classRosterArray[4] = temp;
		cout << "Student A5 has been removed.";
	}
	else cout << "Student " << studentID << " does not exist." << endl;
	cout << endl;
}
													//DESTRUCTOR
Roster::~Roster() {
	for (int i = 0; i < 5; i++) {
		delete classRosterArray[i];
	}
	cout << "Allocated Memory Has Been Released"<< endl;
}