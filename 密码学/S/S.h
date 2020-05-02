// S.h : main header file for the S application
//

#if !defined(AFX_S_H__36C46F0E_F3B9_49E1_A3C5_9C55AC5A5494__INCLUDED_)
#define AFX_S_H__36C46F0E_F3B9_49E1_A3C5_9C55AC5A5494__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols

/////////////////////////////////////////////////////////////////////////////
// CSApp:
// See S.cpp for the implementation of this class
//

class CSApp : public CWinApp
{
public:
	CSApp();

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation

	//{{AFX_MSG(CSApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_S_H__36C46F0E_F3B9_49E1_A3C5_9C55AC5A5494__INCLUDED_)
