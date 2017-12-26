#if !defined(AFX_OUTIN_H__D5983B3D_463F_4774_8D51_0D48943DA5E6__INCLUDED_)
#define AFX_OUTIN_H__D5983B3D_463F_4774_8D51_0D48943DA5E6__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// outin.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Coutin dialog

class Coutin : public CDialog
{
// Construction
public:
	Coutin(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Coutin)
	enum { IDD = IDD_outin };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Coutin)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Coutin)
	afx_msg void OnButexit();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OUTIN_H__D5983B3D_463F_4774_8D51_0D48943DA5E6__INCLUDED_)
