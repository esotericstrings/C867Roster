#include "student.h"

// softwareStudent publicly inheriting Student
class softwareStudent : public Student
{
private:
	Degree degreeType;
public:
	softwareStudent(string studentID, string firstName, string lastName, string emailAddress, int studentAge, vector<int> daysToComplete, Degree degreeType)
		: Student(studentID, firstName, lastName, emailAddress, studentAge, daysToComplete, degreeType) {
	};
	Degree getDegreeProgram();
};