// RusLatDlg.cpp : implementation file
//

#include "stdafx.h"
#include "RusLat.h"
#include "RusLatDlg.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialog
{
public:
	CAboutDlg();

// Dialog Data
	enum { IDD = IDD_ABOUTBOX };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
};

CAboutDlg::CAboutDlg() : CDialog(CAboutDlg::IDD)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialog)
END_MESSAGE_MAP()


// CRusLatDlg dialog



CRusLatDlg::CRusLatDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CRusLatDlg::IDD, pParent)
	, m_strText(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CRusLatDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, m_strText);
	DDX_Control(pDX, IDC_EDIT1, m_edtText);
}

BEGIN_MESSAGE_MAP(CRusLatDlg, CDialog)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	//}}AFX_MSG_MAP
	ON_BN_CLICKED(IDC_BTNCONVERT, OnBnClickedBtnconvert)
	ON_BN_CLICKED(IDC_BTNCOPYALL, OnBnClickedBtncopyall)
END_MESSAGE_MAP()


// CRusLatDlg message handlers

BOOL CRusLatDlg::OnInitDialog()
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

void CRusLatDlg::OnSysCommand(UINT nID, LPARAM lParam)
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

void CRusLatDlg::OnPaint() 
{
	if (IsIconic())
	{
		CPaintDC dc(this); // device context for painting

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

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

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CRusLatDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}

void CRusLatDlg::OnBnClickedBtnconvert()
{
	CStringList Latin;
	CStringList Russian;

	Russian.RemoveAll();
	Russian.AddTail( "à" );
	Russian.AddTail( "á" );
	Russian.AddTail( "â" );
	Russian.AddTail( "ã" );
	Russian.AddTail( "ä" );
	Russian.AddTail( "å" );
	Russian.AddTail( "¸" );
	Russian.AddTail( "æ" );
	Russian.AddTail( "ç" );
	Russian.AddTail( "è" );
	Russian.AddTail( "é" );
	Russian.AddTail( "ê" );
	Russian.AddTail( "ë" );
	Russian.AddTail( "ì" );
	Russian.AddTail( "í" );
	Russian.AddTail( "î" );
	Russian.AddTail( "ï" );
	Russian.AddTail( "ð" );
	Russian.AddTail( "ñ" );
	Russian.AddTail( "ò" );
	Russian.AddTail( "ó" );
	Russian.AddTail( "ô" );
	Russian.AddTail( "õ" );
	Russian.AddTail( "ö" );
	Russian.AddTail( "÷" );
	Russian.AddTail( "ø" );
	Russian.AddTail( "ù" );
	Russian.AddTail( "ú" );
	Russian.AddTail( "û" );
	Russian.AddTail( "ü" );
	Russian.AddTail( "ý" );
	Russian.AddTail( "þ" );
	Russian.AddTail( "ÿ" );

	Latin.RemoveAll();
	Latin.AddTail( "a" );
	Latin.AddTail( "b" );
	Latin.AddTail( "v" );
	Latin.AddTail( "g" );
	Latin.AddTail( "d" );
	Latin.AddTail( "e" );
	Latin.AddTail( "yo" );
	Latin.AddTail( "zh" );
	Latin.AddTail( "z" );
	Latin.AddTail( "i" );
	Latin.AddTail( "y" );
	Latin.AddTail( "k" );
	Latin.AddTail( "l" );
	Latin.AddTail( "m" );
	Latin.AddTail( "n" );
	Latin.AddTail( "o" );
	Latin.AddTail( "p" );
	Latin.AddTail( "r" );
	Latin.AddTail( "s" );
	Latin.AddTail( "t" );
	Latin.AddTail( "u" );
	Latin.AddTail( "f" );
	Latin.AddTail( "h" );
	Latin.AddTail( "c" );
	Latin.AddTail( "ch" );
	Latin.AddTail( "sh" );
	Latin.AddTail( "sch" );
	Latin.AddTail( "'" );
	Latin.AddTail( "y" );
	Latin.AddTail( "'" );
	Latin.AddTail( "e" );
	Latin.AddTail( "yu" );
	Latin.AddTail( "ya" );
	
	UpdateData( TRUE );

	for( int i = 0, idx; i < 33; i++ )
	{
		CString srch = Russian.GetAt( Russian.FindIndex( i ) );
		CString rplc = Latin.GetAt( Latin.FindIndex( i ) );

		while( ( idx = m_strText.Find( srch ) ) != -1 )
		{
			m_strText.Delete( idx, srch.GetLength() );
			m_strText.Insert( idx, rplc );
		}

		CString strTemp;

		strTemp = srch[0];
		strTemp.MakeUpper();
		srch.Delete( 0, 1 );
		srch.Insert( 0, strTemp );

		strTemp = rplc[0];
		strTemp.MakeUpper();
		rplc.Delete( 0, 1 );
		rplc.Insert( 0, strTemp );

		while( ( idx = m_strText.Find( srch ) ) != -1 )
		{
			m_strText.Delete( idx, srch.GetLength() );
			m_strText.Insert( idx, rplc );
		}

	}

	UpdateData( FALSE );
}

void CRusLatDlg::OnBnClickedBtncopyall()
{
	m_edtText.SetSel( 0, -1, TRUE );
	m_edtText.Copy();
}
