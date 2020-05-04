// tuxingDoc.h : interface of the CTuxingDoc class
//
/////////////////////////////////////////////////////////////////////////////

#if !defined(AFX_TUXINGDOC_H__AC0CFD19_7CE9_4C1A_9016_B9B19980B7EE__INCLUDED_)
#define AFX_TUXINGDOC_H__AC0CFD19_7CE9_4C1A_9016_B9B19980B7EE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


class CTuxingDoc : public CDocument
{
protected: // create from serialization only
	CTuxingDoc();
	DECLARE_DYNCREATE(CTuxingDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTuxingDoc)
	public:
	virtual BOOL OnNewDocument();
	virtual void Serialize(CArchive& ar);
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CTuxingDoc();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CTuxingDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TUXINGDOC_H__AC0CFD19_7CE9_4C1A_9016_B9B19980B7EE__INCLUDED_)
