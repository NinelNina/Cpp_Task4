#pragma once
#include <string>

using namespace std;

class Subject
{
private:
	string _name;
public:
	Subject(string name);
	~Subject();
	string getName();
};

