#pragma once
#include "afxdialogex.h"
#include "pch.h"


// TableDialog dialog

class TableDialog : public CDialogEx
{
	DECLARE_DYNAMIC(TableDialog)

public:
	TableDialog(CWnd* pParent, CString _text);
	virtual ~TableDialog();
	CListCtrl _studentList;

#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_TABLE_DIALOG };
#endif

protected:
	CString _tableText;
	StudentManager* _studentManager;
	
	virtual void DoDataExchange(CDataExchange* pDX);

	BOOL OnInitDialog();

	void LoadData();

	DECLARE_MESSAGE_MAP()
public:
	afx_msg
		void OnClose();
	void OnBnClickedButton1();
};
