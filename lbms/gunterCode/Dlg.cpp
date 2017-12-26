// Dlg.cpp : implementation file
//

#include "stdafx.h"
#include "gunterLBMS.h"
#include "Dlg.h"
#include "RainFunction.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDlg dialog


CDlg::CDlg(CWnd* pParent /*=NULL*/)
	: CDialog(CDlg::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlg)
	TipText = _T("");
	//}}AFX_DATA_INIT
}


void CDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlg)
	DDX_Control(pDX, IDC_BUTSure, m_ButSure);
	DDX_Control(pDX, IDC_EdtValue, m_EdtValue);
	DDX_Text(pDX, IDC_TipText, TipText);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlg, CDialog)
	//{{AFX_MSG_MAP(CDlg)
	ON_BN_CLICKED(IDC_BUTSure, OnBUTSure)
	ON_BN_CLICKED(IDC_BUTEXIT, OnButexit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlg message handlers

void CDlg::OnOK() 
{
	// TODO: Add extra validation here

	//CDialog::OnOK();
}

void CDlg::OnCancel() 
{
	CDialog::OnCancel();
}

void CDlg::OnBUTSure() 
{
	CString thisValue;
	m_EdtValue.GetWindowText(thisValue);
	Value=thisValue;
	this->OnCancel();
	
}

void CDlg::OnButexit() 
{
	this->OnCancel();	
}

BOOL CDlg::PreTranslateMessage(MSG* pMsg) 
{
	function.CMessage(this,pMsg,&m_EdtValue,&m_ButSure);
	return CDialog::PreTranslateMessage(pMsg);
}
