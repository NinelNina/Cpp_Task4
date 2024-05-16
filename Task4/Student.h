#pragma once

#include <set>
#include <vector>
#include <CString>
#include "Subject.h"

using namespace std;

class Student
{
	private:
		CString _surname;
		set<Subject*> _subjects;
	public:
		Student(CString surname, Subject* subject);
		Student(CString surname);
		~Student();
		CString getSurname();
		void addSubject(Subject* subject);
		set<Subject*> getSubjects();
};

