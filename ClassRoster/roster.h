#pragma once
#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"

#ifndef ROSTER_H
#define ROSTER_H

class Roster {
private:
	int capacity = 10;
	int size = 0;
	Student* roster[10];
public:
	Roster();
	void add(string studentID, string firstName, string lastName, string email, int age, int* days, DegreeProgram degreeprogram);
	void remove(string studentID);
	void printAll();
	void printAverageDaysInCourse(string studentID);
	void printInvalidEmails();
	void printByDegreeProgram(DegreeProgram degreeProgram);
	~Roster();
};

#endif