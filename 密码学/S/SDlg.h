// SDlg.h : header file
//

#if !defined(AFX_SDLG_H__4C128DD0_0D1E_4EFD_B090_E3E714412217__INCLUDED_)
#define AFX_SDLG_H__4C128DD0_0D1E_4EFD_B090_E3E714412217__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CSDlg dialog

class CSDlg : public CDialog
{
// Construction
public:
	CSDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CSDlg)
	enum { IDD = IDD_S_DIALOG };
	CString	m_message;
	int		m_1;
	int		m_2;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CSDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CSDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_SDLG_H__4C128DD0_0D1E_4EFD_B090_E3E714412217__INCLUDED_)
