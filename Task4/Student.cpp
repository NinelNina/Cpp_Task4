#include "pch.h"
#include "Student.h"

Student::Student(string surname) {
	_surname = surname;
}

Student::Student(string surname, Subject* subject) {
	_surname = surname;
	_subjects.insert(subject);
}

string Student::getSurname() {
	return _surname;
}

set<Subject*> Student::getSubjects(){
	return _subjects;
}

Student::~Student() {
	for (auto subject : _subjects) {
		delete subject;
	}
	_subjects.clear();
}

void Student::addSubject(Subject* subject) {
	_subjects.insert(subject);
}