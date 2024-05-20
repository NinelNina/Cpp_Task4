
#include "pch.h"
#include "StudentManager.h"

StudentManager::StudentManager()
{
}

StudentManager::~StudentManager()
{
    for (auto student : _students) {
        delete student;
    }
}

void StudentManager::AddStudent(Student* student)
{
    _students.push_back(student);
}

void StudentManager::AddStudent(CString surname, Subject* subject)
{
    Student* existingStudent = FindStudentBySurname(surname);
    if (existingStudent)
    {
        existingStudent->AddSubject(subject);
    }
    else
    {
        Student* student = new Student(surname, subject);
        AddStudent(student);
    }
}

const vector<Student*> StudentManager::GetStudents()
{
    return _students;
}

Student* StudentManager::FindStudentBySurname(const CString& surname)
{
    for (auto student : _students)
    {
        if (student->GetSurname() == surname)
        {
            return student;
        }
    }
    return nullptr;
}

vector<Student*> StudentManager::FindStudents(const vector<Subject*> learningSubjects, const vector<Subject*> notLearningSubjects)
{
    vector<Student*> result;

    for (auto student : _students)
    {
        bool learnsAllSubjects = true;
        bool doesNotLearnAnySubject = true;

        const set<Subject*, SubjectComparator>& studentSubjects = student->GetSubjects();

        for (const auto subject : learningSubjects)
        {
            if (studentSubjects.find(subject) == studentSubjects.end())
            {
                learnsAllSubjects = false;
                break;
            }
        }

        for (const auto subject : notLearningSubjects)
        {
            if (studentSubjects.find(subject) != studentSubjects.end())
            {
                doesNotLearnAnySubject = false;
                break;
            }
        }

        if (learnsAllSubjects && doesNotLearnAnySubject)
        {
            result.push_back(student);
        }
    }

    return result;
}

//vector<Student*> StudentManager::findStudents(vector<Subject*> learningSubjects, vector<Subject*> notlearningSubjects) {
//    vector<Student*> filteredStudents;
//
//    for (Student* student : _students) {
//        set<Subject*, SubjectComparator> studentSubjects = student->getSubjects();
//        bool learnsAllRequired = true;
//        bool learnsForbidden = false;
//
//        for (Subject* requiredSubject : learningSubjects) {
//            if (studentSubjects.find(requiredSubject) == studentSubjects.end()) {
//                learnsAllRequired = false;
//                break;
//            }
//        }
//
//        for (Subject* forbiddenSubject : notlearningSubjects) {
//            if (studentSubjects.find(forbiddenSubject) != studentSubjects.end()) {
//                learnsForbidden = true;
//                break;
//            }
//        }
//
//        if (learnsAllRequired && !learnsForbidden) {
//            filteredStudents.push_back(student);
//        }
//    }
//
//    return filteredStudents;
//}