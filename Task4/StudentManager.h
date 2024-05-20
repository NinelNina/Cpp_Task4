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
	void AddStudent(CString surname, Subject* subject);
	const vector<Student*> GetStudents();
	Student* FindStudentBySurname(const CString& surname);
	vector<Student*> FindStudents(vector<Subject*> learningSubjects, vector<Subject*> notlearningSubjects);
};

