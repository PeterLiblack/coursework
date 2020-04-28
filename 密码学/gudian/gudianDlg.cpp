// gudianDlg.cpp : implementation file
//

#include "stdafx.h"
#include "gudian.h"
#include "gudianDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	//{{AFX_DATA(CAboutDlg)
	enum { IDD = IDD_ABOUTBOX };
	//}}AFX_DATA

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAboutDlg)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:
	//{{AFX_MSG(CAboutDlg)
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
	//{{AFX_DATA_INIT(CAboutDlg)
	//}}AFX_DATA_INIT
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAboutDlg)
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
	//{{AFX_MSG_MAP(CAboutDlg)
		// No message handlers
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGudianDlg dialog

CGudianDlg::CGudianDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CGudianDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CGudianDlg)
	m_a = 0;
	m_b = 0;
	m_cipher = _T("");
	m_message1 = _T("");
	m_message = _T("");
	m_1 = _T("");
	m_2 = 0;
	m_3 = _T("");
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CGudianDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CGudianDlg)
	DDX_Text(pDX, IDC_EDIT2, m_a);
	DDX_Text(pDX, IDC_EDIT3, m_b);
	DDX_Text(pDX, IDC_EDIT4, m_cipher);
	DDX_Text(pDX, IDC_EDIT5, m_message1);
	DDX_Text(pDX, IDC_EDIT1, m_message);
	DDX_Text(pDX, IDC_EDIT6, m_1);
	DDX_Text(pDX, IDC_EDIT7, m_2);
	DDX_Text(pDX, IDC_EDIT8, m_3);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CGudianDlg, CDialog)
	//{{AFX_MSG_MAP(CGudianDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CGudianDlg message handlers

BOOL CGudianDlg::OnInitDialog()
{
	CDialog::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != NULL)
	{
		CString strAboutMenu;
		strAboutMenu.LoadString(IDS_ABOUTBOX);
		if (!strAboutMenu.IsEmpty())
		{
			pSysMenu->AppendMenu(MF_SEPARATOR);
			pSysMenu->AppendMenu(MF_STRING, IDM_ABOUTBOX, strAboutMenu);
		}
	}

	// Set the icon for this dialog.  The framework does this automatically
	//  when the application's main window is not a dialog
	SetIcon(m_hIcon, TRUE);			// Set big icon
	SetIcon(m_hIcon, FALSE);		// Set small icon
	
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CGudianDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialog::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CGudianDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, (WPARAM) dc.GetSafeHdc(), 0);

		// Center icon in client rectangle
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// Draw the icon
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialog::OnPaint();
	}
}

// The system calls this to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CGudianDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}

void CGudianDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	

	UpdateData(true);
	CString tempmessage=m_message;
	int i;
	int tempkey1=m_a;
	int tempkey2=m_b;
	char a[100]={0};
	memcpy(a,m_message,m_message.GetLength()); 
	for(i=0;i<m_message.GetLength();i++)
		a[i]=m_message.GetAt(i);                  
	for(i=0;i<m_message.GetLength();i++)
	a[i]=(m_a*(a[i]-'a')+m_b)%26+'a';
	m_cipher=a;
    UpdateData(false);
}


void CGudianDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	char b[100]={0};
	memcpy(b,m_cipher,m_cipher.GetLength());
	int tempkey1=m_a;
	int tempkey2=m_b;
	int j;
	int n;
		for(n=1;n<=25;n++)
	{
		if(((n*m_a)%26!=1))
			continue;
	
	for(j=0;j<m_cipher.GetLength();j++)
		b[j]=m_cipher.GetAt(j);
	for(j=0;j<m_cipher.GetLength();j++)
		b[j]=(n*(b[j]-m_b-'a'+26))%26+'a';
	}

	m_message1=b;
	UpdateData(false);
}


void CGudianDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
   char a[100];
   int b =m_2;
   strcpy(a,m_1);
   char c[100]={0};
   for (int i=0;i<m_1.GetLength();i++)
   {
	   if('a'<=a[i]&&a[i]<='z')

	   {
		   c[i]=(a[i]-'a'+b)%26+'a';
	   }
   }
   m_3=c;
   UpdateData(false);
}
