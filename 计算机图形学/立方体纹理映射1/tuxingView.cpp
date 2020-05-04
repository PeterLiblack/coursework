// tuxingView.cpp : implementation of the CTuxingView class
//

#include "stdafx.h"
#include "tuxing.h"

#include "tuxingDoc.h"
#include "tuxingView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CTuxingView

IMPLEMENT_DYNCREATE(CTuxingView, CView)

BEGIN_MESSAGE_MAP(CTuxingView, CView)
	//{{AFX_MSG_MAP(CTuxingView)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG_MAP
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, CView::OnFilePrintPreview)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CTuxingView construction/destruction

CTuxingView::CTuxingView()
{
	// TODO: add construction code here

}

CTuxingView::~CTuxingView()
{
}

BOOL CTuxingView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

/////////////////////////////////////////////////////////////////////////////
// CTuxingView drawing

void CTuxingView::OnDraw(CDC* pDC)
{
	CTuxingDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	// TODO: add draw code for native data here
}

/////////////////////////////////////////////////////////////////////////////
// CTuxingView printing

BOOL CTuxingView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CTuxingView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CTuxingView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

/////////////////////////////////////////////////////////////////////////////
// CTuxingView diagnostics

#ifdef _DEBUG
void CTuxingView::AssertValid() const
{
	CView::AssertValid();
}

void CTuxingView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CTuxingDoc* CTuxingView::GetDocument() // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CTuxingDoc)));
	return (CTuxingDoc*)m_pDocument;
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CTuxingView message handlers
