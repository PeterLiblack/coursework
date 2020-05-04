// tuxingView.h : interface of the CTuxingView class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TUXINGVIEW_H__05B97510_463D_44DF_948A_EFB431AEBE5D__INCLUDED_)
#define AFX_TUXINGVIEW_H__05B97510_463D_44DF_948A_EFB431AEBE5D__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTuxingView : public CView
{
protected: // create from serialization only
	CTuxingView();
	DECLARE_DYNCREATE(CTuxingView)

// Attributes
public:
	CTuxingDoc* GetDocument();

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTuxingView)
	public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTuxingView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTuxingView)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

#ifndef _DEBUG  // debug version in tuxingView.cpp
inline CTuxingDoc* CTuxingView::GetDocument()
   { return (CTuxingDoc*)m_pDocument; }
#endif

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TUXINGVIEW_H__05B97510_463D_44DF_948A_EFB431AEBE5D__INCLUDED_)
