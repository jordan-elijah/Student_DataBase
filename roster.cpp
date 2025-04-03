#include "roster.h"
#include <stdio.h>
#include <iostream>
#include <map>
#include "student.h"
using namespace std;


roster::roster(int classCapacity) {

	this->classCapacity = classCapacity;
	this->slot = 0;
	for (int n = 0; n < classCapacity; n++) {
		this->classRosterArray[n] = new student;
	}
	return;
}

string roster::getStudentClassID(int slot) {

	string studentID = classRosterArray[slot]->getStudentID();
	return studentID;
}

roster::roster()
{

}

//descructor for the release of memory
roster::~roster()
{
	return;
}

//Parse Function Defined here: uses find to locate commas in between strings, uses substring to measure 
//alongside "first" and "next" to determine previous strings for accuracy, proceeds then with passing 
// found data along to the set functions to be used with our print function
void roster::parse(string studentDataTable)
{
	string studentID, firstName, lastName, emailAddress;
	int age, daysInCourse1, daysInCourse2, daysInCourse3;


	if (slot < classCapacity) {

		classRosterArray[slot] = new student();

		int first = studentDataTable.find(",");
		studentID = studentDataTable.substr(0, first);
		classRosterArray[slot]->setStudentID(studentID);

		int next = first + 1;
		first = studentDataTable.find(",", next);
		firstName = studentDataTable.substr(next, first - next);
		classRosterArray[slot]->setFirstName(firstName);

		next = first + 1;
		first = studentDataTable.find(",", next);
		lastName = studentDataTable.substr(next, first - next);
		classRosterArray[slot]->setLastName(lastName);

		next = first + 1;
		first = studentDataTable.find(",", next);
		emailAddress = studentDataTable.substr(next, first - next);
		classRosterArray[slot]->setEmailAddress(emailAddress);

		next = first + 1;
		first = studentDataTable.find(",", next);
		age = stoi(studentDataTable.substr(next, first - next));
		classRosterArray[slot]->setAge(age);

		next = first + 1;
		first = studentDataTable.find(",", next);
		daysInCourse1 = stoi(studentDataTable.substr(next, first - next));

		next = first + 1;
		first = studentDataTable.find(",", next);
		daysInCourse2 = stoi(studentDataTable.substr(next, first - next));

		next = first + 1;
		first = studentDataTable.find(",", next);
		daysInCourse3 = stoi(studentDataTable.substr(next, first - next));
		classRosterArray[slot]->setDaysInCourse(daysInCourse1, daysInCourse2, daysInCourse3);

		next = first + 1;
		first = studentDataTable.find(",", next);
		string degree = studentDataTable.substr(next, first - next);
		
		if (degree == "SOFTWARE") {
			classRosterArray[slot]->setDegreeProgram(SOFTWARE);
		}
		else if (degree == "SECURITY") {
			classRosterArray[slot]->setDegreeProgram(SECURITY);
		}
		else if (degree == "NETWORK") {
			classRosterArray[slot]->setDegreeProgram(NETWORK);
		}
		else {
			cout << "Degree not found" << endl;
		}
		slot++;
	}

}
//add function to be used with print()
// specifies array to be used properly for main.cpp outputs
void roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1,int daysInCourse2,int daysInCourse3, DegreeProgram degreeProgram)
{

	int daysInCourse[3] = {daysInCourse1, daysInCourse2, daysInCourse3};

	classRosterArray[classCapacity] = new student(studentID, firstName, lastName, emailAddress, age, daysInCourse, degreeProgram);

	

}

//checks if student is in the system, does so only if class capacity hasnt been met/ student has been found within class capacirt with invalid credentials
void roster::removeStudent(string studentID)
{
	bool found = false;
	int n = 0;

	while (found != true && n < classCapacity) {
		if (classRosterArray[n]->getStudentID() == studentID) {
			cout << "Invalid Student Found! " << classRosterArray[n]->getStudentID() << " - Removed." << endl;
			delete classRosterArray[n];
			found = true;
			for (int j = n; j < classCapacity - 1; j++) {
				classRosterArray[j] = classRosterArray[j + 1];
			}
			classCapacity--;
		}
		else {
			n++;
		}
	}

	if (found != true) {
		cout << studentID << " was not found." << endl;
	}

	return;
}
//Utilizes Print function to list all students and their associated information
void roster::printAll()
{
	cout << "Current Student Roster Now Showing: \n \n";
	for (int n = 0; n < classCapacity; n++) {
		roster::classRosterArray[n]->print();
	}
		
}
//averages out course completion time out by dividing by all classes length given. 
void roster::printAvgDaysInCourse(string studentID)
{

	for (int n = 0; n < classCapacity; n++) {
		if (studentID == classRosterArray[n]->getStudentID()) {
			cout << studentID << " \tAverage Course Time (In Days):\t" << 
				(classRosterArray[n]->getDaysInCourse1() +
				classRosterArray[n]->getDaysInCourse2() +
				classRosterArray[n]->getDaysInCourse3()) / 3 << endl;
		}
	}
	}

//finds email addresses with invalid characters; displays said emails on screen
void roster::printBadEmails()

{
	for (int n = 0; n < classCapacity; ++n) {
		string emailFinder = classRosterArray[n]->getEmailAddress();
		if ((emailFinder.find('@') == string::npos) || (emailFinder.find(' ') != string::npos) || (emailFinder.find('.') == string::npos)) {
			cout<< emailFinder << " - is invalid." << endl;
		}
	}
	cout << endl;
	return;
}
//filters and prints all students with specified degree type.
void roster::printViaDegreeType(DegreeProgram degreeProgram)
{
	for (int n = 0; n < classCapacity; n++) {
		if (classRosterArray[n]->getDegreeProgram() == SOFTWARE) {
			classRosterArray[n]->print();
		}

	}
}












