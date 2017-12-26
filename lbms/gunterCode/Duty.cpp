// Duty.cpp : implementation file
//

#include "stdafx.h"
#include "gunterLBMS.h"
#include "Duty.h"
#include "RainFunction.h"
#include "DBSlider.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern _ConnectionPtr cnn;
/////////////////////////////////////////////////////////////////////////////
// CDuty dialog


CDuty::CDuty(CWnd* pParent /*=NULL*/)
	: CDialog(CDuty::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDuty)
	//}}AFX_DATA_INIT
}


void CDuty::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDuty)
	DDX_Control(pDX, IDC_BUTUnDo, m_ButUndo);
	DDX_Control(pDX, IDC_BUTSave, m_ButSave);
	DDX_Control(pDX, IDC_BUTEXIT, m_ButExit);
	DDX_Control(pDX, IDC_BUTDELETE, m_ButDelete);
	DDX_Control(pDX, IDC_BUTChange, m_ButChange);
	DDX_Control(pDX, IDC_BUTADD, m_ButAdd);
	DDX_Control(pDX, IDC_ComDuty, m_ComDuty);
	DDX_Control(pDX, IDC_EDTLetterName, m_EdtLetterName);
	DDX_Control(pDX, IDC_EDTName, m_EdtName);
	DDX_Control(pDX, IDC_STAID, m_StaID);
	DDX_Control(pDX, IDC_LIST2, m_List);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDuty, CDialog)
	//{{AFX_MSG_MAP(CDuty)
	ON_BN_CLICKED(IDC_BUTEXIT, OnButexit)
	ON_BN_CLICKED(IDC_BUTADD, OnButadd)
	ON_BN_CLICKED(IDC_BUTChange, OnBUTChange)
	ON_BN_CLICKED(IDC_BUTDELETE, OnButdelete)
	ON_BN_CLICKED(IDC_BUTSave, OnBUTSave)
	ON_BN_CLICKED(IDC_BUTUnDo, OnBUTUnDo)
	ON_EN_CHANGE(IDC_EDTName, OnChangeEDTName)
	ON_LBN_SELCHANGE(IDC_LIST2, OnSelchangeList2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDuty message handlers

BOOL CDuty::OnInitDialog() 
{
	/*
	CDialog::OnInitDialog();
	_RecordsetPtr DutyRst;
	DutyRst.CreateInstance(__uuidof(Recordset));
	DutyRst=cnn->Execute((_bstr_t)"客户类别表",NULL,adCmdTable);
	if(function.RecordCount(DutyRst)>0)
	{
		m_ComDuty.record=DutyRst;
		m_ComDuty.DateBaseName="客户类别表";
		m_ComDuty.IDStyle=1;
		m_ComDuty.Init("名称");
	}
	DutyRst->Close();
	rst.CreateInstance(__uuidof(Recordset));
	rst=cnn->Execute((_bstr_t)"客户职务查询",NULL,adCmdTable);
	if(function.RecordCount(rst)>0)
	{
		m_List.record=rst;
		m_List.DateBaseName="客户职务查询";
		m_List.Init("名称");
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
				  */
		CDialog::OnInitDialog();
	/*_RecordsetPtr DutyRst;
	DutyRst.CreateInstance(__uuidof(Recordset));
	DutyRst=cnn->Execute((_bstr_t)"usersrights",NULL,adCmdTable);
	if(function.RecordCount(DutyRst)>0)
	{
		m_ComDuty.record=DutyRst;
		m_ComDuty.DateBaseName="usersrights";
		//m_ComDuty.IDStyle=1;
		m_ComDuty.Init("ID");
	}
	DutyRst->Close();*/
	rst.CreateInstance(__uuidof(Recordset));
	rst=cnn->Execute((_bstr_t)"usersrights",NULL,adCmdTable);
	if(function.RecordCount(rst)>0)
	{
		m_List.record=rst;
		m_List.DateBaseName="usersrights";
		m_List.Init("ID");
	}
	
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE

}

void CDuty::OnOK() 
{
	// TODO: Add extra validation here
	
	//CDialog::OnOK();
}

void CDuty::Display()
{
	/*
	_RecordsetPtr DisplayRst;
	DisplayRst.CreateInstance(__uuidof(Recordset));
	CString ID,Name,LetterName,Duty,sSQL;
	sSQL.Format("SELECT * FROM 客户职务查询 WHERE 编号=%d",this->m_List.Recno);
	DisplayRst=cnn->Execute((_bstr_t)sSQL,NULL,adCmdText);
	if(function.RecordCount(DisplayRst)>0)
	{
		DisplayRst->MoveFirst();
		ID=(char*)(_bstr_t)DisplayRst->GetCollect("编号");
		Name=(char*)(_bstr_t)DisplayRst->GetCollect("名称");
		LetterName=(char*)(_bstr_t)DisplayRst->GetCollect("简称");
		Duty=(char*)(_bstr_t)DisplayRst->GetCollect("客户类别");
		m_StaID.SetWindowText(ID);
		m_EdtName.SetWindowText(Name);
		m_EdtLetterName.SetWindowText(LetterName);
		m_ComDuty.SetWindowText(Duty);
	}
	DisplayRst->Close();
	*/
	_RecordsetPtr DisplayRst;
	DisplayRst.CreateInstance(__uuidof(Recordset));
	//CString ID,Name,LetterName,Duty,sSQL;
    CString ID,Categroy,MaxOutNum,CanOutMonths,sSQL;
	sSQL.Format("select * from usersrights where ID=%d",this->m_List.Recno);
     		 MessageBox("ID="+this->m_List.Recno,"系统提示",MB_OK|MB_ICONSTOP);
	DisplayRst=cnn->Execute((_bstr_t)sSQL,NULL,adCmdText);
	if(function.RecordCount(DisplayRst)>0)
	{
		DisplayRst->MoveFirst();
		//ID=(char*)(_bstr_t)DisplayRst->GetCollect("编号");
         //Categroy=(char*)(_bstr_t)DisplayRst->GetCollect("类别");
         //MaxOutNum=(char*)(_bstr_t)DisplayRst->GetCollect("最多借出");
         //CanOutMonths=(char*)(_bstr_t)DisplayRst->GetCollect("最长月数");

		 ID=(char*)(_bstr_t)DisplayRst->GetCollect("ID");
         Categroy=(char*)(_bstr_t)DisplayRst->GetCollect("Categroy");
         MaxOutNum=(char*)(_bstr_t)DisplayRst->GetCollect("MaxOutNum");
         CanOutMonths=(char*)(_bstr_t)DisplayRst->GetCollect("CanOutMonths");
		//Name=(char*)(_bstr_t)DisplayRst->GetCollect("名称");
		//LetterName=(char*)(_bstr_t)DisplayRst->GetCollect("简称");
		//Duty=(char*)(_bstr_t)DisplayRst->GetCollect("客户类别");
		//m_StaID.SetWindowText(ID);
		//m_EdtName.SetWindowText(Name);
		//m_EdtLetterName.SetWindowText(LetterName);
		//m_ComDuty.SetWindowText(Duty);
		 MessageBox("请将字段填写完整！ID","系统提示",MB_OK|MB_ICONSTOP);
		 m_StaID.SetWindowText(ID);
		 m_EdtName.SetWindowText(Categroy);
		 m_EdtLetterName.SetWindowText(MaxOutNum);
         m_ComDuty.SetWindowText(CanOutMonths);
	}
	DisplayRst->Close();
}



void CDuty::OnButexit() 
{
	this->OnCancel();
}

void CDuty::OnButadd() 
{
    int NewID;
	CString ID;
	this->Enabled(false);
	this->ClearFrom();
	NewID=function.AutoNumber(0,"usersrights");
	ID.Format("%d",NewID);
	this->m_StaID.SetWindowText(ID);
	this->AddorChange=true;
	this->m_EdtName.SetFocus();
}

void CDuty::Enabled(bool enabled)
{
	this->m_ButAdd.EnableWindow(enabled);
	this->m_ButChange.EnableWindow(enabled);
	this->m_ButDelete.EnableWindow(enabled);
	this->m_ButExit.EnableWindow(enabled);
	this->m_ButSave.EnableWindow(!enabled);
	this->m_ButUndo.EnableWindow(!enabled);
	this->m_ComDuty.EnableWindow(!enabled);
	this->m_EdtLetterName.EnableWindow(!enabled);
	this->m_EdtName.EnableWindow(!enabled);
	this->m_List.EnableWindow(enabled);
}

void CDuty::OnBUTChange() 
{
	this->Enabled(false);
	this->m_ComDuty.SetWindowText("");
	this->m_EdtName.SetFocus();
	AddorChange=false;
}

void CDuty::OnButdelete() 
{
	/*
	CString ID,sSQL;
	this->m_StaID.GetWindowText(ID);
	if(ID.IsEmpty()==false)
	{
		int a=MessageBox("确定要删除此条记录吗？","系统提示",MB_OKCANCEL|MB_ICONQUESTION);
		if (a==1)
		{
			CString sSQL;
			sSQL.Format("DELETE FROM 客户职务表 WHERE 编号=%s",ID);
			cnn->Execute((_bstr_t)sSQL,NULL,adCmdText);
			this->Enabled(true);
			m_List.ResetContent();
			m_List.Init("名称");
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
     */
	//my
	CString ID,sSQL;
	this->m_StaID.GetWindowText(ID);
	if(ID.IsEmpty()==false)
	{
		int a=MessageBox("确定要删除此条记录吗？","系统提示",MB_OKCANCEL|MB_ICONQUESTION);
		if (a==1)
		{
			CString sSQL;
			sSQL.Format("DELETE FROM usersrights WHERE ID=%s",ID);
			cnn->Execute((_bstr_t)sSQL,NULL,adCmdText);
			this->Enabled(true);
			m_List.ResetContent();
			m_List.Init("ID");
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

void CDuty::OnBUTSave() 
{
	int a=MessageBox("确定保存记录吗?","系统提示",MB_ICONQUESTION|MB_OKCANCEL);
	if(a==1)
	{
		CString sSQL,ID,Name,LetterName,Duty;
		_RecordsetPtr myrst;
		myrst.CreateInstance(__uuidof(Recordset));
		m_StaID.GetWindowText(ID);
		m_EdtName.GetWindowText(Name);
		m_EdtLetterName.GetWindowText(LetterName);
		m_ComDuty.GetWindowText(Duty);
		if( Name.IsEmpty()==false && LetterName.IsEmpty()==false && Duty.IsEmpty()==false)
		{
			if(this->AddorChange==true)// 如果执行添加操作	
				sSQL.Format("Insert Into 客户职务表 values (%s,'%s','%s',%d)",ID,Name,LetterName,m_ComDuty.Recno);
			else
				sSQL.Format("UPDATE 客户职务表 SET 名称='%s',简称='%s',客户类别=%d WHERE 编号=%s",Name,LetterName,m_ComDuty.Recno,ID);
			try{
			myrst=cnn->Execute((_bstr_t)sSQL,NULL,adCmdText);
			}
			catch(...)
			{
				function.ADOError(myrst);
				return;
			}
			m_List.ResetContent();
			m_List.Init("名称");
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

void CDuty::OnBUTUnDo() 
{
	this->Enabled(true);	
}

void CDuty::ClearFrom()
{
	this->m_EdtLetterName.SetWindowText("");
	this->m_EdtName.SetWindowText("");
	this->m_ComDuty.SetWindowText("");
}

BOOL CDuty::PreTranslateMessage(MSG* pMsg) 
{
	function.CMessage(this,pMsg,&m_EdtName,&m_EdtLetterName);
	function.CMessage(this,pMsg,&m_EdtLetterName,&m_ComDuty);
	function.CMessage(this,pMsg,&m_ComDuty,&m_ButSave);	
	return CDialog::PreTranslateMessage(pMsg);
}

void CDuty::OnChangeEDTName() 
{
	CString LetterName,Name;
	m_EdtName.GetWindowText(Name);
	LetterName=function.CharToLetterCode(Name);
	m_EdtLetterName.SetWindowText(LetterName);	
}


void CDuty::OnSelchangeList2() 
{
	this->Display();
	MessageBox("更改！","系统提示",MB_OK|MB_ICONSTOP);
}
