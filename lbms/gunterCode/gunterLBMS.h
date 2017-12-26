// 源程序.h : main header file for the 源程序 application
//  源程序应用程序 的主要头文件

#if !defined(AFX__H__573F9927_58AA_11D8_8750_5254AB32C8FB__INCLUDED_)
#define AFX__H__573F9927_58AA_11D8_8750_5254AB32C8FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

#ifndef __AFXWIN_H__
	#error include 'stdafx.h' before including this file for PCH
#endif

#include "resource.h"		// main symbols
#include "源程序_i.h"
/////////////////////////////////////////////////////////////////////////////
// CMyApp:
// See 源程序.cpp for the implementation of this class
//查看 源程序.cpp 为这个类的执行
class CMyApp : public CWinApp
{
public:
	CMyApp();

// Overrides 重载
	// ClassWizard generated virtual function overrides ，ClassWizard 生成的抽象函数重载
	//{{AFX_VIRTUAL(CMyApp)
	public:
	virtual BOOL InitInstance();
	//}}AFX_VIRTUAL

// Implementation 执行

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
