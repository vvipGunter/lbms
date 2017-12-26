#if !defined(AFX_DLG_H__C6386828_5BC5_11D8_8750_5254AB32C8FB__INCLUDED_)
#define AFX_DLG_H__C6386828_5BC5_11D8_8750_5254AB32C8FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dlg.h : header file
//
#include "RainFunction.h"
/////////////////////////////////////////////////////////////////////////////
// CDlg dialog

class CDlg : public CDialog
{
// Construction
public:
	CString Value;
	CDlg(CWnd* pParent = NULL);   // standard constructor
	CRainFunction function;
// Dialog Data
	//{{AFX_DATA(CDlg)
	enum { IDD = IDD_DlgDlg };
	CButton	m_ButSure;
	CEdit	m_EdtValue;
	CString	TipText;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlg)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlg)
	virtual void OnOK();
	virtual void OnCancel();
	afx_msg void OnBUTSure();
	afx_msg void OnButexit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLG_H__C6386828_5BC5_11D8_8750_5254AB32C8FB__INCLUDED_)
