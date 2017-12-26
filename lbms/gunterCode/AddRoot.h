#if !defined(AFX_ADDROOT_H__D90BE6A1_5B40_11D8_8750_5254AB32C8FB__INCLUDED_)
#define AFX_ADDROOT_H__D90BE6A1_5B40_11D8_8750_5254AB32C8FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// AddRoot.h : header file
//
#include "Rainfunction.h"
/////////////////////////////////////////////////////////////////////////////
// CAddRoot dialog

class CAddRoot : public CDialog
{
// Construction
public:
	CString EdtNameText;
	int Connection;
	int Style;
	int RootStyle(HTREEITEM Root,CString  Field);
	CAddRoot(CWnd* pParent = NULL);   // standard constructor
// Dialog Data
	//{{AFX_DATA(CAddRoot)
	enum { IDD = IDD_DIAAddItem };
	CComboBox	m_ComConnection;
	CButton	m_ButSure;
	CEdit	m_EdtName;
	CComboBox	m_ComStyle;
	CString	m_StaItem;
	HTREEITEM Root;
	HTREEITEM ParentRoot;
	CTreeCtrl * m_tree;
	CRainFunction m_function;
	bool Rady;

	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAddRoot)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CAddRoot)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnButexit();
	afx_msg void OnBUTSure();
	afx_msg void OnClose();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_ADDROOT_H__D90BE6A1_5B40_11D8_8750_5254AB32C8FB__INCLUDED_)
