#include <iostream>
#include <string>
#include <algorithm>
#include "securityStudent.h"
#include "networkStudent.h"
#include "softwareStudent.h"
#include "roster.h"
using namespace std;

Roster::~Roster() {
	for (int i = 0; i < rosterSize; i++) {
		delete classRosterArray[i];
	}
}

void Roster::add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree) {
	Roster::rosterSize += 1;
	if (degree == SECURITY) {
		securityStudent* newStudent = new securityStudent(studentID, firstName, lastName, emailAddress, age, { daysInCourse1 , daysInCourse2, daysInCourse3 }, degree);
		newStudent->setId(studentID);
		newStudent->setFirstName(firstName);
		newStudent->setLastName(lastName);
		newStudent->setEmail(emailAddress);
		newStudent->setAge(age);
		newStudent->setDaysToComplete({ daysInCourse1 , daysInCourse2, daysInCourse3 });
		newStudent->setDegreeType(degree);
		for (int i = 0; i < rosterSize; i++)
		{
			if (classRosterArray[i] == nullptr) {
				classRosterArray[i] = newStudent;
				break;
			}
		}
	}
	else if (degree == NETWORK) {
		networkStudent* newStudent = new networkStudent(studentID, firstName, lastName, emailAddress, age, { daysInCourse1 , daysInCourse2, daysInCourse3 }, degree);
		newStudent->setId(studentID);
		newStudent->setFirstName(firstName);
		newStudent->setLastName(lastName);
		newStudent->setEmail(emailAddress);
		newStudent->setAge(age);
		newStudent->setDaysToComplete({ daysInCourse1 , daysInCourse2, daysInCourse3 });
		newStudent->setDegreeType(degree);
		for (int i = 0; i < rosterSize; i++)
		{
			if (classRosterArray[i] == nullptr) {
				classRosterArray[i] = newStudent;
				break;
			}
		}
	}
	else {
		softwareStudent* newStudent = new softwareStudent(studentID, firstName, lastName, emailAddress, age, { daysInCourse1 , daysInCourse2, daysInCourse3 }, degree);
		newStudent->setId(studentID);
		newStudent->setFirstName(firstName);
		newStudent->setLastName(lastName);
		newStudent->setEmail(emailAddress);
		newStudent->setAge(age);
		newStudent->setDaysToComplete({ daysInCourse1 , daysInCourse2, daysInCourse3 });
		newStudent->setDegreeType(degree);
		for (int i = 0; i < rosterSize; i++)
		{
			if (classRosterArray[i] == nullptr) {
				classRosterArray[i] = newStudent;
				break;
			}
		}
	}
}

void Roster::remove(string id) {

	bool removedIndex = false;
	for ( int i = 0; i < rosterSize; i++ )
	{
		if ( id == classRosterArray[i]->getId() ) {
			classRosterArray[i] = classRosterArray[i + 1];
			removedIndex = true;
		}
		if (removedIndex) {
			classRosterArray[i] = classRosterArray[i + 1];
			if (i == rosterSize - 1) {
				classRosterArray[i + 1] = nullptr;
				rosterSize -= 1;
			}
		}
	}

	if (!removedIndex) {
		cout << "Student with this ID was not found!" << endl;
	}
}

void Roster::printDaysInCourse(string studentID) {
	for (int i = 0; i < rosterSize; i++)
	{
		if (classRosterArray[i]->getId() == studentID) {
			vector<int> courseDays = classRosterArray[i]->getDaysToComplete();
			int averageDays = 0;
			for ( int k = 0; k < size(courseDays); k++ ) {
				averageDays += courseDays[k];
			}
			averageDays = averageDays / size(courseDays);
			cout << averageDays;
			break;
		}
	}
}

void Roster::printAll() {
	for (int i = 0; i < rosterSize; i++)
	{
		if (classRosterArray[i] != NULL) {
			cout << i + 1 << "	";
			classRosterArray[i]->print();
		}
	}
	cout << endl;
}

