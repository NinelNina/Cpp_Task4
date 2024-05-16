#pragma once
#include <iostream>
#include <fstream>
#include "Student.h"

using namespace std;

class StudentManager
{
private:
	vector<Student*> _students;
public:
	StudentManager();
	~StudentManager();
	
	void AddStudent(Student* student);
	const vector<Student*> GetStudents();
	vector<Student*> findStudents(vector<Subject*> learningSubjects, vector<Subject*> notlearningSubjects);
	//void inputFile(string filename);
};

