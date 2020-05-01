// haoxueDlg.h : header file
//

#if !defined(AFX_HAOXUEDLG_H__10106B76_E637_4BE8_948F_C5CB2DC91AAE__INCLUDED_)
#define AFX_HAOXUEDLG_H__10106B76_E637_4BE8_948F_C5CB2DC91AAE__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CHaoxueDlg dialog

class CHaoxueDlg : public CDialog
{
// Construction
public:
	CHaoxueDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CHaoxueDlg)
	enum { IDD = IDD_HAOXUE_DIALOG };
	CString	m_1;
	int		m_2;
	CString	m_3;
	int		m_4;
	int		m_n;
	int		m_e;
	int		m_f;
	int		m_d;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CHaoxueDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CHaoxueDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton1();
	afx_msg void OnButton2();
	afx_msg void OnButton3();
	afx_msg void OnButton4();
	afx_msg void OnButton5();
	afx_msg void OnButton6();
	afx_msg void OnButton7();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_HAOXUEDLG_H__10106B76_E637_4BE8_948F_C5CB2DC91AAE__INCLUDED_)
