#pragma once
#include "Student.h"

class UniversityManager
{
private:
	vector<Student*> students;
	vector<Subject*> subjects;
public:
	vector<Student*> findStudents(vector<Subject*> learningSubjects, vector<Subject*> notlearningSubjects);
	void addStudent();
	void addSubject();
	void parseFile(); //точно здесь?
};

