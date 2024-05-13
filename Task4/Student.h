#pragma once

#include <set>
#include <vector>
#include <string>
#include "Subject.h"

using namespace std;

class Student
{
	private:
		string surname;
		set<Subject*> subjects;
	public:
		Student(string surname, Subject* subject);
		Student(string surname);
		~Student();
		string getSurname();
		void addSubject(Subject* subject);
		set<Subject*> getSubjects();
};

