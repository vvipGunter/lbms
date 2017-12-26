#if !defined(AFX_CLIENTSTYLE_H__C6386827_5BC5_11D8_8750_5254AB32C8FB__INCLUDED_)
#define AFX_CLIENTSTYLE_H__C6386827_5BC5_11D8_8750_5254AB32C8FB__INCLUDED_

#include "RainFunction.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// ClientStyle.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CClientStyle dialog

class CClientStyle : public CDialog
{
// Construction
public:
	CString  DlgTipText;
	CString DateBase;
	CRainFunction function;
	CString Value;
	CClientStyle(CWnd* pParent = NULL);   // standard constructor 标准构造器
	
// Dialog Data
	//{{AFX_DATA(CClientStyle)
	enum { IDD = IDD_Style };
	CStatic	m_StaValue;
	CListBox	m_List;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CClientStyle)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CClientStyle)
	virtual void OnOK();
	afx_msg void OnButadd();
	virtual BOOL OnInitDialog();
	afx_msg void OnBUTDele();
	afx_msg void OnButexit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_CLIENTSTYLE_H__C6386827_5BC5_11D8_8750_5254AB32C8FB__INCLUDED_)
