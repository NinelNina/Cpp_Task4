#pragma once
#include "afxcmn.h"
#include "StudentManager.h"

class ResultsDialog : public CDialogEx
{
    DECLARE_DYNAMIC(ResultsDialog)

public:
    ResultsDialog(CWnd* pParent = nullptr, vector<Student*> students = {}, vector<Subject*> learningSubjects = {}, vector<Subject*> notLearningSubjects = {});
    virtual ~ResultsDialog();
    CString GetResultsText() const;

#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_RESULTS_DIALOG };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);
    virtual BOOL OnInitDialog();

    DECLARE_MESSAGE_MAP()

private:
    CListCtrl _resultsList;
    CListCtrl _learningList;
    CListCtrl _notLearningList;
    vector<Subject*> _learningSubjects;
    vector<Subject*> _notLearningSubjects;
    vector<Student*> _students;
    void LoadData();
public:
    afx_msg void OnBnClickedOk();
    
};
