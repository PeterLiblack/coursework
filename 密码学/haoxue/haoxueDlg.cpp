// haoxueDlg.cpp : implementation file
//

#include "stdafx.h"
#include "haoxue.h"
#include "haoxueDlg.h"
#include "stdio.h"
#include "math.h"

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
// CHaoxueDlg dialog

CHaoxueDlg::CHaoxueDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CHaoxueDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CHaoxueDlg)
	m_1 = _T("");
	m_2 = 0;
	m_3 = _T("");
	m_4 = 0;
	m_n = 0;
	m_e = 0;
	m_f = 0;
	m_d = 0;
	//}}AFX_DATA_INIT
	// Note that LoadIcon does not require a subsequent DestroyIcon in Win32
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CHaoxueDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CHaoxueDlg)
	DDX_Text(pDX, IDC_EDIT1, m_1);
	DDX_Text(pDX, IDC_EDIT2, m_2);
	DDX_Text(pDX, IDC_EDIT3, m_3);
	DDX_Text(pDX, IDC_EDIT4, m_4);
	DDX_Text(pDX, IDC_EDIT5, m_n);
	DDX_Text(pDX, IDC_EDIT6, m_e);
	DDX_Text(pDX, IDC_EDIT7, m_f);
	DDX_Text(pDX, IDC_EDIT8, m_d);
	//}}AFX_DATA_MAP
}

BEGIN_MESSAGE_MAP(CHaoxueDlg, CDialog)
	//{{AFX_MSG_MAP(CHaoxueDlg)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, OnButton1)
	ON_BN_CLICKED(IDC_BUTTON2, OnButton2)
	ON_BN_CLICKED(IDC_BUTTON3, OnButton3)
	ON_BN_CLICKED(IDC_BUTTON4, OnButton4)
	ON_BN_CLICKED(IDC_BUTTON5, OnButton5)
	ON_BN_CLICKED(IDC_BUTTON6, OnButton6)
	ON_BN_CLICKED(IDC_BUTTON7, OnButton7)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CHaoxueDlg message handlers

BOOL CHaoxueDlg::OnInitDialog()
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

void CHaoxueDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CHaoxueDlg::OnPaint() 
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
HCURSOR CHaoxueDlg::OnQueryDragIcon()
{
	return (HCURSOR) m_hIcon;
}
	 CString strFilePath;
void CHaoxueDlg::OnButton1() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
    //设置过滤器 
	 TCHAR szFilter[]=_T("文本文件(*.txt)|*.txt|所有文件(*.*)|*.*||");
    //构造打开文件对话框
	 CFileDialog fileDlg(TRUE,_T("txt"),NULL,0,szFilter,this);
    //显示打开文件对话框
	if(IDOK==fileDlg.DoModal())
	 {//将选择的文件路径显示到编辑框内
		 strFilePath=fileDlg.GetPathName();
		 SetDlgItemText(IDC_EDIT1,strFilePath);
	 }

}

//移位加密
void CHaoxueDlg::OnButton2() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	//读取文件
	CFile file(strFilePath, CFile::modeRead);
	char pBuf[100]={0};
	file.Read(pBuf,100);
	file.Close();
	//加密算法
     char a[100];
     int b =m_2;
     strcpy(a,pBuf);
     char c[100]={0};
     for (int i=0;i<strFilePath.GetLength();i++)
   {
	   if('a'<=a[i]&&a[i]<='z')
	   {
		   c[i]=(a[i]-'a'+b)%26+'a';
	   }
        if ('A' <= a[i]&&a[i]<'Z')
        {
            c[i]=(a[i]-'A'+b)%26+'A';
        }
    }

	 m_3=c;
   //存储文件
    file.Open("加密文件1.txt",CFile::modeCreate);
	file.Close();
    file.Open("加密文件1.txt",CFile::modeWrite);
	file.Write(c,100);
    file.Close();
	MessageBox("加密完成","",MB_OK);
    UpdateData(false);
}

