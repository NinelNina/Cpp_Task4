#include "pch.h"
#include "Subject.h"

Subject::Subject(string name) {
	this->name = name;
}

Subject::~Subject() { }

string Subject::getName()
{
	return name;
}

