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
		// �������� ��������� ������ ���������
		// ���������� �� ���������
		// set<Subject>
		set<Subject*> subjects;
	public:
		string getSurname();
		set<Subject*> getSubjects();
};

