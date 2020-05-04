// tuxing.h : main header file for the TUXING application
//

#if !defined(AFX_TUXING_H__52793EEB_7365_4973_831E_FA993F9B75BE__INCLUDED_)
#define AFX_TUXING_H__52793EEB_7365_4973_831E_FA993F9B75BE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"       // main symbols

/////////////////////////////////////////////////////////////////////////////
// CTuxingApp:
// See tuxing.cpp for the implementation of this class
//

class CTuxingApp : public CWinApp
{
public:
	CTuxingApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CTuxingApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation
	//{{AFX_MSG(CTuxingApp)
	afx_msg void OnAppAbout();
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_TUXING_H__52793EEB_7365_4973_831E_FA993F9B75BE__INCLUDED_)