//仿射解密
void CHaoxueDlg::OnButton3() 
{
	// TODO: Add your control notification handler code here

	UpdateData(true);
	//读取文件
	CFile file(strFilePath, CFile::modeRead);
	char pBuf[100]={0};
	file.Read(pBuf,100);
	file.Close();
    
    char a[100];
    strcpy(a,pBuf);
    char t[100]={0};
    //求逆
    int A;
	for(A=1;A<=25;A++)
	{
	    if((A*m_2)%26!=1)
	 	  continue;
    	else
		  A;
    
    for (int i=0;i<strFilePath.GetLength();i++)
   {
		if('a'<=a[i]&&a[i]<='z')
		{
			t[i]=(A*((a[i]-'a')-m_4+26))%26+'a';
		}
		if ('A' <= a[i]&&a[i]<'Z')
		{
			t[i]=(A*((a[i]-'A')-m_4+26))%26+'A';
		}
   }

	}

   m_3=t;

    file.Open("解密文件1.txt",CFile::modeCreate);
	file.Close();
    file.Open("解密文件1.txt",CFile::modeWrite);
	file.Write(t,100);
    file.Close();
	MessageBox("解密完成","",MB_OK);

	UpdateData(false);	
}

//仿射加密
void CHaoxueDlg::OnButton4() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CFile file(strFilePath, CFile::modeRead);
	char pBuf[100]={0};
	file.Read(pBuf,100);
	file.Close();


	  char a[100];

   strcpy(a,pBuf);
   char c[100]={0};
   for (int i=0;i<strFilePath.GetLength();i++)
   {
	   if('a'<=a[i]&&a[i]<='z')
	   {
		   c[i]=(m_2*(a[i]-'a')+m_4)%26+'a';
	   }
        if ('A' <= a[i]&&a[i]<'Z')
        {
            c[i]=(m_2*(a[i]-'A')+m_4)%26+'A';
        }
    }

    m_3=c;

    file.Open("加密文件2.txt",CFile::modeCreate);
	file.Close();
    file.Open("加密文件2.txt",CFile::modeWrite);
	file.Write(c,100);
    file.Close();
	MessageBox("加密完成","",MB_OK);

	UpdateData(false);	
}

void CHaoxueDlg::OnButton5() 
{
	// TODO: Add your control notification handler code here
    UpdateData(true);
	
	int x = m_2;
	int y = m_4;
	int a,b;
	a = (x-1)*(y-1);
    b = x*y;
	m_f = a;
	m_n = b;
	int A;
	for(A=1;A<=m_f;A++)
	{
	    if((A*m_e)%(m_f)==1)
			break;

	}
	m_d = A;//求d的逆

	UpdateData(false);	
}

void CHaoxueDlg::OnButton6() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CFile file(strFilePath, CFile::modeRead);
	char pBuf[100]={0};
	file.Read(pBuf,100);
	file.Close();



    CString strFilePath=pBuf;
    char a[100]={0};
	char b[100]={0};
	int c[100]={0};
	int i;

	memcpy(a,strFilePath,strFilePath.GetLength()); 
	for(i=0;i<strFilePath.GetLength();i++)
	{
		a[i]=(int)(a[i]-'0');
		c[i] = pow(a[i],m_e);
		c[i]=c[i]%m_n;
		c[i]=c[i]+'0';
		b[i]=c[i];
	}

m_3=b;


	file.Open("加密文件3.txt",CFile::modeCreate);
	file.Close();
    file.Open("加密文件3.txt",CFile::modeWrite);
	file.Write(b,100);
    file.Close();
	MessageBox("加密完成","",MB_OK);

	UpdateData(false);	
}

void CHaoxueDlg::OnButton7() 
{
	// TODO: Add your control notification handler code here
	UpdateData(true);
	CFile file(strFilePath, CFile::modeRead);
	char pBuf[100]={0};
	file.Read(pBuf,100);
	file.Close();

   CString strFilePath=pBuf;
	char a[100]={0};
	char b[100]={0};
	int c[100]={0};
	int i;
	memcpy(a,strFilePath,strFilePath.GetLength()); 
	for(i=0;i<strFilePath.GetLength();i++)
	{
		a[i]=(int)(a[i]-'0');
		c[i] = pow(a[i],m_d);
		c[i]=c[i]%m_n;
		c[i]=c[i]+'0';
		b[i]=c[i];
	}

	m_3=b;


	file.Open("解密文件2.txt",CFile::modeCreate);
	file.Close();
    file.Open("解密文件2.txt",CFile::modeWrite);
	file.Write(b,100);
    file.Close();
	MessageBox("加密完成","",MB_OK);

	UpdateData(false);	
}
