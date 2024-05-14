#pragma once
#include "afxdialogex.h"


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
	
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

	int OnInitDialog();

	void LoadData();

	DECLARE_MESSAGE_MAP()
};
