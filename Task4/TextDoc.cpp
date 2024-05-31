
// TextDoc.cpp : implementation of the CTextDoc class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "Task4.h"
#endif

#include "TextDoc.h"

#include <propkey.h>

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CTextDoc

IMPLEMENT_DYNCREATE(CTextDoc, CDocument)

BEGIN_MESSAGE_MAP(CTextDoc, CDocument)
	ON_UPDATE_COMMAND_UI(ID_TOOLS_LOADTOTABLE, &CTextDoc::OnUpdateToolsLoadToTable)
END_MESSAGE_MAP()


// CTextDoc construction/destruction

bool CTextDoc::loggedTextfileFormat = false;

CTextDoc::CTextDoc() noexcept
{
	_text = _T("Untitled");

}

BOOL CTextDoc::IsTextValid()
{
	CStringArray lines;
	int pos = 0;
	while (pos < _text.GetLength())
	{
		int nextPos = _text.Find(_T("\n"), pos);
		if (nextPos == -1)
		{
			lines.Add(_text.Mid(pos));
			break;
		}
		lines.Add(_text.Mid(pos, nextPos - pos));
		pos = nextPos + 1;
	}

	for (int i = 0; i < lines.GetSize(); i++)
	{
		CString line = lines[i].Trim();
		if (line.IsEmpty())
			continue;

		int firstSpacePos = line.Find(_T(' '));
		if (firstSpacePos == -1)
			return false;

		CString lastName = line.Left(firstSpacePos);
		CString subject = line.Mid(firstSpacePos + 1).Trim();

		if (lastName.IsEmpty() || subject.IsEmpty())
			return false;
	}

	return true;
}


CTextDoc::~CTextDoc()
{
}

BOOL CTextDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	loggedTextfileFormat = false;

	return TRUE;
}

BOOL CTextDoc::OnOpenDocument(LPCTSTR lpszPathName)
{
	if (!CDocument::OnOpenDocument(lpszPathName))
		return FALSE;

	loggedTextfileFormat = false; // Reset the log state for an opened document

	return TRUE;
}


// CTextDoc serialization

void CTextDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		USES_CONVERSION;
		int charCnt = _text.GetLength();
		char* buf = new char[charCnt * 2 + 1];
		int convertedChars = WideCharToMultiByte(CP_UTF8, 0, _text.GetBuffer(), charCnt, buf, charCnt * 2, 0, 0);

		ar.Write(buf, convertedChars);
		delete[] buf;
	}
	else
	{
		_text = L"";

		const int bufSize = 1024 * 1024;
		char* buf = new char[bufSize + 1];

		while (int count = ar.Read(buf, bufSize))
		{
			CStringA tempA(buf, count);
			CStringW tempW(CA2W(tempA.GetBuffer(), CP_UTF8));
			_text.Append(tempW);
		}

		delete[] buf;
	}
}


const CString& CTextDoc::GetText() 
{
	return _text;
}

#ifdef SHARED_HANDLERS

// Support for thumbnails
void CTextDoc::OnDrawThumbnail(CDC& dc, LPRECT lprcBounds)
{
	// Modify this code to draw the document's data
	dc.FillSolidRect(lprcBounds, RGB(255, 255, 255));

	CString strText = _T("TODO: implement thumbnail drawing here");
	LOGFONT lf;

	CFont* pDefaultGUIFont = CFont::FromHandle((HFONT) GetStockObject(DEFAULT_GUI_FONT));
	pDefaultGUIFont->GetLogFont(&lf);
	lf.lfHeight = 36;

	CFont fontDraw;
	fontDraw.CreateFontIndirect(&lf);

	CFont* pOldFont = dc.SelectObject(&fontDraw);
	dc.DrawText(strText, lprcBounds, DT_CENTER | DT_WORDBREAK);
	dc.SelectObject(pOldFont);
}

// Support for Search Handlers
void CTextDoc::InitializeSearchContent()
{
	CString strSearchContent;
	// Set search contents from document's data.
	// The content parts should be separated by ";"

	// For example:  strSearchContent = _T("point;rectangle;circle;ole object;");
	SetSearchContent(strSearchContent);
}

void CTextDoc::SetSearchContent(const CString& value)
{
	if (value.IsEmpty())
	{
		RemoveChunk(PKEY_Search_Contents.fmtid, PKEY_Search_Contents.pid);
	}
	else
	{
		CMFCFilterChunkValueImpl *pChunk = nullptr;
		ATLTRY(pChunk = new CMFCFilterChunkValueImpl);
		if (pChunk != nullptr)
		{
			pChunk->SetTextValue(PKEY_Search_Contents, value, CHUNK_TEXT);
			SetChunkValue(pChunk);
		}
	}
}

#endif // SHARED_HANDLERS

// CTextDoc diagnostics

#ifdef _DEBUG
void CTextDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTextDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG


// CTextDoc commands


void CTextDoc::OnUpdateToolsLoadToTable(CCmdUI* pCmdUI)
{
	bool isTextValid = IsTextValid();
	pCmdUI->Enable(isTextValid);
	if (!isTextValid && !loggedTextfileFormat)
	{
		Logger::Instance().Log("Текст не соответствует формату \"Фамилия Предмет\".", Logger::ERR);
		loggedTextfileFormat = true;
	}
	else if (!loggedTextfileFormat) {
		Logger::Instance().Log("Текст соответствует формату \"Фамилия Предмет\".");
		loggedTextfileFormat = true;
	}
}

void CTextDoc::SetText(const CString& text)
{
	_text = text;
	UpdateAllViews(nullptr);
}
