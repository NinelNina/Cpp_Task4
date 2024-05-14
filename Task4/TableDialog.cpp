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

    listCtrl.Create(WS_CHILD | WS_VISIBLE | LVS_REPORT, CRect(10, 10, 320, 355), this, 1001);

    listCtrl.InsertColumn(0, _T("Фамилия"), LVCFMT_LEFT, 160);
    listCtrl.InsertColumn(1, _T("Предмет"), LVCFMT_LEFT, 160);

    LoadData();

    return 0;
}

void TableDialog::LoadData()
{
    listCtrl.DeleteAllItems();

    CString strLine;
    int startPos = 0;
    CString delimiter = _T("\n");
    while ((strLine = _tableText.Tokenize(delimiter, startPos)) != _T(""))
    {
        //TODO: преобразовывать в объект
        int pos = strLine.Find(_T(' '));
        if (pos != -1)
        {
            CString lastName = strLine.Left(pos);
            CString subject = strLine.Mid(pos + 1);

            int nIndex = listCtrl.InsertItem(0, lastName);
            listCtrl.SetItemText(nIndex, 1, subject);
        }
    }
}


BEGIN_MESSAGE_MAP(TableDialog, CDialogEx)
END_MESSAGE_MAP()


// TableDialog message handlers
