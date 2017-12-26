#if !defined(AFX_DUSER_H__A3E5F581_5F0D_11D8_8751_5254AB32C8FB__INCLUDED_)
#define AFX_DUSER_H__A3E5F581_5F0D_11D8_8751_5254AB32C8FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DUser.h : header file
//
#include"RecordEditBox.h"
#include "RecordList.h"
#include "RainFunction.h"
/////////////////////////////////////////////////////////////////////////////
// CDUser dialog

class CDUser : public CDialog
{
// Construction
public:
	bool AddOrChange;
	_RecordsetPtr rst;
	CRainFunction function;
	void Enabled(bool enabled);
	void Display();
	void ClearFrom();
	CDUser(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDUser)
	enum { IDD = IDD_DIAAddUser };
	CStatic	m_StaID;
	CRecordList	m_List;
	CRecordEditBox	m_EdtPassWard;
	CRecordEditBox	m_EdtName;
	CRecordEditBox	m_EdtAffarmPassWard;
	CButton	m_ButUndo;
	CButton	m_ButSave;
	CButton	m_ButExit;
	CButton	m_ButDele;
	CButton	m_ButChange;
	CButton	m_ButAdd;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDUser)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDUser)
	virtual void OnOK();
	virtual BOOL OnInitDialog();
	afx_msg void OnButadd();
	afx_msg void OnBUTChange();
	afx_msg void OnButdelete();
	afx_msg void OnBUTSave();
	afx_msg void OnSelchangeList();
	afx_msg void OnBUTUnDo();
	afx_msg void OnButexit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DUSER_H__A3E5F581_5F0D_11D8_8751_5254AB32C8FB__INCLUDED_)
