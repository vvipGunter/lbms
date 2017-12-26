// IDD_books.cpp : implementation file
//

#include "stdafx.h"
#include "gunterLBMS.h"
#include "IDD_books.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// IDD_books dialog


IDD_books::IDD_books(CWnd* pParent /*=NULL*/)
	: CDialog(IDD_books::IDD, pParent)
{
	//{{AFX_DATA_INIT(IDD_books)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void IDD_books::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(IDD_books)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(IDD_books, CDialog)
	//{{AFX_MSG_MAP(IDD_books)
	ON_BN_CLICKED(IDC_BUTADD, OnButadd)
	ON_BN_CLICKED(IDC_BUTupdate, OnBUTupdate)
	ON_BN_CLICKED(IDC_BUTdelete1, OnBUTdelete1)
	ON_BN_CLICKED(IDC_BUTExit1, OnBUTExit1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// IDD_books message handlers

void IDD_books::OnButadd() 
{
	// TODO: Add your control notification handler code here
    
    	//	MessageBox("感谢您初次使用客户管理系统！请在进入程序主界面后添加一新用户！","系统提示",MB_OK|MB_ICONQUESTION);
		
		MessageBox("对不起！您不能登录本系统，请与管理员联系!","系统提示",MB_OK|MB_ICONSTOP);
}

void IDD_books::OnBUTupdate() 
{
	// TODO: Add your control notification handler code here
	
}

void IDD_books::OnBUTdelete1() 
{
	// TODO: Add your control notification handler code here
	
}

void IDD_books::OnBUTExit1() 
{
	// TODO: Add your control notification handler code here
	this->OnCancel();
}
