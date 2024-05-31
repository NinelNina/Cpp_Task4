#pragma once
#include "afxdialogex.h"


// FindStudentsDialog dialog

class FindStudentsDialog : public CDialogEx
{
	DECLARE_DYNAMIC(FindStudentsDialog)

public:
	//FindStudentsDialog(CWnd* pParent = nullptr);
	FindStudentsDialog(CWnd* pParent, StudentManager* studentManager);
	// standard constructor
	virtual ~FindStudentsDialog();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_FIND_STUDENTS_DIALOG};
#endif

protected:
	SubjectManager* _subjectManager;
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	BOOL OnInitDialog();
	void FillSubjectList();
	StudentManager* _studentManager;
	CListCtrl _learningList;
	CListCtrl _notLearningList;
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedOk();
	afx_msg void OnBnClickedCancel();
	void OnItemChangedLearningList(NMHDR* pNMHDR, LRESULT* pResult);
	void OnItemChangedNotLearningList(NMHDR* pNMHDR, LRESULT* pResult);
};
