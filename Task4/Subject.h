#pragma once
#include <string>

using namespace std;

class Subject
{
private:
	CString _name;
public:
	Subject(CString name);
	~Subject();
	CString GetName() const;
};

