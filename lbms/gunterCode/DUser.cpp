// DUser.cpp : implementation file
//

#include "stdafx.h"
#include "gunterLBMS.h"
#include "DUser.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern _ConnectionPtr cnn;
/////////////////////////////////////////////////////////////////////////////
// CDUser dialog


CDUser::CDUser(CWnd* pParent /*=NULL*/)
	: CDialog(CDUser::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDUser)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDUser::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDUser)
	DDX_Control(pDX, IDC_STAID, m_StaID);
	DDX_Control(pDX, IDC_LIST, m_List);
	DDX_Control(pDX, IDC_EDTPassWard, m_EdtPassWard);
	DDX_Control(pDX, IDC_EDTName, m_EdtName);
	DDX_Control(pDX, IDC_EDTAffarmPassward, m_EdtAffarmPassWard);
	DDX_Control(pDX, IDC_BUTUnDo, m_ButUndo);
	DDX_Control(pDX, IDC_BUTSave, m_ButSave);
	DDX_Control(pDX, IDC_BUTEXIT, m_ButExit);
	DDX_Control(pDX, IDC_BUTDELETE, m_ButDele);
	DDX_Control(pDX, IDC_BUTChange, m_ButChange);
	DDX_Control(pDX, IDC_BUTADD, m_ButAdd);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDUser, CDialog)
	//{{AFX_MSG_MAP(CDUser)
	ON_BN_CLICKED(IDC_BUTADD, OnButadd)
	ON_BN_CLICKED(IDC_BUTChange, OnBUTChange)
	ON_BN_CLICKED(IDC_BUTDELETE, OnButdelete)
	ON_BN_CLICKED(IDC_BUTSave, OnBUTSave)
	ON_LBN_SELCHANGE(IDC_LIST, OnSelchangeList)
	ON_BN_CLICKED(IDC_BUTUnDo, OnBUTUnDo)
	ON_BN_CLICKED(IDC_BUTEXIT, OnButexit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDUser message handlers

void CDUser::OnOK() 
{
	// TODO: Add extra validation here
	
	//CDialog::OnOK();
}


void CDUser::ClearFrom()
{
	this->m_EdtAffarmPassWard.SetWindowText("");
	this->m_EdtName.SetWindowText("");
	this->m_EdtPassWard.SetWindowText("");
}

void CDUser::Display()
{
	_RecordsetPtr DisplayRst;
	DisplayRst.CreateInstance(__uuidof(Recordset));
	CString ID,Name,PassWard,sSQL,text;

	sSQL.Format("select * from users WHERE 编号=%d",m_List.Recno);
	DisplayRst=cnn->Execute((_bstr_t)sSQL,NULL,adCmdText);
	if(function.RecordCount(DisplayRst)>0)
	{
		DisplayRst->MoveFirst();
		ID=(char*)(_bstr_t)DisplayRst->GetCollect("编号");
		Name=(char*)(_bstr_t)DisplayRst->GetCollect("UserID");
		PassWard=(char*)(_bstr_t)DisplayRst->GetCollect("Password");
		m_StaID.SetWindowText(ID);
		m_EdtName.SetWindowText(Name);
		m_EdtPassWard.SetWindowText(PassWard);
	}
	DisplayRst->Close();
}

void CDUser::Enabled(bool enabled)
{
	this->m_ButAdd.EnableWindow(enabled);
	this->m_ButChange.EnableWindow(enabled);
	this->m_ButDele.EnableWindow(enabled);
	this->m_ButExit.EnableWindow(enabled);
	this->m_ButSave.EnableWindow(!enabled);
	this->m_ButUndo.EnableWindow(!enabled);
	this->m_EdtName.EnableWindow(!enabled);
	this->m_EdtAffarmPassWard.EnableWindow(!enabled);
	this->m_EdtPassWard.EnableWindow(!enabled);
	this->m_List.EnableWindow(enabled);
}

BOOL CDUser::OnInitDialog()               //判断是否初始化窗体成功
{
	CDialog::OnInitDialog();

	rst.CreateInstance(__uuidof(Recordset));
	rst=cnn->Execute((_bstr_t)"users",NULL,adCmdTable);
	if(function.RecordCount(rst)>0)
	{
		m_List.record=rst;
		m_List.DateBaseName="users";
		m_List.Init("UserID");
	}	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CDUser::OnButadd()             //点击添加按钮
{
	int NewID;
	CString ID;
	this->Enabled(false);
	this->ClearFrom();
	NewID=function.AutoNumber(0,"users");
	ID.Format("%d",NewID);
	this->m_StaID.SetWindowText(ID);
	this->AddOrChange=true;
	this->m_EdtName.SetFocus();
	
}

void CDUser::OnBUTChange()                //点击修改按钮
{
	this->Enabled(false);
	this->m_EdtName.SetFocus();
	AddOrChange=false;
	
}

void CDUser::OnButdelete()                //根据用户ID删除用户
{
	CString ID,sSQL;
	this->m_StaID.GetWindowText(ID);
	if(ID.IsEmpty()==false)
	{
		int a=MessageBox("确定要删除编号为"+ID+"的记录吗？","系统提示",MB_OKCANCEL|MB_ICONQUESTION);
		if (a==1)
		{
			CString sSQL;
			sSQL.Format("delete from users where 编号=%s",ID);
			cnn->Execute((_bstr_t)sSQL,NULL,adCmdText);
			this->Enabled(true);
			m_List.ResetContent();
			m_List.Init("UserID");
			this->Enabled(true);
			m_List.SetFocus();
			this->m_List.SetCurSel(0);
			this->ClearFrom();
		}
	}
	else
	{
		MessageBox("请选择一条记录！","系统提示",MB_OK|MB_ICONSTOP);
	}	
}

void CDUser::OnBUTSave() 
{
	CString sSQL,ID,UserID,PassWard,NewPassWard;
	_RecordsetPtr myrst;
	myrst.CreateInstance(__uuidof(Recordset));
	m_StaID.GetWindowText(ID);
	m_EdtName.GetWindowText(UserID);
	m_EdtPassWard.GetWindowText(PassWard);
	m_EdtAffarmPassWard.GetWindowText(NewPassWard);
	if(PassWard!=NewPassWard)
	{
		MessageBox("两次输入的密码不一致！","系统提示",MB_OK|MB_ICONSTOP);
		m_EdtAffarmPassWard.SetWindowText("");
		m_EdtAffarmPassWard.SetFocus();
		return;
	}
	int a=MessageBox("确定保存记录吗?","系统提示",MB_ICONQUESTION|MB_OKCANCEL);
	if(a==1)
	{
		if( UserID.IsEmpty()==false && PassWard.IsEmpty()==false)
		{
			if(this->AddOrChange==true)// 如果执行添加操作	
			{
				sSQL.Format("Insert Into users(UserID,Password) values ('%s','%s')",UserID,PassWard);
				MessageBox("添加成功！","系统提示",MB_OK|MB_ICONSTOP);
			}
			else
			{
				sSQL.Format("update users SET UserID='%s',Password='%s' WHERE 编号=%s",UserID,PassWard,ID);  //成功
				MessageBox("修改成功！","系统提示",MB_OK|MB_ICONSTOP);
			}
			try{
			myrst=cnn->Execute((_bstr_t)sSQL,NULL,adCmdText);
			}
			catch(...)
			{
				function.ADOError(myrst);
				return;
			}
			m_List.ResetContent();
			m_List.Init("UserID");
			this->Enabled(true);
			m_List.SetFocus();

		}
		else
		{
			MessageBox("请将字段填写完整！","系统提示",MB_OK|MB_ICONSTOP);
			this->m_EdtName.SetFocus();
			return;
		}
	}
}

void CDUser::OnSelchangeList()  //选择项更改了，调用显示Display()函数
{
	//if(this->m_List.GetCurSel()==-1)
	//	return;

	this->Display();
	
}

void CDUser::OnBUTUnDo()   //撤销
{
	this->Enabled(true);	
	
}

void CDUser::OnButexit() //退出
{
	this->OnCancel();	
}
