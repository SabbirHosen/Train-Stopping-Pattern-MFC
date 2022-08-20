
// MFCApplicationTrainDlg.cpp : implementation file
//

#include "pch.h"
#include "framework.h"
#include "MFCApplicationTrain.h"
#include "MFCApplicationTrainDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CAboutDlg dialog used for App About

class CAboutDlg : public CDialogEx
{
public:
	CAboutDlg();

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_ABOUTBOX };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support

// Implementation
protected:
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnEnChangeInput();
};

CAboutDlg::CAboutDlg() : CDialogEx(IDD_ABOUTBOX)
{
}

void CAboutDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(CAboutDlg, CDialogEx)
	ON_EN_CHANGE(IDC_INPUT, &CAboutDlg::OnEnChangeInput)
END_MESSAGE_MAP()


// CMFCApplicationTrainDlg dialog



CMFCApplicationTrainDlg::CMFCApplicationTrainDlg(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_MFCAPPLICATIONTRAIN_DIALOG, pParent)
	, m_strEditVal(_T(""))
	, m_strOutVal(_T(""))
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void CMFCApplicationTrainDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Control(pDX, IDC_INPUT, m_strEditCrtl);
	DDX_Text(pDX, IDC_INPUT, m_strEditVal);
	DDX_Control(pDX, IDC_OUTPUT, m_strOutCrtl);
	DDX_Text(pDX, IDC_OUTPUT, m_strOutVal);
}

BEGIN_MESSAGE_MAP(CMFCApplicationTrainDlg, CDialogEx)
	ON_WM_SYSCOMMAND()
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(ID_SUBMIT, &CMFCApplicationTrainDlg::OnBnClickedSubmit)
	ON_EN_CHANGE(IDC_INPUT, &CMFCApplicationTrainDlg::OnEnChangeInput)
END_MESSAGE_MAP()


// CMFCApplicationTrainDlg message handlers

BOOL CMFCApplicationTrainDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// Add "About..." menu item to system menu.

	// IDM_ABOUTBOX must be in the system command range.
	ASSERT((IDM_ABOUTBOX & 0xFFF0) == IDM_ABOUTBOX);
	ASSERT(IDM_ABOUTBOX < 0xF000);

	CMenu* pSysMenu = GetSystemMenu(FALSE);
	if (pSysMenu != nullptr)
	{
		BOOL bNameValid;
		CString strAboutMenu;
		bNameValid = strAboutMenu.LoadString(IDS_ABOUTBOX);
		ASSERT(bNameValid);
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

	ShowWindow(SW_MAXIMIZE);

	ShowWindow(SW_MINIMIZE);

	// TODO: Add extra initialization here
	UpdateData(TRUE);
	m_strOutCrtl.SetWindowText(_T(" "));

	return TRUE;  // return TRUE  unless you set the focus to a control
}

void CMFCApplicationTrainDlg::OnSysCommand(UINT nID, LPARAM lParam)
{
	if ((nID & 0xFFF0) == IDM_ABOUTBOX)
	{
		CAboutDlg dlgAbout;
		dlgAbout.DoModal();
	}
	else
	{
		CDialogEx::OnSysCommand(nID, lParam);
	}
}

// If you add a minimize button to your dialog, you will need the code below
//  to draw the icon.  For MFC applications using the document/view model,
//  this is automatically done for you by the framework.

void CMFCApplicationTrainDlg::OnPaint()
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
		CDialogEx::OnPaint();
	}
}

// The system calls this function to obtain the cursor to display while the user drags
//  the minimized window.
HCURSOR CMFCApplicationTrainDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void CMFCApplicationTrainDlg::OnBnClickedSubmit()
{
	// TODO: Add your control notification handler code here
	UpdateData(TRUE);
	CString b = _T("");
	CStdioFile file;
	if (m_strEditVal.GetLength() == 0) {

		AfxMessageBox(L"You must specify the text.");
		return;
	}
	file.Open(L"..\\test.txt", CFile::modeCreate |
		CFile::modeWrite | CFile::typeText);
	m_strEditCrtl.GetWindowText(b);

	//Read from the file and display
	file.WriteString(b);
	file.Close();


	CString strText = _T("");
	CString szLine = _T("");

	CStdioFile fileout;
	fileout.Open(L"..\\test.txt", CFile::modeRead | CFile::typeText);
	while (fileout.ReadString(szLine))
	{
		strText += szLine;
		strText += _T("\r\n");
	}
	//m_strEdit.SetWindowText(strText);
	//file.ReadString(m_strEditCtrl);
	m_strOutVal = strText;
	fileout.Close();
	UpdateData(FALSE);
}


/*void CAboutDlg::OnEnChangeInput()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	

}*/


void CMFCApplicationTrainDlg::OnEnChangeInput()
{
	// TODO:  If this is a RICHEDIT control, the control will not
	// send this notification unless you override the CDialogEx::OnInitDialog()
	// function and call CRichEditCtrl().SetEventMask()
	// with the ENM_CHANGE flag ORed into the mask.

	// TODO:  Add your control notification handler code here
	UpdateData(TRUE);
	m_strOutCrtl.SetWindowText(_T(" "));
}
