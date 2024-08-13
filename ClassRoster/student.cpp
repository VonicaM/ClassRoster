#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
using namespace std;

Student::Student(string studentIDS, string firstNameS, string lastNameS, string emailS, int ageS, int* daysS, DegreeProgram degreeProgramS) {
	studentID = studentIDS;
	firstName = firstNameS;
	lastName = lastNameS;
	email = emailS;
	age = ageS;
	days[0] = *daysS; days[1] = *(daysS+1); days[2] = *(daysS+2);
	degreeProgram = degreeProgramS;
}

void Student::SetID(string studentIDS) {
	studentID = studentIDS;
}

void Student::SetFirstName(string firstNameS) {
	firstName = firstNameS;
}

void Student::SetLastName(string lastNameS) {
	lastName = lastNameS;
}

void Student::SetEmail(string emailS) {
	email = emailS;
}

void Student::SetAge(int ageS) {
	age = ageS;
}

void Student::SetDays(int* daysS) {
	days[0] = *daysS; days[1] = *(daysS+1); days[2] = *(daysS+2);
}

void Student::SetDegreeProgram(DegreeProgram degreeProgramS) {
	degreeProgram = degreeProgramS;
}

string Student::GetID() {
	return studentID;
}

string Student::getFirstName() {
	return firstName;
}

string Student::getLastName() {
	return lastName;
}

string Student::getEmail() {
	return email;
}

int Student::GetAge() {
	return age;
}

int* Student::GetDays() {
	return &days[0];
}

DegreeProgram Student::GetDegreeProgram() {
	return degreeProgram;
}

void Student::print() {
	string degreeProgram_str;
	switch (degreeProgram) {
		case SECURITY:
			degreeProgram_str = "SECURITY";
			break;
		case NETWORK:
			degreeProgram_str = "NETWORK";
			break;
		case SOFTWARE:
			degreeProgram_str = "SOFTWARE";
			break;
	}
	cout << studentID << " \t First Name: " << firstName << " \t Last Name: " << lastName << " \t Age: " << age << " \t daysInCourse: {" << days[0] << ", " << days[1] << ", " << days[2] << "} Degree Program: " << degreeProgram_str << "." << endl;
}

Student::~Student() {
	
}