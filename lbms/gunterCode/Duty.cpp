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
	DutyRst=cnn->Execute((_bstr_t)"�ͻ�����",NULL,adCmdTable);
	if(function.RecordCount(DutyRst)>0)
	{
		m_ComDuty.record=DutyRst;
		m_ComDuty.DateBaseName="�ͻ�����";
		m_ComDuty.IDStyle=1;
		m_ComDuty.Init("����");
	}
	DutyRst->Close();
	rst.CreateInstance(__uuidof(Recordset));
	rst=cnn->Execute((_bstr_t)"�ͻ�ְ���ѯ",NULL,adCmdTable);
	if(function.RecordCount(rst)>0)
	{
		m_List.record=rst;
		m_List.DateBaseName="�ͻ�ְ���ѯ";
		m_List.Init("����");
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
	sSQL.Format("SELECT * FROM �ͻ�ְ���ѯ WHERE ���=%d",this->m_List.Recno);
	DisplayRst=cnn->Execute((_bstr_t)sSQL,NULL,adCmdText);
	if(function.RecordCount(DisplayRst)>0)
	{
		DisplayRst->MoveFirst();
		ID=(char*)(_bstr_t)DisplayRst->GetCollect("���");
		Name=(char*)(_bstr_t)DisplayRst->GetCollect("����");
		LetterName=(char*)(_bstr_t)DisplayRst->GetCollect("���");
		Duty=(char*)(_bstr_t)DisplayRst->GetCollect("�ͻ����");
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
     		 MessageBox("ID="+this->m_List.Recno,"ϵͳ��ʾ",MB_OK|MB_ICONSTOP);
	DisplayRst=cnn->Execute((_bstr_t)sSQL,NULL,adCmdText);
	if(function.RecordCount(DisplayRst)>0)
	{
		DisplayRst->MoveFirst();
		//ID=(char*)(_bstr_t)DisplayRst->GetCollect("���");
         //Categroy=(char*)(_bstr_t)DisplayRst->GetCollect("���");
         //MaxOutNum=(char*)(_bstr_t)DisplayRst->GetCollect("�����");
         //CanOutMonths=(char*)(_bstr_t)DisplayRst->GetCollect("�����");

		 ID=(char*)(_bstr_t)DisplayRst->GetCollect("ID");
         Categroy=(char*)(_bstr_t)DisplayRst->GetCollect("Categroy");
         MaxOutNum=(char*)(_bstr_t)DisplayRst->GetCollect("MaxOutNum");
         CanOutMonths=(char*)(_bstr_t)DisplayRst->GetCollect("CanOutMonths");
		//Name=(char*)(_bstr_t)DisplayRst->GetCollect("����");
		//LetterName=(char*)(_bstr_t)DisplayRst->GetCollect("���");
		//Duty=(char*)(_bstr_t)DisplayRst->GetCollect("�ͻ����");
		//m_StaID.SetWindowText(ID);
		//m_EdtName.SetWindowText(Name);
		//m_EdtLetterName.SetWindowText(LetterName);
		//m_ComDuty.SetWindowText(Duty);
		 MessageBox("�뽫�ֶ���д������ID","ϵͳ��ʾ",MB_OK|MB_ICONSTOP);
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
		int a=MessageBox("ȷ��Ҫɾ��������¼��","ϵͳ��ʾ",MB_OKCANCEL|MB_ICONQUESTION);
		if (a==1)
		{
			CString sSQL;
			sSQL.Format("DELETE FROM �ͻ�ְ��� WHERE ���=%s",ID);
			cnn->Execute((_bstr_t)sSQL,NULL,adCmdText);
			this->Enabled(true);
			m_List.ResetContent();
			m_List.Init("����");
			this->Enabled(true);
			m_List.SetFocus();
			this->m_List.SetCurSel(0);
			this->ClearFrom();
		}
	}
	else
	{
		MessageBox("��ѡ��һ����¼��","ϵͳ��ʾ",MB_OK|MB_ICONSTOP);
	}
     */
	//my
	CString ID,sSQL;
	this->m_StaID.GetWindowText(ID);
	if(ID.IsEmpty()==false)
	{
		int a=MessageBox("ȷ��Ҫɾ��������¼��","ϵͳ��ʾ",MB_OKCANCEL|MB_ICONQUESTION);
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
		MessageBox("��ѡ��һ����¼��","ϵͳ��ʾ",MB_OK|MB_ICONSTOP);
	}

}

void CDuty::OnBUTSave() 
{
	int a=MessageBox("ȷ�������¼��?","ϵͳ��ʾ",MB_ICONQUESTION|MB_OKCANCEL);
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
			if(this->AddorChange==true)// ���ִ����Ӳ���	
				sSQL.Format("Insert Into �ͻ�ְ��� values (%s,'%s','%s',%d)",ID,Name,LetterName,m_ComDuty.Recno);
			else
				sSQL.Format("UPDATE �ͻ�ְ��� SET ����='%s',���='%s',�ͻ����=%d WHERE ���=%s",Name,LetterName,m_ComDuty.Recno,ID);
			try{
			myrst=cnn->Execute((_bstr_t)sSQL,NULL,adCmdText);
			}
			catch(...)
			{
				function.ADOError(myrst);
				return;
			}
			m_List.ResetContent();
			m_List.Init("����");
			this->Enabled(true);
			m_List.SetFocus();
		}
		else	
		{
			MessageBox("�뽫�ֶ���д������","ϵͳ��ʾ",MB_OK|MB_ICONSTOP);
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
	MessageBox("���ģ�","ϵͳ��ʾ",MB_OK|MB_ICONSTOP);
}
