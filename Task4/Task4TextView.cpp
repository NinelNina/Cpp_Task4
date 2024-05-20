
// Task4TextView.cpp : implementation of the CTask4TextView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Task4.h"
#endif

#include "TextDoc.h"
#include "Task4TextView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif

// CTask4TextView

IMPLEMENT_DYNCREATE(CTask4TextView, CView)

BEGIN_MESSAGE_MAP(CTask4TextView, CView)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
    ON_COMMAND(ID_TOOLS_LOADTOTABLE, &CTask4TextView::OnToolsLoadToTable)
END_MESSAGE_MAP()

// CTask4TextView construction/destruction

CTask4TextView::CTask4TextView() noexcept
{
}

CTask4TextView::~CTask4TextView()
{
}

BOOL CTask4TextView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CTask4TextView drawing

void CTask4TextView::OnDraw(CDC* pDC)
{
	const int textH = 40;
	const int textW = 15;

	CTextDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
	{
		Logger::Instance().Log("Ошибка получения документа в OnDraw().");
		return;
	}

	RECT r;
	CPen pen;
	pen.CreatePen(0, 20, COLOR_WINDOWTEXT);
	CFont font;
	font.CreateFontW(textH, textW, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, _T("Arial"));
	CFont* oldFont = pDC->SelectObject(&font);

	GetClientRect(&r);
	CPen* oldPen = pDC->SelectObject(&pen);
	CString text = pDoc->GetText();
	pDC->DrawTextEx(text, &r, 0, 0);
	pDC->SelectObject(oldPen);
	pDC->SelectObject(oldFont);
}

void CTask4TextView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CTask4TextView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}

// CTask4TextView diagnostics

#ifdef _DEBUG
void CTask4TextView::AssertValid() const
{
	CView::AssertValid();
}

void CTask4TextView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTextDoc* CTask4TextView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTextDoc)));
	return (CTextDoc*)m_pDocument;
}
#endif //_DEBUG


// CTask4TextView message handlers


void CTask4TextView::OnToolsLoadToTable()
{
	CTextDoc* pDoc = GetDocument();

	TableDialog* pDlg = new TableDialog(this, pDoc->_text);
	pDlg->Create(IDD_TABLE_DIALOG, this);
	pDlg->ShowWindow(SW_SHOW);

	Logger::Instance().Log("Данные загружены в таблицу.");
}
