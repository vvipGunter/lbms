#if !defined(AFX_DBSLIDER_H__A0943185_5BE3_11D8_8750_5254AB32C8FB__INCLUDED_)
#define AFX_DBSLIDER_H__A0943185_5BE3_11D8_8750_5254AB32C8FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000
// DBSlider.h : header file
//
#include "Rainfunction.h"
/////////////////////////////////////////////////////////////////////////////
// CDBSlider window

class CDBSlider : public CSliderCtrl
{
// Construction 构造函数
public:
	CDBSlider();

// Attributes 属性，特性
public:

// Operations   操作
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDBSlider)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

// Implementation 执行
public:
	int Record;
	void Init();
	_RecordsetPtr Recordset;
	CRainFunction function;
	virtual ~CDBSlider();        //析构函数
	
	// Generated message map functions  生成的消息映射函数
protected:
	//{{AFX_MSG(CDBSlider)
		// NOTE - the ClassWizard will add and remove member functions here.
	//}}AFX_MSG

	DECLARE_MESSAGE_MAP()
};

/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX_DBSLIDER_H__A0943185_5BE3_11D8_8750_5254AB32C8FB__INCLUDED_)
