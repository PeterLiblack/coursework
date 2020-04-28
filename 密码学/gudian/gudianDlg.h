// gudianDlg.h : header file
//

#if !defined(AFX_GUDIANDLG_H__63993D33_BFFD_454D_91F3_F587CB7A37F3__INCLUDED_)
#define AFX_GUDIANDLG_H__63993D33_BFFD_454D_91F3_F587CB7A37F3__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

/////////////////////////////////////////////////////////////////////////////
// CGudianDlg dialog

class CGudianDlg : public CDialog
{
// Construction
public:
	CGudianDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	//{{AFX_DATA(CGudianDlg)
	enum { IDD = IDD_GUDIAN_DIALOG };
	int		m_a;
	int		m_b;
	CString	m_cipher;
	CString	m_message1;
	CString	m_message;
	CString	m_1;
	int		m_2;
	CString	m_3;
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CGudianDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	//{{AFX_MSG(CGudianDlg)
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	afx_msg void OnButton2();
	afx_msg void OnButton1();
	afx_msg void OnButton3();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_GUDIANDLG_H__63993D33_BFFD_454D_91F3_F587CB7A37F3__INCLUDED_)
