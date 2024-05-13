
#include "pch.h"
#include "UniversityManager.h"

vector<Student*> UniversityManager::findStudents(vector<Subject*> learningSubjects, vector<Subject*> notlearningSubjects) {
    vector<Student*> filteredStudents;

    for (Student* student : _students) {
        set<Subject*> studentSubjects = student->getSubjects();
        bool learnsAllRequired = true;
        bool learnsForbidden = false;

        for (Subject* requiredSubject : learningSubjects) {
            if (studentSubjects.find(requiredSubject) == studentSubjects.end()) {
                learnsAllRequired = false;
                break;
            }
        }

        for (Subject* forbiddenSubject : notlearningSubjects) {
            if (studentSubjects.find(forbiddenSubject) != studentSubjects.end()) {
                learnsForbidden = true;
                break;
            }
        }

        if (learnsAllRequired && !learnsForbidden) {
            filteredStudents.push_back(student);
        }
    }

    return filteredStudents;
}

void UniversityManager::inputFile(string filename) {
    ifstream inputFile(filename);
    if (!inputFile.is_open()) {
        cerr << "Ошибка открытия файла." << endl;
        return;
    }

    string line;
    while (getline(inputFile, line)) {
        size_t pos = line.find("\t");
        if (pos == string::npos) {
            cerr << "Неверный формат: " << line << endl;
            continue;
        }

        string surname = line.substr(0, pos);
        string subjectName = line.substr(pos + 1);

        bool subjectExists = false;
        Subject* subject = nullptr;
        for (Subject* s : _subjects) {
            if (s->getName() == subjectName) {
                subjectExists = true;
                subject = s;
                break;
            }
        }

        if (!subjectExists) {
            subject = new Subject(subjectName);
            _subjects.push_back(subject);
        }

        bool studentExists = false;
        Student* student = nullptr;
        for (Student* s : _students) {
            if (s->getSurname() == surname) {
                studentExists = true;
                student = s;
                break;
            }
        }

        if (studentExists) {
            student->addSubject(subject);
        }
        else {
            
            student = new Student(surname, subject);
            _students.push_back(student);
        }
    }

    inputFile.close();
}