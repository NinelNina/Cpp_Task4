#include "pch.h"
#include "Student.h"

Student::Student(string surname) {
	this->surname = surname;
}

Student::Student(string surname, Subject* subject) {
	this->surname = surname;
	this->subjects.insert(subject);
}

string Student::getSurname() {
	return surname;
}

set<Subject*> Student::getSubjects(){
	return subjects;
}

Student::~Student() {
	for (auto subject : subjects) {
		delete subject;
	}
	subjects.clear();
}

void Student::addSubject(Subject* subject) {
	subjects.insert(subject);
}