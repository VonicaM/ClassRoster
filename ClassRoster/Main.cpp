// ClassRoster.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <sstream>
#include "degree.h"
#include "student.h"
#include "roster.h"
using namespace std;

int main()
{
    const string studentData[] = { "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY", "A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK", "A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE", "A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY", "A5,Michael,Vonica,michaelvonica@puppies.net,20,50,58,40,SOFTWARE" };
    cout << "SCRIPTING AND PROGRAMMING - APPLICATIONS � C867, C++, ID# 001464347, Michael Vonica" << endl;
    Roster classRoster;
	string studentID;
	string firstName;
	string lastName;
	string email;
	int age;
	string age_str;
	int days[3];
	string day1;
	string day2;
	string day3;
	DegreeProgram degreeProgram;
	string degreeProgram_str;
    for (int x = 0; x < sizeof(studentData) / sizeof(studentData[0]); x++) {
		stringstream s_stream(studentData[x]);
		getline(s_stream, studentID, ',');
		getline(s_stream, firstName, ',');
		getline(s_stream, lastName, ',');
		getline(s_stream, email, ',');
		getline(s_stream, age_str, ',');
		age = stoi(age_str);
		getline(s_stream, day1, ',');
		days[0] = stoi(day1);
		getline(s_stream, day2, ',');
		days[1] = stoi(day2);
		getline(s_stream, day3, ',');
		days[2] = stoi(day3);
		getline(s_stream, degreeProgram_str, ',');
		if (degreeProgram_str == "SECURITY") {
			degreeProgram = SECURITY;
		}
		else if (degreeProgram_str == "NETWORK") {
			degreeProgram = NETWORK;
		}
		else {
			degreeProgram = SOFTWARE;
		}
		classRoster.add(studentID, firstName, lastName, email, age, days, degreeProgram);
    }
	classRoster.printAll();
	cout << endl;
	classRoster.printInvalidEmails();
	cout << endl;
	classRoster.printAverageDaysInCourse("A1");
	classRoster.printAverageDaysInCourse("A2");
	classRoster.printAverageDaysInCourse("A3");
	classRoster.printAverageDaysInCourse("A4");
	classRoster.printAverageDaysInCourse("A5");
	cout << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	cout << endl;
	classRoster.remove("A3");
	classRoster.printAll();
	cout << endl;
	classRoster.remove("A3");
	return 0;
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
