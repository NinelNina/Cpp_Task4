#pragma once
#include <string>

using namespace std;

class Subject
{
private:
	string name;
public:
	Subject(string name);
	~Subject();
	string getName();
};

