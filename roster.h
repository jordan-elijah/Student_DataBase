#pragma once
#include "student.h"
#include <stdio.h>
#include <iostream>
using namespace std;

class roster {

private:
	const static int studentDataTable = 5;
	student* classRosterArray[studentDataTable];

public:
	int classCapacity;
	int slot;

	void parse(string row);
	void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, DegreeProgram degreeProgram);
	void removeStudent(string studentID);
	void printAll();
	void printAvgDaysInCourse(string studentID);
	void printBadEmails();
	void printViaDegreeType(DegreeProgram degreeProgram);
	roster();
	roster(int classSize);
	string getStudentClassID(int slot);
	~roster();
};
