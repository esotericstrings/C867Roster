#include "student.h"

Student::Student(
	string studentID, 
	string firstName, 
	string lastName, 
	string emailAddress,
	int studentAge,
	vector<int> daysToComplete,
	Degree degree
){
	studentID = "";
	firstName = "";
	lastName = "";
	emailAddress = "";
	studentAge = 0;
	daysToComplete = {};
}
Student::~Student() {
}
string Student::getId() {
	return studentID;
}
string Student::getFirstName() {
	return firstName;
}
string Student::getLastName() {
	return lastName;
}
int Student::getAge() {
	return studentAge;
}
string Student::getEmail() {
	return emailAddress;
}
vector<int> Student::getDaysToComplete() {
	return daysToComplete;
}
void Student::setId(string id) {
	studentID = id;
}
void Student::setFirstName(string first) {
	firstName = first;
}
void Student::setLastName(string last) {
	lastName = last;
}
void Student::setEmail(string email) {
	emailAddress = email;
}
void Student::setAge(int age) {
	studentAge = age;
}
void Student::setDaysToComplete(vector<int >daysComplete) {
	daysToComplete = daysComplete;
}
void Student::setDegreeType(Degree studentDegree) {
	degree = studentDegree;
}
void Student::print() {
	Student::printFirstName();
	cout << "	";
	Student::printLastName();
	cout << "	";
	Student::printAge();
	cout << "	";
	Student::printDaysToComplete();
	cout << "	";
	Student::printDegree();
	cout << "	";
}
void Student::printId() {
	cout << "Student ID: " << studentID;
}
void Student::printFirstName() {
	cout << "First Name: " << firstName;
}
void Student::printLastName() {
	cout << "Last Name: " << lastName;
}
void Student::printEmail() {
	cout << "Email: " << emailAddress;
}
void Student::printAge() {
	cout << "Age: " << studentAge;
}
void Student::printDaysToComplete() {
	cout << "daysInCourse: {";
	for (int i = 0; i < size(daysToComplete); i++)
	{
		cout << daysToComplete[i];
		if (i < size(daysToComplete) - 1) {
			cout << ", ";
		}
	}
	cout << "}";
}
void Student::printDegree() {
	cout << "Degree Program: ";
	if (degree == 0) {
		cout << "Security";
	}
	else if (degree == 1) {
		cout << "Network";
	}
	else if (degree == 2) {
		cout << "Software";
	}
}