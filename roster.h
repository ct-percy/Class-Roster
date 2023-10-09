#include "student.h"

class Roster {
private:
	Student* classRosterArray[5];
	int index = 0;
	Student* temp = new Student;
public:
	void add(
		string studentID,
		string firstName,
		string lastName,
		string emailAddress,
		int age,
		int daysToComplete0,
		int daysToComplete1,
		int daysToComplete2,
		DegreeProgram degreeProgram);
	void printAll();
	void remove(string studentID);
	void printAverageDaysInCourse(string newStudentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	void parse(string studentData);
	~Roster();
};