void Roster::printInvalidEmails() {
	cout << "Invalid emails: " << endl;
	for (int i = 0; i < rosterSize; i++)
	{
		bool has_period = classRosterArray[i]->getEmail().find('.') != std::string::npos;
		bool has_at = classRosterArray[i]->getEmail().find('@') != std::string::npos;
		bool has_space = classRosterArray[i]->getEmail().find(' ') != std::string::npos;
		//print out invalid emails, which have a space, or do not have a period or @
		if (!has_period || !has_at || has_space) {
			classRosterArray[i]->printEmail();
			cout << endl;
		}
	}
	cout << endl;
}
void Roster::printByDegreeProgram(Degree degreeProgram) {
	for (int i = 0; i < rosterSize; i++)
	{
		if (classRosterArray[i]->getDegreeProgram() == degreeProgram) {
			classRosterArray[i]->print();
			cout << endl;
		}
	}
	cout << endl;
}
void main() {
	const string studentData[] =
	{ "A1,John,Smith,John1989@gm ail.com,20,30,35,40,SECURITY",
	"A2,Suzan,Erickson,Erickson_1990@gmailcom,19,50,30,40,NETWORK",
	"A3,Jack,Napoli,The_lawyer99yahoo.com,19,20,40,33,SOFTWARE",
	"A4,Erin,Black,Erin.black@comcast.net,22,50,58,40,SECURITY",
	"A5,Jamie,Huang,jhuan19@wgu.edu,25,50,58,40,SOFTWARE" };
	
	cout << " SCRIPTING AND PROGRAMMING APPLICATIONS C867 " << endl;
	cout << "              Language Used: C++            " << endl;
	cout << "            Student ID: #001195694          " << endl;
	cout << "          Student Name: Jamie Huang         " << endl;
	cout << "============================================" << endl;
	cout << endl;
	cout << "FPP1 TASK 1: CLASS ROSTER" << endl;
	cout << endl;

	Roster classRoster;

	for (int i = 0; i < size(studentData); i++) {
		string studentstring = studentData[i].substr(studentData[i].find(",") + 1);
		string namestr = studentstring.substr(studentstring.find(",") + 1);
		string emailstr = namestr.substr(namestr.find(",") + 1);
		string agestr = emailstr.substr(emailstr.find(",") + 1);
		string course1str = agestr.substr(agestr.find(",") + 1);
		string course2str = course1str.substr(course1str.find(",") + 1);
		string course3str = course2str.substr(course2str.find(",") + 1);

		string studentId = studentData[i].substr(0, studentData[i].find(","));
		string firstName = studentstring.substr(0, studentstring.find(","));
		string lastName = namestr.substr(0, (namestr).find(","));
		string email = emailstr.substr(0, (emailstr).find(","));
		string degree = course3str.substr(course3str.find(",") + 1);

		int ageYears = stoi(agestr.substr(0, (agestr).find(",")));
		int course1Days = stoi(course1str.substr(0, (course1str).find(",")));
		int course2Days = stoi(course2str.substr(0, (course2str).find(",")));
		int course3Days = stoi(course3str.substr(0, (course3str).find(",")));

		if (degree == "SECURITY") {
			classRoster.add(studentId, firstName, lastName, email, ageYears, course1Days, course2Days, course3Days, SECURITY);
		}
		else if (degree == "NETWORK") {
			classRoster.add(studentId, firstName, lastName, email, ageYears, course1Days, course2Days, course3Days, NETWORK);
		}
		else if (degree == "SOFTWARE") {
			classRoster.add(studentId, firstName, lastName, email, ageYears, course1Days, course2Days, course3Days, SOFTWARE);
		}

	}

	classRoster.printAll();
	classRoster.printInvalidEmails();

	//loop through classRosterArray and for each element:
	for (int j = 0; j < classRoster.rosterSize; j++) {
		cout << "Average Days in Courses for Student " << classRoster.classRosterArray[j]->getId() << ": ";
		classRoster.printDaysInCourse(classRoster.classRosterArray[j]->getId());
		cout << endl;
	}
	cout << endl;
	classRoster.printByDegreeProgram(SOFTWARE);
	classRoster.remove("A3");
	classRoster.remove("A3");
	classRoster.printAll();

}