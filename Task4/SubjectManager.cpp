#include "pch.h"
#include "SubjectManager.h"

SubjectManager& SubjectManager::GetInstance()
{
    static SubjectManager instance;
    return instance;
}

void SubjectManager::AddSubject(const Subject& subject)
{
    _subjects.push_back(subject);
}

vector<Subject>& SubjectManager::GetSubjects()
{
    return _subjects;
}

SubjectManager::SubjectManager() {}

SubjectManager::~SubjectManager()
{
    for (auto subject : _subjects) {
        delete &subject;
    }
    _subjects.clear();
}
