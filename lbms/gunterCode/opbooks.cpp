// opbooks.cpp : implementation file
//

#include "stdafx.h"
#include "gunterLBMS.h"
#include "opbooks.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// Copbooks dialog


Copbooks::Copbooks(CWnd* pParent /*=NULL*/)
	: CDialog(Copbooks::IDD, pParent)
{
	//{{AFX_DATA_INIT(Copbooks)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void Copbooks::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Copbooks)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Copbooks, CDialog)
	//{{AFX_MSG_MAP(Copbooks)
	ON_BN_CLICKED(IDC_BUTADD, OnButadd)
	ON_BN_CLICKED(IDC_BUTupdate, OnBUTupdate1)
	ON_BN_CLICKED(IDC_BUTdelete1, OnBUTdelete1)
	ON_BN_CLICKED(IDC_BUTExit1, OnBUTExit1)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Copbooks message handlers

void Copbooks::OnButadd() 
{
	// TODO: Add your control notification handler code here
	
}

void Copbooks::OnBUTupdate1() 
{
	// TODO: Add your control notification handler code here
	
}

void Copbooks::OnBUTdelete1() 
{
	// TODO: Add your control notification handler code here
	
}

void Copbooks::OnBUTExit1() 
{
	// TODO: Add your control notification handler code here
	this->OnCancel();
}
