// haoxue.h : main header file for the HAOXUE application
//

#if !defined(AFX_HAOXUE_H__D391CA1D_B7B2_436C_AC8B_BD2CFE11F466__INCLUDED_)
#define AFX_HAOXUE_H__D391CA1D_B7B2_436C_AC8B_BD2CFE11F466__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CHaoxueApp:
// See haoxue.cpp for the implementation of this class
//

class CHaoxueApp : public CWinApp
{
public:
	CHaoxueApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHaoxueApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CHaoxueApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HAOXUE_H__D391CA1D_B7B2_436C_AC8B_BD2CFE11F466__INCLUDED_)
