#include "pch.h"
#include "Student.h"

Student::Student(CString surname) {
	_surname = surname;
}

Student::Student(CString surname, Subject* subject) {
	_surname = surname;
	_subjects.insert(subject);
}

CString Student::GetSurname() {
	return _surname;
}

set<Subject*, SubjectComparator> Student::GetSubjects(){
	return _subjects;
}

Student::~Student() {
	_subjects.clear();
}

void Student::AddSubject(Subject* subject) {
	_subjects.insert(subject);
}