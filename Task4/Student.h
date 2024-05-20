#pragma once

#include <set>
#include <vector>
#include <CString>
#include "pch.h"

using namespace std;

class Student
{
	private:
		CString _surname;
		set<Subject*, SubjectComparator> _subjects;
	public:
		Student(CString surname, Subject* subject);
		Student(CString surname);
		~Student();
		CString GetSurname();
		void AddSubject(Subject* subject);
		set<Subject*, SubjectComparator> GetSubjects();
};

