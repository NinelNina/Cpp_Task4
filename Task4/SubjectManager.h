#pragma once
#include "Subject.h"
#include <vector>

using namespace std;

class SubjectManager
{
public:
    static SubjectManager& GetInstance();

    void AddSubject(const Subject& subject);

    vector<Subject>& GetSubjects();

private:
    SubjectManager();
    ~SubjectManager();
    vector<Subject> _subjects;
};

