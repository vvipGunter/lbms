// ClientStyle.cpp : implementation file
//

#include "stdafx.h"
#include "gunterLBMS.h"
#include "ClientStyle.h"
#include "Dlg.h"
#include "RainFunction.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern _ConnectionPtr cnn;
/////////////////////////////////////////////////////////////////////////////
// CClientStyle dialog


CClientStyle::CClientStyle(CWnd* pParent /*=NULL*/)
	: CDialog(CClientStyle::IDD, pParent)
{
	//{{AFX_DATA_INIT(CClientStyle)
	//}}AFX_DATA_INIT
}


void CClientStyle::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CClientStyle)
	DDX_Control(pDX, IDC_STAValue, m_StaValue);
	DDX_Control(pDX, IDC_LIST1, m_List);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CClientStyle, CDialog)
	//{{AFX_MSG_MAP(CClientStyle)
	ON_BN_CLICKED(IDC_BUTADD, OnButadd)
	ON_BN_CLICKED(IDC_BUTDele, OnBUTDele)
	ON_BN_CLICKED(IDC_BUTEXIT, OnButexit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CClientStyle message handlers

void CClientStyle::OnOK() 
{
	// TODO: Add extra validation here
	
	//CDialog::OnOK();
}

void CClientStyle::OnButadd() 
{

	int NewNumber;
	CString sSQL,Style,LetterStyle;
	CDlg dlg;
	dlg.TipText=DlgTipText;
	dlg.DoModal();
	Style=dlg.Value;
	if(Style.IsEmpty()==false)
	{
		try{
		NewNumber=function.AutoNumber(0,this->DateBase);
		LetterStyle=function.CharToLetterCode(Style);
		sSQL.Format("Insert into %s values(%d,'%s','%s')",this->DateBase,NewNumber,Style,LetterStyle);
		cnn->Execute((_bstr_t)sSQL,NULL,adCmdText);
		this->m_List.AddString(Style);
		}
		catch(...)
		{
			MessageBox("插入记录时出错！","系统提示",MB_OK|MB_ICONSTOP);
		}
	}
}

BOOL CClientStyle::OnInitDialog() 
{
	CDialog::OnInitDialog();
	this->SetWindowText(Value);
	this->m_StaValue.SetWindowText(Value);
	_RecordsetPtr rst;
	CString style;
	rst.CreateInstance(__uuidof(Recordset));
	rst=cnn->Execute((_bstr_t)this->DateBase,NULL,adCmdTable);
	if(function.RecordCount(rst)>0)
	{
		rst->MoveFirst();
		for(int i=0;i<function.RecordCount(rst);i++)
		{
			rst->MoveFirst();
			rst->Move(i);
			style=(char*)(_bstr_t)rst->GetCollect("名称");
			this->m_List.AddString(style);
		}
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CClientStyle::OnBUTDele() 
{
	CString sSQL,DeleValue;
	int a=MessageBox("确定删除此信息吗？","系统提示",MB_ICONQUESTION|MB_OKCANCEL);
	if(a==1)
	{
		this->m_List.GetText(m_List.GetCurSel(),DeleValue);
		this->m_List.DeleteString(m_List.GetCurSel());
		sSQL.Format("DELETE FROM %s WHERE 名称='%s'",this->DateBase,DeleValue);
		cnn->Execute((_bstr_t)sSQL,NULL,adCmdText);

	}
}

void CClientStyle::OnButexit() 
{
	this->OnCancel();	
}
