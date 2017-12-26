// outin.cpp : implementation file
//

#include "stdafx.h"
#include "gunterLBMS.h"
#include "outin.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Coutin dialog


Coutin::Coutin(CWnd* pParent /*=NULL*/)
	: CDialog(Coutin::IDD, pParent)
{
	//{{AFX_DATA_INIT(Coutin)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Coutin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Coutin)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Coutin, CDialog)
	//{{AFX_MSG_MAP(Coutin)
	ON_BN_CLICKED(IDC_BUTEXIT, OnButexit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Coutin message handlers

void Coutin::OnButexit() 
{
	// TODO: Add your control notification handler code here
	this->OnCancel();
}
