#include "student.h"

//blank constuctor
student::student() {

	this->studentID = "";
	this->firstName = "";
	this->lastName = "";
	this->emailAddress = "";
	this->age = 0;
	for (int n = 0; n < numberOfClasses; n++) this->daysInCourse[n] = 0;
	this->degreeProgram = degreeProgram;

}

//Full Connstructor
student::student(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse[], DegreeProgram degreeProgram) {

	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int n = 0; n < numberOfClasses; n++) this->daysInCourse[n] = daysInCourse[n];
	this->degreeProgram = degreeProgram;

}
//descructor
student::~student() {}

// Setter,Getter,Printer for ID
void student::setStudentID(string studentID) {
 this->studentID = studentID;
 return;
}

string student::getStudentID() {
return studentID;
}

void student::printStudentID() {
	cout << studentID;
}



//Setter,Getter,Printer for First Name
void student::setFirstName(string firstName) {
	this->firstName = firstName;
	return;
}

string student::getFirstName() {
	return firstName;
}

void student::printFirstName() {
	cout << firstName;
}



//Setter,Getter,Printer for Last Name
void student::setLastName(string lastName) {
	this->lastName = lastName;
	return;
}

string student::getLastName() {
	return lastName;
}

void student::printLastName() {
	cout << lastName;
}




//Setter,Getter,Printer for Email Address
void student::setEmailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
	return;
}

string student::getEmailAddress() {
	return emailAddress;
}

void student::printEmailAddress() {
	cout << emailAddress;
}




//Setter,Getter,Printer for Student Age
void student::setAge(int age) {
	this->age = age;
	return;
}

int student::getAge() {
	return age;
}

void student::printAge() {
	cout << age;
}



//Setter,Getters,Printer for the Days In Course
void student::setDaysInCourse(int daysInCourse1, int daysInCourse2, int daysInCourse3) {
	this->daysInCourse[0] = daysInCourse1;
	this->daysInCourse[1] = daysInCourse2;
	this->daysInCourse[2] = daysInCourse3;
	return;
}

int student::getDaysInCourse1() {
	return daysInCourse[0];
}
int student::getDaysInCourse2() {
	return daysInCourse[1];
}
int student::getDaysInCourse3() {
	return daysInCourse[2];
}

void student::printDaysInCourse() {
	cout << daysInCourse[0] << ", " << daysInCourse[1] << ", " << daysInCourse[2] << endl;
	return;
}



//Setter,Getter,Printer for Degree Programs
void student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

DegreeProgram student::getDegreeProgram() {
	return degreeProgram;
}

void student::printDegreeProgram() {
	string degree;

	if (degreeProgram = SOFTWARE) {
		degree = "SOFTWARE";
	}
	else if (degreeProgram = NETWORK) {
		degree = "NETWORK";
	}
	else if  (degreeProgram = SECURITY) {
		degree = "SECURITY";
	}
	
}


//utilizes accessors and prints out specified  information for one student; created to be used with printAll function 
void student::print() {
	string degree;
	if (degreeProgram == SECURITY) {
		degree = "SECURITY";
	}
	else if (degreeProgram == SOFTWARE) {
		degree = "SOFTWARE";
	}
	else if (degreeProgram == NETWORK) {
		degree = "NETWORK";
	}

	cout << this->getStudentID() << '\t';
	cout << this->getFirstName() << '\t';
	cout << this->getLastName() << '\t';
	cout << this->getEmailAddress() << '\t';
	cout << this->getAge() << '\t';
	cout << this->getDaysInCourse1() << ',';
	cout << this->getDaysInCourse2() << ',';
	cout << this->getDaysInCourse3() << '\t';
	cout <<  degree << '\n';
}



