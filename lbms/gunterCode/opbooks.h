#if !defined(AFX_OPBOOKS_H__018FADCF_307E_4AEB_AD79_EB9E8F735E31__INCLUDED_)
#define AFX_OPBOOKS_H__018FADCF_307E_4AEB_AD79_EB9E8F735E31__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// opbooks.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// Copbooks dialog

class Copbooks : public CDialog
{
// Construction
public:
	Copbooks(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(Copbooks)
	enum { IDD = IDD_OpBooks };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(Copbooks)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(Copbooks)
	afx_msg void OnButadd();
	afx_msg void OnBUTupdate1();
	afx_msg void OnBUTdelete1();
	afx_msg void OnBUTExit1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_OPBOOKS_H__018FADCF_307E_4AEB_AD79_EB9E8F735E31__INCLUDED_)
