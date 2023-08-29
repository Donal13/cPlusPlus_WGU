#include <iostream>
#include "degree.h"
#include "roster.h"
#include "student.h"

using namespace std;

int main() {

	int numberStudents = 5;

// F.1. Print out course and student info
	cout << " Course Title: Scripting and Programing - Applications C867" << endl;
	cout << "\t \tProgramming Language Used: C++" << endl;
	cout << "\t \tWGU Student Number: 010193498" << endl;
	cout << " \t Student Programmer's Name: Donal Schultz" << endl << endl << endl;
	
// Student Data Table - modified with my own info
	const string studentData[] = {
		"A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
		"A2,Suzan,Erickson,Erickson_1990@gmail.com,19,50,30,40,NETWORK",
		"A3,Jack,Napoli,The_Lawyer99yahoo.com,19,20,40,33,SOFTWARE",
		"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
		"A5,Donal,Schultz,dschu91@my.wgu.edu,42,30,31,28,SOFTWARE"
	};

// F.2. Create roster class instance "classRoster"
	Roster classRoster;

	cout << " All Student's in the Roster:" << endl;
	for (int i = 0; i < numberStudents; i++) {
	classRoster.parse(studentData[i]);
	}
	classRoster.printAll();
	cout << endl << endl;
	
// F.4. Print functions
	cout << " Student's email is Invalid:" << endl;
	classRoster.printInvalidEmails();
	cout << endl << endl;

	cout << " Average days spent per course:" << endl;
	for (int i = 0; i < numberStudents; i++) {
		classRoster.printAvgDays(classRoster.classRosterArray[i]->getstudentID());
	}
	cout << endl << endl;

	cout << " Students in the Software program:";
	classRoster.printByDegree(SOFTWARE);
	cout << endl << endl;

// F.4. Removal functions
	cout << " Remove student A3" << endl;
	classRoster.remove("A3");
	cout << endl << endl;

	cout << " Remove already non-existent student A3" << endl;
	classRoster.remove("A3");
	cout << endl << endl;

}