#pragma once
#include <iostream>
#include <string>
#include "degree.h"
using namespace std;

#ifndef STUDENT_H
#define STUDENT_H

class Student {
	private:
		string studentID;
		string firstName;
		string lastName;
		string email;
		int age;
		int days[3];
		DegreeProgram degreeProgram;
	public:
		Student(string studentIDS, string firstNameS, string lastNameS, string emailS, int ageS, int* daysS, DegreeProgram degreeProgramS);
		void SetID(string studentIDS);
		void SetFirstName(string firstNameS);
		void SetLastName(string lastNameS);
		void SetEmail(string emailS);
		void SetAge(int ageS);
		void SetDays(int* daysS);
		void SetDegreeProgram(DegreeProgram degreeProgramS);
		string GetID();
		string getFirstName();
		string getLastName();
		string getEmail();
		int GetAge();
		int* GetDays();
		DegreeProgram GetDegreeProgram();
		void print();
		~Student();
};

#endif