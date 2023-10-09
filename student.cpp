#include <iostream>
#include "student.h"
#include <string>
using namespace std;
														//Constructors
Student::Student() {
	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	this->daysToComplete[0] = 0;
	this->daysToComplete[1] = 0;
	this->daysToComplete[2] = 0;
	this->degreeProgram = DegreeProgram::SOFTWARE;
}
Student::Student(
	string studentID,
	string firstName,
	string lastName,
	string emailAddress,
	int age,
	int daysToComplete0,
	int daysToComplete1,
	int daysToComplete2,
	DegreeProgram degreeProgram)
{
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	this->daysToComplete[0] = daysToComplete0;
	this->daysToComplete[1] = daysToComplete1;
	this->daysToComplete[2] = daysToComplete2;
	this->degreeProgram = degreeProgram;
}
														//Print Declaration
void Student::print() {
				//ENUM to String
	string programString;
	if (degreeProgram == DegreeProgram::SECURITY) {
		programString = "SECURITY";}
	else if (degreeProgram == DegreeProgram::NETWORK) {
		programString = "NETWORK";}
	else if (degreeProgram == DegreeProgram::SOFTWARE) {
		programString = "SOFTWARE";}
				//Print format
		cout << studentID << "\t"
			<< "First Name: " << firstName << "\t"
			<< "Last Name: " << lastName << "\t"
			<< "Age: " << age << "\t" 
			<< "daysInCourse {" 
			<< daysToComplete[0] <<","
			<< daysToComplete[1] << ","
			<< daysToComplete[2] << "}" << "\t"
			<< "Degree Program: " << programString << endl;}
														//Setters
void Student::setStudentID(string sID) {
	studentID = sID;}
void Student::setFirstName(string fName) {
	firstName = fName;}
void Student::setLastName(string lName) {
	lastName = lName;}
void Student::setEmailAddress(string eMail) {
	emailAddress = eMail;}
void Student::setAge(int studentAge) {
	age = studentAge;}
void Student::setDaysToComplete0( int newDaysToComplete) {
	daysToComplete[0] = newDaysToComplete;}
void Student::setDaysToComplete1( int newDaysToComplete1) {
	daysToComplete[1] = newDaysToComplete1;}
void Student::setDaysToComplete2(int newDaysToComplete2) {
	daysToComplete[2] = newDaysToComplete2;}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;}
														//Getters
string Student::getStudentID() const {
	return studentID;}
string Student::getFirstName() const {
	return firstName;}
string Student::getLastName() const {
	return lastName;}
string Student::getEmailAddress() const {
	return emailAddress;}
int Student::getAge() const {
	return age;}
int Student::getDaysToComplete0() const{
	return daysToComplete[0];}
int Student::getDaysToComplete1() const {
	return daysToComplete[1];}
int Student::getDaysToComplete2() const {
	return daysToComplete[2];}
DegreeProgram Student::getDegreeProgram() const {
	return degreeProgram;}