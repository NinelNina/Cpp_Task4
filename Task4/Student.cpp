#include "pch.h"
#include "Student.h"

Student::Student(CString surname) {
	_surname = surname;
}

Student::Student(CString surname, Subject* subject) {
	_surname = surname;
	_subjects.insert(subject);
}

CString Student::getSurname() {
	return _surname;
}

set<Subject*> Student::getSubjects(){
	return _subjects;
}

Student::~Student() {
	_subjects.clear();
}

void Student::addSubject(Subject* subject) {
	_subjects.insert(subject);
}