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
// Construction ���캯��
public:
	CDBSlider();

// Attributes ���ԣ�����
public:

// Operations   ����
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CDBSlider)
	public:
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	//}}AFX_VIRTUAL

// Implementation ִ��
public:
	int Record;
	void Init();
	_RecordsetPtr Recordset;
	CRainFunction function;
	virtual ~CDBSlider();        //��������
	
	// Generated message map functions  ���ɵ���Ϣӳ�亯��
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
