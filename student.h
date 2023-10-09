#pragma once
#include "degree.h"
using namespace std;

class Student {
private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	int daysToComplete[3];
	DegreeProgram degreeProgram;
public:
	void print();
														//Constructors
	Student();
	Student(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysToComplete0,
		int daysToComplete1,
		int daysToComplete2,
	DegreeProgram degreeProgram);
														//Setters
	void setStudentID(string sID);
	void setFirstName(string fName);
	void setLastName(string lName);
	void setEmailAddress(string eMail);
	void setAge(int studentAge);
	void setDaysToComplete0(int newDaysToComplete);
	void setDaysToComplete1(int newDaysToComplete1);
	void setDaysToComplete2(int newDaysToComplete2);
	void setDegreeProgram(DegreeProgram degreeProgram);
														//Getters
	string getStudentID() const;
	string getFirstName() const;
	string getLastName() const;
	string getEmailAddress() const;
	int getAge() const;
	int getDaysToComplete0() const;
	int getDaysToComplete1() const;
	int getDaysToComplete2() const;
	DegreeProgram getDegreeProgram() const;
};
