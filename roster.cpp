#include <string>
#include <iostream>
#include "roster.h"
#include "student.h"

using namespace std;

// E.2. Extract each string from the student data table by comma delimiter
void Roster::parse(string studentData) {
// studentID
	int rightSide = studentData.find(",");
	string studentID = studentData.substr(0, rightSide);
// firstName
	int leftSide = rightSide + 1;
	rightSide = studentData.find(",", leftSide);
	string firstName = studentData.substr(leftSide, rightSide - leftSide);
// lastName
	leftSide = rightSide + 1;
	rightSide = studentData.find(",", leftSide);
	string lastName = studentData.substr(leftSide, rightSide - leftSide);
// email
	leftSide = rightSide + 1;
	rightSide = studentData.find(",", leftSide);
	string emailAddress = studentData.substr(leftSide, rightSide - leftSide);
// age
	leftSide = rightSide + 1;
	rightSide = studentData.find(",", leftSide);
	int age = stoi(studentData.substr(leftSide, rightSide - leftSide));
// daysCouse1
	leftSide = rightSide + 1;
	rightSide = studentData.find(",", leftSide);
	int daysCourse1 = stoi(studentData.substr(leftSide, rightSide - leftSide));
// daysCourse2
	leftSide = rightSide + 1;
	rightSide = studentData.find(",", leftSide);
	int daysCourse2 = stoi(studentData.substr(leftSide, rightSide - leftSide));
// daysCourse3
	leftSide = rightSide + 1;
	rightSide = studentData.find(",", leftSide);
	int daysCourse3 = stoi(studentData.substr(leftSide, rightSide - leftSide));
	
// Determining the degree program
	leftSide = rightSide + 1;
	rightSide = studentData.find(",", leftSide);
	string degreeString = studentData.substr(leftSide, rightSide - leftSide);

	DegreeProgram degreeProgram{};
	if (degreeString.substr() == "SECURITY") {
		degreeProgram = SECURITY;
	}
	if (degreeString.substr() == "NETWORK") {
		degreeProgram = NETWORK;
	}
	if (degreeString.substr() == "SOFTWARE") {
		degreeProgram = SOFTWARE;
	}

	add(studentID, firstName, lastName, emailAddress, age, daysCourse1, daysCourse2, daysCourse3, degreeProgram);

}

// E.3.a. Set instance variables and update the roster
void Roster::add(
	string studentID, string firstName, string lastName, string emailAddress,
	int age, int daysCourse1, int daysCourse2, int daysCourse3,
	DegreeProgram degreeProgram) {

	double daysArray[] = { static_cast<double>(daysCourse1), static_cast<double>(daysCourse2), static_cast<double>(daysCourse3) };
	classRosterArray[++position] = new Student(studentID, firstName, lastName, emailAddress, age, daysArray, degreeProgram);
}

// E.3.b. Remove students from roster by studentID
void Roster::remove(string studentID) {
	bool eval = false;

	for (int i = 0; i <= Roster::position; i++) {
		if (classRosterArray[i]->getstudentID() == studentID) {
			eval = true;
			if (i < numberStudents - 1) {
				Student* temp = classRosterArray[i];
				classRosterArray[i] = classRosterArray[numberStudents - 1];
				classRosterArray[numberStudents - 1] = temp;
			}
			Roster::position--;
		}
	}
	if (eval) {
		cout << "Student: " << studentID << " was removed from the roster." << endl;
	}
	else
		cout << "Student: " << studentID << " was not found." << endl;
}

// E.3.c. Print complete tab-separated list of student data
void Roster::printAll() {
	for (int i = 0; i <= Roster::position; i++) {
		classRosterArray[i]->print();
	}
}

// E.3.d. Print average number of days student was enrolled in courses
void Roster::printAvgDays(string studentID) {
	for (int i = 0; i <= Roster::position; i++) {
		if (this->classRosterArray[i]->getstudentID() == studentID) {
			cout << "Student with ID " << classRosterArray[i]->getstudentID();
			int avgDays = (classRosterArray[i]->getnumberOfDays()[0] + classRosterArray[i]->getnumberOfDays()[1] + classRosterArray[i]->getnumberOfDays()[2]) / 3.0;
			cout << " averages: " << avgDays << " days per course." << endl;
		}
	}
}

// E.3.e. Print students with an invalid email
void Roster::printInvalidEmails() {
	bool eval2 = false;
	for (int i = 0; i <= Roster::position; i++) {
		string emailTest = (classRosterArray[i]->getemailAddress());
		if ((emailTest.find('@') == string::npos) || (emailTest.find(' ') != string::npos) || (emailTest.find('.') == string::npos)) {
			eval2 = true;
			cout << "Invalid email addresses: " << classRosterArray[i]->getemailAddress() << endl;
		}
	}
	if (!eval2) {
		cout << "None invalid." << endl;
	}
}

// E.3.f. Print student info by degree program
void Roster::printByDegree(DegreeProgram degreeProgram) {
	for (int i = 0; i <= Roster::position; i++) {
		if (Roster::classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
		}
		cout << endl;
	}
}

// F.5. Implement the destructor
Roster::~Roster() {
	for (int i = 0; i < numberStudents; i++) {
		cout << i + 1 << " was removed." << endl;
		delete classRosterArray[i];
		classRosterArray[i] = nullptr;
	}
}