
// Task4TextView.h : interface of the CTask4TextView class
//

#pragma once
#include "TableDialog.h"
#include "TextDoc.h"

class CTask4TextView : public CView
{
protected: // create from serialization only
	CTask4TextView() noexcept;
	DECLARE_DYNCREATE(CTask4TextView)
// Attributes
public:
	CTextDoc* GetDocument() const;
// Operations
public:

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:

// Implementation
public:
	virtual ~CTask4TextView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnToolsLoadToTable();
};

#ifndef _DEBUG  // debug version in Task4TextView.cpp
inline CTextDoc* CTask4TextView::GetDocument() const
   { return reinterpret_cast<CTextDoc*>(m_pDocument); }
#endif

