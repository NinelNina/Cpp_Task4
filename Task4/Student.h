#pragma once

#include <string>
#include <set>
#include <vector>
#include <string>
#include "Subject.h"

using namespace std;

class Student
{
	private:
		string surname;
		// добавить отдельный список предметов
		// сравнивать по указателю
		// set<Subject>
		set<Subject*> subjects;
	public:
		string getSurname();
		set<Subject*> getSubjects();
};

