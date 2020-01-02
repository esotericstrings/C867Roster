#include "student.h"

// networkStudent publicly inheriting Student
class networkStudent : public Student
{
private:
	Degree degreeType;
public:
	networkStudent(string studentID, string firstName, string lastName, string emailAddress, int studentAge, vector<int> daysToComplete, Degree degreeType)
		: Student(studentID, firstName, lastName, emailAddress, studentAge, daysToComplete, degreeType) {
	};
	Degree getDegreeProgram();
};