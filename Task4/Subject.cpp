#include "pch.h"
#include "Subject.h"

Subject::Subject(CString name) {
	_name = name;
}

Subject::~Subject() { }

CString Subject::GetName() const
{
	return _name;
}