#pragma once
#include <iostream>
#include <fstream>
#include "Student.h"

using namespace std;

class UniversityManager
{
private:
	vector<Student*> _students;
	vector<Subject*> _subjects;
	//void addStudent();
	//void addSubject();
public:
	UniversityManager();
	~UniversityManager();
	vector<Student*> findStudents(vector<Subject*> learningSubjects, vector<Subject*> notlearningSubjects);
	void inputFile(string filename);
};

