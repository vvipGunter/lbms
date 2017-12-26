#if !defined(AFX_IDD_BOOKS_H__4F9BA27B_7E6E_4D7D_B6AA_3D071251435E__INCLUDED_)
#define AFX_IDD_BOOKS_H__4F9BA27B_7E6E_4D7D_B6AA_3D071251435E__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// IDD_books.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// IDD_books dialog

class IDD_books : public CDialog
{
// Construction
public:
	IDD_books(CWnd* pParent = NULL);   // standard constructor

// Dialog Data
	//{{AFX_DATA(IDD_books)
	enum { IDD = IDD_OpBooks };
		// NOTE: the ClassWizard will add data members here
	//}}AFX_DATA


// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(IDD_books)
	protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV support
	//}}AFX_VIRTUAL

// Implementation
protected:

	// Generated message map functions
	//{{AFX_MSG(IDD_books)
	afx_msg void OnButadd();
	afx_msg void OnBUTupdate();
	afx_msg void OnBUTdelete1();
	afx_msg void OnBUTExit1();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
};

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_IDD_BOOKS_H__4F9BA27B_7E6E_4D7D_B6AA_3D071251435E__INCLUDED_)
