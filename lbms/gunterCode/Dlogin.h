#if !defined(AFX_DLOGIN_H__678AB2CA_5EEE_11D8_8751_5254AB32C8FB__INCLUDED_)
#define AFX_DLOGIN_H__678AB2CA_5EEE_11D8_8751_5254AB32C8FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Dlogin.h : header file
//
#include "RainFunction.h"
#include "RecordComboBox.h"
#include"RecordEditBox.h"
/////////////////////////////////////////////////////////////////////////////
// CDlogin dialog

class CDlogin : public CDialog
{
// Construction
public:
	CDlogin(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDlogin)
	enum { IDD = IDD_DIALogin };
	CRecordEditBox	m_EdtPassWard;
	CRecordComboBox	m_ComName;
	CButton	m_ButLogin;
	CButton	m_ButExit;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDlogin)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDlogin)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnBUTLogin();
	afx_msg void OnButexit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	int Time;
	_RecordsetPtr rst;
	CRainFunction function;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DLOGIN_H__678AB2CA_5EEE_11D8_8751_5254AB32C8FB__INCLUDED_)
