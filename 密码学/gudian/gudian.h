// gudian.h : main header file for the GUDIAN application
//

#if !defined(AFX_GUDIAN_H__5E00661A_11DE_4B9F_8772_04B40857F6A7__INCLUDED_)
#define AFX_GUDIAN_H__5E00661A_11DE_4B9F_8772_04B40857F6A7__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CGudianApp:
// See gudian.cpp for the implementation of this class
//

class CGudianApp : public CWinApp
{
public:
	CGudianApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGudianApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CGudianApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GUDIAN_H__5E00661A_11DE_4B9F_8772_04B40857F6A7__INCLUDED_)
