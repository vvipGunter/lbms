#if !defined(AFX_USERSRIGHTS_H__225AEC56_BC88_4F75_855A_0FD46FBF8E2F__INCLUDED_)
#define AFX_USERSRIGHTS_H__225AEC56_BC88_4F75_855A_0FD46FBF8E2F__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// usersrights.h : header file
//

#include "RecordList.h"
#include "RecordComboBox.h"
#include"RecordEditBox.h"
#include "RainFunction.h"
/////////////////////////////////////////////////////////////////////////////
// Cusersrights dialog

class Cusersrights : public CDialog
{
// Construction
public:
	Cusersrights(CWnd* pParent = NULL);   // standard constructor
    //
   	_RecordsetPtr rst;
	CRainFunction function;
	CRecordList	m_List;
    void Display();
// Dialog Data
	//{{AFX_DATA(Cusersrights)
	enum { IDD = IDD_Usersrights };
	//CListBox m_List;
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Cusersrights)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Cusersrights)
    virtual BOOL OnInitDialog();
	afx_msg void OnSelchangeList();
	virtual void OnButexit2();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_USERSRIGHTS_H__225AEC56_BC88_4F75_855A_0FD46FBF8E2F__INCLUDED_)
