#if !defined(AFX_RECORDEDITBOX_H__F2AC9281_5D5C_11D8_8750_5254AB32C8FB__INCLUDED_)
#define AFX_RECORDEDITBOX_H__F2AC9281_5D5C_11D8_8750_5254AB32C8FB__INCLUDED_

#include "RainFunction.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RecordEditBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRecordEditBox window

class CRecordEditBox : public CEdit
{
// Construction
public:
	CRecordEditBox();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRecordEditBox)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

// Implementation
public:
	void Init(_RecordsetPtr Record,CString FieldName=" ");
	CString _FieldName;
	bool EmptyValidate;
	_RecordsetPtr _Record;
	virtual ~CRecordEditBox();

	// Generated message map functions
protected:
	//{{AFX_MSG(CRecordEditBox)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	CRainFunction function;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECORDEDITBOX_H__F2AC9281_5D5C_11D8_8750_5254AB32C8FB__INCLUDED_)
