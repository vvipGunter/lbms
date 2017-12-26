// usersrights.cpp : implementation file
//

#include "stdafx.h"
#include "gunterLBMS.h"
#include "usersrights.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern _ConnectionPtr cnn;
/////////////////////////////////////////////////////////////////////////////
// Cusersrights dialog


Cusersrights::Cusersrights(CWnd* pParent /*=NULL*/)
	: CDialog(Cusersrights::IDD, pParent)
{
	//{{AFX_DATA_INIT(Cusersrights)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}

BOOL Cusersrights::OnInitDialog() 
{
	//added 
	CDialog::OnInitDialog();

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

void Cusersrights::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(Cusersrights)
		// NOTE: the ClassWizard will add DDX and DDV calls here
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(Cusersrights, CDialog)
	//{{AFX_MSG_MAP(Cusersrights)
	ON_BN_CLICKED(IDC_BUTEXIT, OnButexit2)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// Cusersrights message handlers

void Cusersrights::OnButexit2() 
{
	// TODO: Add your control notification handler code here
	this->OnCancel();	
}
void Cusersrights::Display()
{
	_RecordsetPtr DisplayRst;
	DisplayRst.CreateInstance(__uuidof(Recordset));
	//CString ID,Name,LetterName,Duty,sSQL;
    CString strID,strCategroy,strMaxOutNum,strCanOutMonths,sSQL;
	sSQL.Format("SELECT * FROM usersrights WHERE ID=%d",this->m_List.Recno);
	DisplayRst=cnn->Execute((_bstr_t)sSQL,NULL,adCmdText);
	if(function.RecordCount(DisplayRst)>0)
	{
		DisplayRst->MoveFirst();
		//ID=(char*)(_bstr_t)DisplayRst->GetCollect("���");
         //Categroy=(char*)(_bstr_t)DisplayRst->GetCollect("���");
         //MaxOutNum=(char*)(_bstr_t)DisplayRst->GetCollect("�����");
         //CanOutMonths=(char*)(_bstr_t)DisplayRst->GetCollect("�����");

		 strID=(char*)(_bstr_t)DisplayRst->GetCollect("ID");
         strCategroy=(char*)(_bstr_t)DisplayRst->GetCollect("Categroy");
         strMaxOutNum=(char*)(_bstr_t)DisplayRst->GetCollect("MaxOutNum");
         strCanOutMonths=(char*)(_bstr_t)DisplayRst->GetCollect("CanOutMonths");
		//Name=(char*)(_bstr_t)DisplayRst->GetCollect("����");
		//LetterName=(char*)(_bstr_t)DisplayRst->GetCollect("���");
		//Duty=(char*)(_bstr_t)DisplayRst->GetCollect("�ͻ����");
		//m_StaID.SetWindowText(ID);
		//m_EdtName.SetWindowText(Name);
		//m_EdtLetterName.SetWindowText(LetterName);
		//m_ComDuty.SetWindowText(Duty);
		    //MessageBox("�뽫�ֶ���д������ID","ϵͳ��ʾ",MB_OK|MB_ICONSTOP);
		 /*
		 m_StaID.SetWindowText(ID);
		 m_EdtName.SetWindowText(Categroy);
		 m_EdtLetterName.SetWindowText(MaxOutNum);
         m_ComDuty.SetWindowText(CanOutMonths);
		 */
	}
	DisplayRst->Close();
}
