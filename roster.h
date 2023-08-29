#pragma once
#include "student.h"

using namespace std;

// E. Create a Roster class
class Roster {

	public:

		int position = -1;

		const static int numberStudents = 5;

// E.1. Create classRosterArray to hold student data
		Student* classRosterArray[numberStudents];

	public:

		void parse(string row);
		void add(string studentID, string firstName, string lastName, string emailAddress,
			int age, int daysCourse1, int daysCourse2, int daysCourse3,
			DegreeProgram degreeProgram);
		void remove(string studentID);
		void printAll();
		void printByDegree(DegreeProgram degreeProgram);
		void printAvgDays(string studentID);
		void printInvalidEmails();
		~Roster();

};