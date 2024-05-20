// TableDialog.cpp : implementation file
//

#include "pch.h"
#include "Task4.h"
#include "afxdialogex.h"
#include "TableDialog.h"
#include "FindStudentsDialog.h"


// TableDialog dialog

IMPLEMENT_DYNAMIC(TableDialog, CDialogEx)

TableDialog::TableDialog(CWnd* pParent /*=nullptr*/, CString _text)
	: CDialogEx(IDD_TABLE_DIALOG, pParent)
{
    _tableText = _text;
    _studentManager = new StudentManager();
}

TableDialog::~TableDialog()
{
}

void TableDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
    DDX_Control(pDX, IDC_STUDENTS_LIST, _studentList);
}

BOOL TableDialog::OnInitDialog()
{
    CDialog::OnInitDialog();

    _studentList.SetExtendedStyle(_studentList.GetExtendedStyle() | LVS_EX_FULLROWSELECT | LVS_EX_GRIDLINES);

    _studentList.InsertColumn(0, _T("Фамилия"), LVCFMT_LEFT, 150);
    _studentList.InsertColumn(1, _T("Предмет"), LVCFMT_LEFT, 150);

    LoadData();

    return true;
}

void TableDialog::LoadData()
{
    _studentList.DeleteAllItems();

    SubjectManager& subjectManager = SubjectManager::GetInstance();

    CString strLine;
    int startPos = 0;
    CString delimiter = _T("\n");

    while ((strLine = _tableText.Tokenize(delimiter, startPos)) != _T(""))
    {
        int pos = strLine.Find(_T(' '));
        if (pos != -1)
        {
            CString surname = strLine.Left(pos);
            CString subjectName = strLine.Mid(pos + 1);

            Subject* subject = new Subject(subjectName);
            subjectManager.AddSubject(subject);
            _studentManager->AddStudent(surname, subject);

            int nIndex = _studentList.InsertItem(0, surname);
            _studentList.SetItemText(nIndex, 1, subjectName);
        }
    }
}

BEGIN_MESSAGE_MAP(TableDialog, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON1, &TableDialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// TableDialog message handlers


void TableDialog::OnBnClickedButton1()
{
    FindStudentsDialog* pDlg = new FindStudentsDialog(this, _studentManager);
    pDlg->Create(IDD_DIALOG2, this);
    pDlg->ShowWindow(SW_SHOW);
}
