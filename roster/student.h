#ifndef Student_H
#define Student_H
#include <iostream>
#include <string>
#include <vector>
#include "degree.h"

using namespace std;

class Student {
    private:
		string studentID;
		string firstName;
		string lastName;
		string emailAddress;
		int studentAge;
		vector<int> daysToComplete;
		Degree degree;

	public:
		Student(string studentID, string firstName, string lastName, string emailAddress, int studentAge, vector<int> daysToComplete, Degree degree);
		//accessors
		string getId();
		string getFirstName();
		string getLastName();
		string getEmail();
		int getAge();
		vector<int> getDaysToComplete();
		//mutators
		void setId(string);
		void setFirstName(string);
		void setLastName(string);
		void setEmail(string);
		void setAge(int);
		void setDaysToComplete(vector<int>);
		void setDegreeType(Degree);
		//constructors
		virtual void print();
		virtual void printId();
		virtual void printFirstName();
		virtual void printLastName();
		virtual void printEmail();
		virtual void printAge();
		virtual void printDaysToComplete();
		virtual void printDegree();
		//virtual getDegreeProgram()
		virtual Degree getDegreeProgram()=0;
		//destructor
		~Student();
};

#endif