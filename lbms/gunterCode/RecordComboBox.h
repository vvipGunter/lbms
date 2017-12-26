#if !defined(AFX_RECORDCOMBOBOX_H__9ADE130D_5C6F_11D8_8750_5254AB32C8FB__INCLUDED_)
#define AFX_RECORDCOMBOBOX_H__9ADE130D_5C6F_11D8_8750_5254AB32C8FB__INCLUDED_

#include "RainFunction.h"	// Added by ClassView
#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// RecordComboBox.h : header file
//

/////////////////////////////////////////////////////////////////////////////
// CRecordComboBox window

class CRecordComboBox : public CComboBox
{
// Construction
public:
	CRecordComboBox();

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CRecordComboBox)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

// Implementation
public:
	CString sID;
	int IDStyle;
	bool EmptyValidate;              //是否为空验证
	int Recno;                       //数据集/结果集的编号
	void Init(CString FieldName);
	CString DateBaseName;
	_RecordsetPtr record;
	virtual ~CRecordComboBox();

	// Generated message map functions
protected:
	//{{AFX_MSG(CRecordComboBox)
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
private:
	CString Field;
	CRainFunction function;
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_RECORDCOMBOBOX_H__9ADE130D_5C6F_11D8_8750_5254AB32C8FB__INCLUDED_)
