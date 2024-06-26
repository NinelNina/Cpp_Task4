
// TextDoc.h : interface of the CTextDoc class
//


#pragma once

class CTextDoc : public CDocument
{
protected: // create from serialization only
	CTextDoc() noexcept;
	DECLARE_DYNCREATE(CTextDoc)

	BOOL IsTextValid();
	static bool loggedTextfileFormat;

	CString _text;

// Attributes
public:

// Operations
public:
	void SetText(const CString& text);
	const CString& GetText();

// Overrides
public:
	virtual BOOL OnNewDocument();
	BOOL OnOpenDocument(LPCTSTR lpszPathName);
	virtual void Serialize(CArchive& ar);
#ifdef SHARED_HANDLERS
	virtual void InitializeSearchContent();
	virtual void OnDrawThumbnail(CDC& dc, LPRECT lprcBounds);
#endif // SHARED_HANDLERS

// Implementation
public:
	virtual ~CTextDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	DECLARE_MESSAGE_MAP()

#ifdef SHARED_HANDLERS
	// Helper function that sets search content for a Search Handler
	void SetSearchContent(const CString& value);
#endif // SHARED_HANDLERS
public:
	afx_msg void OnUpdateToolsLoadToTable(CCmdUI* pCmdUI);
};
