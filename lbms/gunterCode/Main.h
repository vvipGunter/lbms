#if !defined(AFX_MAIN_H__126241F6_7ECD_4B8D_A2CE_E00717A7E7C5__INCLUDED_)
#define AFX_MAIN_H__126241F6_7ECD_4B8D_A2CE_E00717A7E7C5__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Main.h : header file
//
#include "RxButton.h"
/////////////////////////////////////////////////////////////////////////////
// CMain dialog

class CMain : public CDialog
{
// Construction
public:
	CString User;
	CMain(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CMain)
	enum { IDD = IDD_MY_DIALOG };
	CRxButton	m_ButOp;
	CRxButton	m_ButUnit;
	CRxButton	m_ButSort;
	CRxButton	m_ButMessage;
	CRxButton	m_ButDuty;
	CRxButton	m_ButCG;
	CRxButton	m_ButClime;
	CStatic    mypic;
	
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CMain)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CMain)
	virtual BOOL OnInitDialog();
	afx_msg void OnButClime();
	afx_msg void OnButUnit();
	afx_msg void OnButSort();
	afx_msg void OnButMessage();
	afx_msg void OnButDuty();
	afx_msg void OnButCG();
	afx_msg void OnButadd();
	afx_msg HBRUSH OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor);
	virtual void OnOK();
	
	virtual CString getNowTime();
	//ªÊ÷∆Õº–Œ
	virtual void PaintPic1();
	virtual void PaintPic2();
	virtual void PaintPic3();
	afx_msg void OnButOP();
	afx_msg void OnPaint();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_MAIN_H__126241F6_7ECD_4B8D_A2CE_E00717A7E7C5__INCLUDED_)
