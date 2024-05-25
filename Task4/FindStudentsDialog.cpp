// FindStudentsDialog.cpp : implementation file
//

#include "pch.h"
#include "Task4.h"
#include "afxdialogex.h"
#include "FindStudentsDialog.h"
#include "ResultsDialog.h"


// FindStudentsDialog dialog

IMPLEMENT_DYNAMIC(FindStudentsDialog, CDialogEx)

FindStudentsDialog::FindStudentsDialog(CWnd* pParent /*=nullptr*/, StudentManager* studentManager)
	: CDialogEx(IDD_FIND_STUDENTS_DIALOG, pParent)
{
	_studentManager = studentManager;
    _subjectManager = SubjectManager::GetInstance();
}

FindStudentsDialog::~FindStudentsDialog()
{
}

void FindStudentsDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_LEARNING_LIST, _learningList);
    DDX_Control(pDX, IDC_NOT_LEARNING_LIST, _notLearningList);
}

BOOL FindStudentsDialog::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    _learningList.SetExtendedStyle(_learningList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES);
    _notLearningList.SetExtendedStyle(_learningList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES | LVS_EX_CHECKBOXES);

    _learningList.InsertColumn(0, _T(""), LVCFMT_CENTER, 50);
    _learningList.InsertColumn(1, _T("Предмет"), LVCFMT_LEFT, 132);
    
    _notLearningList.InsertColumn(0, _T(""), LVCFMT_CENTER, 50);
    _notLearningList.InsertColumn(1, _T("Предмет"), LVCFMT_LEFT, 132);
    FillSubjectList();

    return true;
}

void FindStudentsDialog::FillSubjectList()
{
    _learningList.DeleteAllItems();
    _notLearningList.DeleteAllItems();

    for (auto& subject : _subjectManager->GetSubjects())
    {
        int item = _learningList.InsertItem(0, _T(""));
        _learningList.SetItemText(item, 1, subject->GetName());
        _learningList.SetCheck(item, FALSE);

        item = _notLearningList.InsertItem(0, _T(""));
        _notLearningList.SetItemText(item, 1, subject->GetName());
        _notLearningList.SetCheck(item, FALSE);
    }

    Logger::Instance().Log("Данные о предметах загружены в таблицы.");
}

BEGIN_MESSAGE_MAP(FindStudentsDialog, CDialogEx)
    ON_BN_CLICKED(IDOK, &FindStudentsDialog::OnBnClickedOk)
    ON_BN_CLICKED(IDCANCEL, &FindStudentsDialog::OnBnClickedCancel)
END_MESSAGE_MAP()


// FindStudentsDialog message handlers


void FindStudentsDialog::OnBnClickedOk()
{
    vector<Subject*> learningSubjects;
    vector<Subject*> notLearningSubjects;
    
    int itemCount = _learningList.GetItemCount();
    for (int i = 0; i < itemCount; i++)
    {
        if (_learningList.GetCheck(i))
        {
            CString subjectName = _learningList.GetItemText(i, 1);
            learningSubjects.push_back(_subjectManager->FindSubject(subjectName));
        }
    }

    itemCount = _notLearningList.GetItemCount();
    for (int i = 0; i < itemCount; i++)
    {
        if (_notLearningList.GetCheck(i))
        {
            CString subjectName = _notLearningList.GetItemText(i, 1);
            notLearningSubjects.push_back(_subjectManager->FindSubject(subjectName));
        }
    }

    vector<Student*> students = _studentManager->FindStudents(learningSubjects, notLearningSubjects);

    ResultsDialog* pResultsDialog = new ResultsDialog(this, students, learningSubjects, notLearningSubjects);
    pResultsDialog->Create(IDD_RESULTS_DIALOG, this);
    pResultsDialog->ShowWindow(SW_SHOW);

    Logger::Instance().Log("Вывод списка найденных студентов.");

    CDialogEx::OnOK();
}


void FindStudentsDialog::OnBnClickedCancel()
{
    Logger::Instance().Log("Поиск отменён.", Logger::WARNING);
    CDialogEx::OnCancel();
}
