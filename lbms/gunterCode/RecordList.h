#if !defined(AFX_RECORDLIST_H__9ADE1301_5C6F_11D8_8750_5254AB32C8FB__INCLUDED_)
#define AFX_RECORDLIST_H__9ADE1301_5C6F_11D8_8750_5254AB32C8FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RecordList.h : header file
#include "RainFunction.h"
/////////////////////////////////////////////////////////////////////////////
// CRecordList window

class CRecordList : public CListBox
{
// Construction
public:
	CRecordList();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRecordList)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

// Implementation
public:
	int Recno;
	void Init(CString FieldName);
	_RecordsetPtr record;
	CRainFunction function;
	CString DateBaseName;
	virtual ~CRecordList();

	// Generated message map functions
protected:
	//{{AFX_MSG(CRecordList)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	CString Field;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECORDLIST_H__9ADE1301_5C6F_11D8_8750_5254AB32C8FB__INCLUDED_)
