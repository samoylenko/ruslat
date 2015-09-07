// RusLatDlg.h : header file
//

#pragma once
#include "afxwin.h"

// CRusLatDlg dialog
class CRusLatDlg : public CDialog
{
// Construction
public:
	CRusLatDlg(CWnd* pParent = NULL);	// standard constructor

// Dialog Data
	enum { IDD = IDD_RUSLAT_DIALOG };

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
	CString m_strText;
	afx_msg void OnBnClickedBtnconvert();
	afx_msg void OnBnClickedBtncopyall();
	CEdit m_edtText;
};
