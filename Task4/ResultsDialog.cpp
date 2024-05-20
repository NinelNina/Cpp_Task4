#include "pch.h"
#include "Task4.h"
#include "afxdialogex.h"
#include "ResultsDialog.h"

IMPLEMENT_DYNAMIC(ResultsDialog, CDialogEx)

ResultsDialog::ResultsDialog(CWnd* pParent /*=nullptr*/, const std::vector<Student*>& students)
    : CDialogEx(IDD_RESULTS_DIALOG, pParent), _students(students)
{
}

ResultsDialog::~ResultsDialog()
{
}

void ResultsDialog::DoDataExchange(CDataExchange* pDX)
{
    CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_RESULTS_LIST, _resultsList);
}

BEGIN_MESSAGE_MAP(ResultsDialog, CDialogEx)
END_MESSAGE_MAP()

BOOL ResultsDialog::OnInitDialog()
{
    CDialogEx::OnInitDialog();

    _resultsList.SetExtendedStyle(_resultsList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

    _resultsList.InsertColumn(0, _T("Фамилия"), LVCFMT_LEFT, 150);
    _resultsList.InsertColumn(1, _T("Предмет"), LVCFMT_LEFT, 150);

    LoadData();

    return TRUE;
}

void ResultsDialog::LoadData()
{
    _resultsList.DeleteAllItems();

    for (auto& student : _students)
    {
        int nIndex = _resultsList.InsertItem(0, student->GetSurname());
        //_resultsList.SetItemText(nIndex, 1, student->getSubjects()->getName());
    }
}
