#include"student.h"

using namespace std;

// D.2.d. Student constructor
Student::Student(string studentID, string firstName, string lastName, string emailAddress,
	int age, double numberOfDays[],
	DegreeProgram degreeProgram) {
	this->studentID = studentID;
	this->firstName = firstName;
	this->lastName = lastName;
	this->emailAddress = emailAddress;
	this->age = age;
	for (int i = 0; i < courseDays; i++) {
		this->numberOfDays[i] = numberOfDays[i];
	}
	this->degreeProgram = degreeProgram;
}

// D.2.a. Getter - accessors
string Student::getstudentID() {
	return this->studentID;
}
string Student::getfirstName() {
	return this->firstName;
}
string Student::getlastName() {
	return this->lastName;
}
string Student::getemailAddress() {
	return this->emailAddress;
}
int Student::getage() {
	return this->age;
}
double* Student::getnumberOfDays() {
	return this->numberOfDays;
}
DegreeProgram Student::getDegreeProgram() {
	return this->degreeProgram;
}

// D.2.b. Setter - mutators
void Student::setstudentID(string studentID) {
	this->studentID = studentID;
}
void Student::setfirstName(string firstName) {
	this->firstName = firstName;
}
void Student::setlastName(string lastName) {
	this->lastName = lastName;
}
void Student::setemailAddress(string emailAddress) {
	this->emailAddress = emailAddress;
}
void Student::setage(int age) {
	this->age = age;
}
void Student::setnumberOfDays(double numberOfDays[]) {
	for (int i = 0; i < courseDays; i++) {
		this->numberOfDays[i] = numberOfDays[i];
	}
}
void Student::setDegreeProgram(DegreeProgram degreeProgram) {
	this->degreeProgram = degreeProgram;
}

// D.2.e. Print specific data & E.3.c Using a tab-separated list
void Student::print() {
	cout << this->getstudentID() << '\t';
	cout << "First Name: " << this->getfirstName() << '\t';
	cout << "Last Name: " << this->getlastName() << '\t';
	cout << "Email: " << this->getemailAddress() << '\t';
	cout << "Age: " << this->getage() << '\t';
	cout << "Days Per Course: (" << this->getnumberOfDays()[0] << ", ";
	cout << this->getnumberOfDays()[1] << ", ";
	cout << this->getnumberOfDays()[2] << ") ";
	cout << "Degree Program: " << degreeProgramStrings[this->getDegreeProgram()] << endl;
}

// Destructor
Student::~Student() {}