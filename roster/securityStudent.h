#include "student.h"

// securityStudent publicly inheriting Student
class securityStudent : public Student
{
private: 
	Degree degreeType;
public:
	securityStudent(string studentID, string firstName, string lastName, string emailAddress, int studentAge, vector<int> daysToComplete, Degree degreeType)
		: Student(studentID, firstName, lastName, emailAddress, studentAge, daysToComplete, degreeType) {
	};
	Degree getDegreeProgram();
};