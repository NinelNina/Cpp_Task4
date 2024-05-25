#include "pch.h"
#include "SubjectManager.h"

SubjectManager* SubjectManager::GetInstance()
{
    static SubjectManager instance;
    return &instance;
}

void SubjectManager::AddSubject(Subject* subject)
{
    _subjects.insert(subject);
}

void SubjectManager::AddSubject(CString subjectName)
{
    Subject* subject = new Subject(subjectName);
    _subjects.insert(subject);
}

Subject* SubjectManager::FindSubject(CString subjectName)
{
    for (auto& subject : _subjects)
    {
        if (subject->GetName() == subjectName)
        {
            return subject;
        }
    }

    return nullptr;
}

void SubjectManager::Clear() {
    for (auto subject : _subjects) {
        delete subject;
    }
    _subjects.clear();
}

set<Subject*, SubjectComparator> SubjectManager::GetSubjects()
{
    return _subjects;
}

SubjectManager::SubjectManager() {}

SubjectManager::~SubjectManager()
{
    for (auto subject : _subjects) {
        delete subject;
    }
}
