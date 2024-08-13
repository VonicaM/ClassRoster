#include <iostream>
#include <string>
#include "degree.h"
#include "student.h"
#include "roster.h"
using namespace std;

Roster::Roster() {

}

void Roster::add(string studentID, string firstName, string lastName, string email, int age, int* days, DegreeProgram degreeProgram) {
	Student* newStudent = new Student(studentID, firstName, lastName, email, age, days, degreeProgram);
	if (size < capacity) {
		roster[size] = newStudent;
		size++;
	}
	else {
		cout << "Roster is full." << endl;
	}
}

void Roster::remove(string studentID) {
	bool exist = false;
	int x = 0;
	for (x; x < size; x++) {
		if (roster[x]->GetID() == studentID) {
			exist = true;
			break;
		}
	}
	if (exist) {
		delete roster[x];
		x++;
		for (x; x < size; x++) {
			roster[x - 1] = roster[x];
		}
		size--;
	}
	else {
		cout << "There is no student with this ID." << endl;
	}
}

void Roster::printAll() {
	for (int x = 0; x < size; x++) {
		roster[x]->print();
	}
}

void Roster::printAverageDaysInCourse(string studentID) {
	int x = 0;
	for (x; x < size; x++) {
		if (roster[x]->GetID() == studentID) {
			break;
		}
		else if (x == size - 1) {
			cout << "There is no student with this ID." << endl;
			return;
		}
	}
	double average = (((double)*roster[x]->GetDays()) + (double)*(roster[x]->GetDays() + 1) + (double)*(roster[x]->GetDays() + 2))/3.0;
	cout << "The average days in course for " << studentID << " is " << average << " days." << endl;
}

void Roster::printInvalidEmails() {
	int i;
	for (int x = 0; x < size; x++) {
		i = roster[x]->getEmail().length();
		if (!(roster[x]->getEmail().find('.') < i && roster[x]->getEmail().find('@') < i) || roster[x]->getEmail().find(' ') < i) {
			cout << roster[x]->getEmail() << endl;
		}
	}
}

void Roster::printByDegreeProgram(DegreeProgram degreeProgram) {
	for (int x = 0; x < size; x++) {
		if (roster[x]->GetDegreeProgram() == degreeProgram) {
			roster[x]->print();
		}
	}
}

Roster::~Roster() {
	for (int x = 0; x < size; x++) {
		delete roster[x];
	}
}