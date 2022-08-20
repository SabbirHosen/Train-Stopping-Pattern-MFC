
// MFCApplicationTrainDlg.h : header file
//

#pragma once


// CMFCApplicationTrainDlg dialog
class CMFCApplicationTrainDlg : public CDialogEx
{
// Construction
public:
	CMFCApplicationTrainDlg(CWnd* pParent = nullptr);	// standard constructor

// Dialog Data
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCAPPLICATIONTRAIN_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV support


// Implementation
protected:
	HICON m_hIcon;

	// Generated message map functions
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	CEdit m_strEditCrtl;
	CString m_strEditVal;
	CEdit m_strOutCrtl;
	CString m_strOutVal;
	afx_msg void OnBnClickedSubmit();
	afx_msg void OnEnChangeInput();
};
