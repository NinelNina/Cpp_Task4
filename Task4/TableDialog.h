#pragma once
#include "afxdialogex.h"
#include "pch.h"


// TableDialog dialog

class TableDialog : public CDialogEx
{
	DECLARE_DYNAMIC(TableDialog)

public:
	TableDialog(CWnd* pParent, CString _text);   // standard constructor
	virtual ~TableDialog();
	CListCtrl listCtrl;

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	CString _tableText;
	StudentManager _studentManager;
	
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	int OnInitDialog();

	void LoadData();
	void InputToTable();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
