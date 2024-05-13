#include "pch.h"
#include "Subject.h"

Subject::Subject(string name) {
	_name = name;
}

Subject::~Subject() { }

string Subject::getName()
{
	return _name;
}

