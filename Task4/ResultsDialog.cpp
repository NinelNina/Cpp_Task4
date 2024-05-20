#include "pch.h"
#include "Task4.h"
#include "afxdialogex.h"
#include "ResultsDialog.h"


IMPLEMENT_DYNAMIC(ResultsDialog, CDialogEx)

ResultsDialog::ResultsDialog(CWnd* pParent, vector<Student*> students, vector<Subject*> learningSubjects, vector<Subject*> notLearningSubjects)
{
    _students = students;
    _learningSubjects = learningSubjects;
    _notLearningSubjects = notLearningSubjects;
}

ResultsDialog::~ResultsDialog()
{
}

void ResultsDialog::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_RESULTS_LIST, _resultsList);
    DDX_Control(pDX, IDC_LEARNING_LIST2, _learningList);
    DDX_Control(pDX, IDC_NOT_LEARNING_LIST2, _notLearningList);
}

BEGIN_MESSAGE_MAP(ResultsDialog, CDialogEx)
    ON_BN_CLICKED(IDOK, &ResultsDialog::OnBnClickedOk)
END_MESSAGE_MAP()

BOOL ResultsDialog::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    _resultsList.SetExtendedStyle(_resultsList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
    _learningList.SetExtendedStyle(_learningList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);
    _notLearningList.SetExtendedStyle(_notLearningList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

    _resultsList.InsertColumn(0, _T("Фамилия"), LVCFMT_LEFT, 100);
    _learningList.InsertColumn(0, _T("Предмет"), LVCFMT_LEFT, 84);
    _notLearningList.InsertColumn(0, _T("Предмет"), LVCFMT_LEFT, 84);

    LoadData();

    return TRUE;
}

void ResultsDialog::LoadData()
{
    _resultsList.DeleteAllItems();

    for (auto student : _students)
    {
        _resultsList.InsertItem(0, student->GetSurname());
    }

    for (auto subject : _learningSubjects) 
    {
        _learningList.InsertItem(0, subject->GetName());
    }
    
    for (auto subject : _notLearningSubjects) 
    {
        _notLearningList.InsertItem(0, subject->GetName());
    }

    Logger::Instance().Log("Результирующие данные загружены.");
}

void ResultsDialog::OnBnClickedOk()
{
    Logger::Instance().Log("Закрытие окна с результирующими данными.");

    CDialogEx::OnOK();    
}
