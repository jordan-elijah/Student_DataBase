#pragma once
#include "degree.h"
#include <iostream>
#include <string>
using namespace std;


class student {

private:
	static const int numberOfClasses = 3;
	
	string studentID ;
	string firstName;
	string lastName ;
	string emailAddress;
	int age;
	int daysInCourse[numberOfClasses];
	DegreeProgram degreeProgram;

public:
	student();
	student(string studentID, string firstName, string  lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram);
	~student();

	string getStudentID();
	void setStudentID(string studentID);
	void printStudentID();

	string getFirstName();
	void setFirstName(string firstName);
	void printFirstName();

	string getLastName();
	void setLastName(string lastName);
	void printLastName();

	string getEmailAddress();
	void setEmailAddress(string emailAddress);
	void printEmailAddress();

	int getAge();
	void setAge(int age);
	void printAge();

	int getDaysInCourse1();
	int getDaysInCourse2();
	int getDaysInCourse3();
	void setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3);
	void printDaysInCourse();

	DegreeProgram getDegreeProgram();
	void setDegreeProgram(DegreeProgram degreeProgram);
	void printDegreeProgram();

	void print();
};