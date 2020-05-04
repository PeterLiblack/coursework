// tuxingDoc.cpp : implementation of the CTuxingDoc class
//

#include "stdafx.h"
#include "tuxing.h"

#include "tuxingDoc.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTuxingDoc

IMPLEMENT_DYNCREATE(CTuxingDoc, CDocument)

BEGIN_MESSAGE_MAP(CTuxingDoc, CDocument)
	//{{AFX_MSG_MAP(CTuxingDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTuxingDoc construction/destruction

CTuxingDoc::CTuxingDoc()
{
	// TODO: add one-time construction code here

}

CTuxingDoc::~CTuxingDoc()
{
}

BOOL CTuxingDoc::OnNewDocument()
{
	if (!CDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}



/////////////////////////////////////////////////////////////////////////////
// CTuxingDoc serialization

void CTuxingDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CTuxingDoc diagnostics

#ifdef _DEBUG
void CTuxingDoc::AssertValid() const
{
	CDocument::AssertValid();
}

void CTuxingDoc::Dump(CDumpContext& dc) const
{
	CDocument::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTuxingDoc commands
