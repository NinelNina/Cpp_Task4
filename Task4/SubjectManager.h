#pragma once
#include "Subject.h"
#include "SubjectComparator.h"
#include <set>

using namespace std;

class SubjectManager
{
public:
    static SubjectManager* GetInstance();

    void AddSubject(Subject* subject);
    void AddSubject(CString subjectName);
    Subject* FindSubject(CString subjectName);

    void Clear();

    set<Subject*, SubjectComparator> GetSubjects();

private:
    SubjectManager();
    ~SubjectManager();
    set<Subject*, SubjectComparator> _subjects;
};

