#include "student.h"
#include "degree.h"

class Roster {
	public:
		~Roster();
		int rosterSize = 0;
		Student* classRosterArray[20] = { nullptr };
		void add(string studentID, string firstName, string lastName, string emailAddress, int age, int daysInCourse1, int daysInCourse2, int daysInCourse3, Degree degree);
		void remove(string studentID);
		void printDaysInCourse(string studentID);
		void printAll();
		void printInvalidEmails();
		void printByDegreeProgram(Degree degreeProgram);
};