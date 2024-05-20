#pragma once
#include "afxcmn.h"
#include "StudentManager.h"

class ResultsDialog : public CDialogEx
{
    DECLARE_DYNAMIC(ResultsDialog)

public:
    ResultsDialog(CWnd* pParent = nullptr, const std::vector<Student*>& students = {});
    virtual ~ResultsDialog();

#ifdef AFX_DESIGN_TIME
    enum { IDD = IDD_RESULTS_DIALOG };
#endif

protected:
    virtual void DoDataExchange(CDataExchange* pDX);
    virtual BOOL OnInitDialog();

    DECLARE_MESSAGE_MAP()

private:
    CListCtrl _resultsList;
    std::vector<Student*> _students;
    void LoadData();
};
