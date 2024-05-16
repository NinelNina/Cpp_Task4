// TableDialog.cpp : implementation file
//

#include "pch.h"
#include "Task4.h"
#include "afxdialogex.h"
#include "TableDialog.h"


// TableDialog dialog

IMPLEMENT_DYNAMIC(TableDialog, CDialogEx)

TableDialog::TableDialog(CWnd* pParent /*=nullptr*/, CString _text)
	: CDialogEx(IDD_DIALOG1, pParent)
{
    _tableText = _text;
}

TableDialog::~TableDialog()
{
}

void TableDialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}


int TableDialog::OnInitDialog()
{
    CDialog::OnInitDialog();
    _studentManager = StudentManager();

    CButton* pButton = (CButton*)GetDlgItem(IDC_BUTTON1);
    if (pButton != nullptr)
    {
        pButton->SetWindowText(_T("Поиск"));
    }

    listCtrl.Create(WS_CHILD | WS_VISIBLE | LVS_REPORT, CRect(10, 10, 320, 355), this, 1001);

    listCtrl.InsertColumn(0, _T("Фамилия"), LVCFMT_LEFT, 160);
    listCtrl.InsertColumn(1, _T("Предмет"), LVCFMT_LEFT, 160);

    LoadData();

    return 0;
}

void TableDialog::LoadData()
{
    listCtrl.DeleteAllItems();

    SubjectManager& subjectManager = SubjectManager::GetInstance();

    CString strLine;
    int startPos = 0;
    CString delimiter = _T("\n");

    while ((strLine = _tableText.Tokenize(delimiter, startPos)) != _T(""))
    {
        int pos = strLine.Find(_T(' '));
        if (pos != -1)
        {
            CString lastName = strLine.Left(pos);
            CString subjectName = strLine.Mid(pos + 1);
            Subject subject = Subject(subjectName);
            subjectManager.AddSubject(subject);
            Student* student = new Student(lastName, &subject);
            _studentManager.AddStudent(student);

            int nIndex = listCtrl.InsertItem(0, lastName);
            listCtrl.SetItemText(nIndex, 1, subjectName);
        }
    }
}

void TableDialog::InputToTable()
{
    listCtrl.DeleteAllItems();

    //for (auto student : _studentManager.GetStudents()) {
    //    int nIndex = listCtrl.InsertItem(0, student.);
    //        listCtrl.SetItemText(nIndex, 1, subjectName);
    //}

    
}



BEGIN_MESSAGE_MAP(TableDialog, CDialogEx)
    ON_BN_CLICKED(IDC_BUTTON1, &TableDialog::OnBnClickedButton1)
END_MESSAGE_MAP()


// TableDialog message handlers


void TableDialog::OnBnClickedButton1()
{
    // TODO: Add your control notification handler code here
}
