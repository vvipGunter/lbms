// AddRoot.cpp : implementation file
//

#include "stdafx.h"
#include "gunterLBMS.h"
#include "AddRoot.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern _ConnectionPtr cnn;
/////////////////////////////////////////////////////////////////////////////
// CAddRoot dialog


CAddRoot::CAddRoot(CWnd* pParent /*=NULL*/)
	: CDialog(CAddRoot::IDD, pParent)
{
	//{{AFX_DATA_INIT(CAddRoot)
	m_StaItem = _T("");
	//}}AFX_DATA_INIT
}


void CAddRoot::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CAddRoot)
	DDX_Control(pDX, IDC_COMConnection, m_ComConnection);
	DDX_Control(pDX, IDC_BUTSure, m_ButSure);
	DDX_Control(pDX, IDC_EDTName, m_EdtName);
	DDX_Control(pDX, IDC_COMStyle, m_ComStyle);
	DDX_Text(pDX, IDC_STAItem, m_StaItem);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CAddRoot, CDialog)
	//{{AFX_MSG_MAP(CAddRoot)
	ON_BN_CLICKED(IDC_BUTEXIT, OnButexit)
	ON_BN_CLICKED(IDC_BUTSure, OnBUTSure)
	ON_WM_CLOSE()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAddRoot message handlers

void CAddRoot::OnOK() 
{
	// TODO: Add extra validation here
	
	//CDialog::OnOK();
}

BOOL CAddRoot::OnInitDialog() 
{
	CString sSQL;
	CDialog::OnInitDialog();
	if(this->m_StaItem=="中华人民共和国")
	{
		m_ComConnection.SetCurSel(0);
		m_ComConnection.EnableWindow(false);
	}
	else
	{
		int nStyle=this->RootStyle(this->Root,"类型");
		if(nStyle==0)
		{
			MessageBox("读取相关数据资料失败！","系统提示",MB_OK|MB_ICONSTOP);
			this->OnCancel();
		}
		else
		{
			if(nStyle==3)
			{
				m_ComConnection.SetCurSel(1);
				m_ComConnection.EnableWindow(false);
			}
			else
			{
				m_ComConnection.SetCurSel(0);
			}
		}

	}
	// TODO: Add extra initialization here
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

 int CAddRoot::RootStyle(HTREEITEM Root,CString FieldName)
 {
	_RecordsetPtr rst;
 	CString sRootName,sSQL;
 	rst.CreateInstance(__uuidof(Recordset));
 	sRootName=m_tree->GetItemText(Root);
 	sSQL.Format("SELECT * from 地域信息表 WHERE 名称='%s'",sRootName);
	try{
 		rst=cnn->Execute((_bstr_t)sSQL,NULL,adCmdText);
	}
	catch(...)
 	{
 		m_function.ADOError(rst);
 		rst->Close();
 		return 0;
 	}
 	if(m_function.RecordCount(rst)<=0)
 	{
 		rst->Close();
 		return 0;
 	}
 	else
	{
 		rst->MoveFirst();
		CString RootStyle=(char*)(_bstr_t)rst->GetCollect((_bstr_t)FieldName);
 		rst->Close();
 		return atoi(RootStyle);
 	}
 }

void CAddRoot::OnButexit() 
{
	this->Rady=false;
	this->OnCancel();	
}

BOOL CAddRoot::PreTranslateMessage(MSG* pMsg) 
{
	m_function.CMessage(this,pMsg,&m_ComConnection,&m_EdtName);
	m_function.CMessage(this,pMsg,&m_EdtName,&m_ComStyle);
	m_function.CMessage(this,pMsg,&m_ComStyle,&m_ButSure);
	return CDialog::PreTranslateMessage(pMsg);
}

void CAddRoot::OnBUTSure() 
{
	CString Text;
	m_ComStyle.GetWindowText(Text);
	if(Text=="省")
		this->Style=1;
	if(Text=="市")
		this->Style=2;
	if(Text=="区")
		this->Style=3;
	this->m_EdtName.GetWindowText(this->EdtNameText);
	this->Connection=this->m_ComConnection.GetCurSel();
	int a=MessageBox("确定添加节点吗？","系统提示",MB_OKCANCEL|MB_ICONQUESTION);
	if(a==1)
		this->Rady=true;
	else
		this->Rady=false;
	this->OnCancel();
}


void CAddRoot::OnClose() 
{
	this->Rady=false;	
	CDialog::OnClose();
}
