// Դ����.h : main header file for the Դ���� application
//  Դ����Ӧ�ó��� ����Ҫͷ�ļ�

#if !defined(AFX__H__573F9927_58AA_11D8_8750_5254AB32C8FB__INCLUDED_)
#define AFX__H__573F9927_58AA_11D8_8750_5254AB32C8FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "Դ����_i.h"
/////////////////////////////////////////////////////////////////////////////
// CMyApp:
// See Դ����.cpp for the implementation of this class
//�鿴 Դ����.cpp Ϊ������ִ��
class CMyApp : public CWinApp
{
public:
	CMyApp();

// Overrides ����
	// ClassWizard generated virtual function overrides ��ClassWizard ���ɵĳ���������
	//{{AFX_VIRTUAL(CMyApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation ִ��

	//{{AFX_MSG(CMyApp)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()
private:
private:
};


/////////////////////////////////////////////////////////////////////////////

//{{AFX_INSERT_LOCATION}}
// Microsoft Visual C++ will insert additional declarations immediately before the previous line.

#endif // !defined(AFX__H__573F9927_58AA_11D8_8750_5254AB32C8FB__INCLUDED_)
