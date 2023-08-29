#pragma once
#include <iostream>
#include "degree.h"

using namespace std;

// D.1. Create Student Class
class Student {

public:
	const static int courseDays = 3;

private:
	string studentID;
	string firstName;
	string lastName;
	string emailAddress;
	int age;
	double numberOfDays[courseDays];
	DegreeProgram degreeProgram;

public:

// Getters
	string getstudentID();
	string getfirstName();
	string getlastName();
	string getemailAddress();
	int getage();
	double* getnumberOfDays();
	DegreeProgram getDegreeProgram();

// Setters
	void setstudentID(string studentID);
	void setfirstName(string firstName);
	void setlastName(string lastName);
	void setemailAddress(string emailAddress);
	void setage(int age);
	void setnumberOfDays(double numberOfDays[]);
	void setDegreeProgram(DegreeProgram degreeProgram);

// Constructor, Parameters, Destructor
	Student();
	Student(string studentID, string firstName, string lastName, string emailAddress,
		int age, double numberDays[],
		DegreeProgram degreeProgram);
	~Student();

// Print
	void print();

};