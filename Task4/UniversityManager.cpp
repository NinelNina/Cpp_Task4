#include "UniversityManager.h"

vector<Student*> UniversityManager::findStudents(vector<Subject*> learningSubjects, vector<Subject*> notlearningSubjects) {
    vector<Student*> filteredStudents;

    for (Student* student : students) {
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