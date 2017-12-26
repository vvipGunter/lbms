#if !defined(AFX_DUTY_H__1A581AA1_5C6A_11D8_8750_5254AB32C8FB__INCLUDED_)
#define AFX_DUTY_H__1A581AA1_5C6A_11D8_8750_5254AB32C8FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// Duty.h : header file
//
#include "RecordList.h"
#include "RecordComboBox.h"
/////////////////////////////////////////////////////////////////////////////
// CDuty dialog

class CDuty : public CDialog
{
// Construction
public:
	void ClearFrom();
	void Enabled(bool enabled);
	void Display();
	_RecordsetPtr rst;
	CRainFunction function;
	CDuty(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(CDuty)
	enum { IDD = IDD_DIADuty };
	CButton	m_ButUndo;
	CButton	m_ButSave;
	CButton	m_ButExit;
	CButton	m_ButDelete;
	CButton	m_ButChange;
	CButton	m_ButAdd;
	CRecordComboBox	m_ComDuty;
	CEdit	m_EdtLetterName;
	CEdit	m_EdtName;
	CStatic	m_StaID;
	CRecordList	m_List;
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDuty)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(CDuty)
	virtual BOOL OnInitDialog();
	virtual void OnOK();
	afx_msg void OnButexit();
	afx_msg void OnButadd();
	afx_msg void OnBUTChange();
	afx_msg void OnButdelete();
	afx_msg void OnBUTSave();
	afx_msg void OnBUTUnDo();
	afx_msg void OnChangeEDTName();
	afx_msg void OnSelchangeList2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
	bool AddorChange;
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DUTY_H__1A581AA1_5C6A_11D8_8750_5254AB32C8FB__INCLUDED_)
