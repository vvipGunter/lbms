#if !defined(AFX_RXBUTTON_H__0B8546E4_594C_11D8_8750_5254AB32C8FB__INCLUDED_)
#define AFX_RXBUTTON_H__0B8546E4_594C_11D8_8750_5254AB32C8FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RxButton.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRxButton window

class CRxButton : public CButton
{
// Construction
public:
	CRxButton();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRxButton)
	public:
	virtual void DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct);
	protected:
	virtual void PreSubclassWindow();
	//}}AFX_VIRTUAL

// Implementation
public:
	void Bitmap(UINT ResNoNal,UINT ResDown);
	virtual ~CRxButton();

	// Generated message map functions
protected:
	//{{AFX_MSG(CRxButton)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	UINT m_ResNoNal,m_ResDown;

};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RXBUTTON_H__0B8546E4_594C_11D8_8750_5254AB32C8FB__INCLUDED_)
