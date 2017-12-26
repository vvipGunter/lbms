// Dlogin.cpp : implementation file
//

#include "stdafx.h"
#include "gunterLBMS.h"
#include "Dlogin.h"
#include "Main.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern _ConnectionPtr cnn;
/////////////////////////////////////////////////////////////////////////////
// CDlogin dialog


CDlogin::CDlogin(CWnd* pParent /*=NULL*/)
	: CDialog(CDlogin::IDD, pParent)
{
	//{{AFX_DATA_INIT(CDlogin)
		// NOTE: the ClassWizard will add member initialization here
	//}}AFX_DATA_INIT
}


void CDlogin::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CDlogin)
	DDX_Control(pDX, IDC_EDTPassWard, m_EdtPassWard);
	DDX_Control(pDX, IDC_COMName, m_ComName);
	DDX_Control(pDX, IDC_BUTLogin, m_ButLogin);
	DDX_Control(pDX, IDC_BUTEXIT, m_ButExit);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CDlogin, CDialog)
	//{{AFX_MSG_MAP(CDlogin)
	ON_BN_CLICKED(IDC_BUTLogin, OnBUTLogin)
	ON_BN_CLICKED(IDC_BUTEXIT, OnButexit)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDlogin message handlers

void CDlogin::OnOK() 
{
	// TODO: Add extra validation here
	//CDialog::OnOK();

	//TODO:在这添加额外的确认
}

BOOL CDlogin::OnInitDialog() 
{
		///-----------------------gunter add（next）表示紧跟的下面几句是我自己加de----------
    CDialog::OnInitDialog();
	rst.CreateInstance(__uuidof(Record));
	rst=cnn->Execute((_bstr_t)"users",NULL,adCmdTable);
	if(function.RecordCount(rst)>0)
	{
		m_ComName.record=rst;
		m_ComName.DateBaseName="users";
		m_ComName.IDStyle=1;
		m_ComName.Init("UserID");
	
	}
	else
	{
		m_ComName.EnableWindow(false);
		m_EdtPassWard.EnableWindow(false);
		MessageBox("感谢您初次使用客户管理系统！请在进入程序主界面后添加一新用户！","系统提示",MB_OK|MB_ICONQUESTION);
		this->OnCancel();
		                //显示主窗体
		CMain dlg;
		dlg.DoModal();
	}
	this->Time=1;
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
	///-----------------------gunter add（next）表示紧跟的下面几句是我自己加de----------
}

void CDlogin::OnBUTLogin() 
{
	CString sSQL,InputPassWard,cName;
	_RecordsetPtr LRst;
	m_EdtPassWard.GetWindowText(InputPassWard);
	if(Time>=3)
	{
		MessageBox("对不起！您不能登录本系统，请与管理员联系!","系统提示",MB_OK|MB_ICONSTOP);
		this->OnCancel();
		return;
	}
	sSQL.Format("SELECT * From  users WHERE 编号=%d",m_ComName.Recno);
   ///-----------------------gunter add（next）表示紧跟的下面几句是我自己加de----------
	LRst=cnn->Execute((_bstr_t)sSQL,NULL,adCmdText);
	if(function.RecordCount(LRst)>0)
	{
		LRst->MoveFirst();
		//CString PassWard=(char*)(_bstr_t)LRst->GetCollect("密码");
		 ///-----------------------gunter add（next）表示紧跟的下面几句是我自己加de----------
         CString PassWard=(char*)(_bstr_t)LRst->GetCollect("Password");
        ///-----------------------gunter add（next）表示紧跟的下面几句是我自己加de----------
		if(PassWard==InputPassWard)
		{
			CMain dlg;
			this->OnCancel();
			CString UserName;
			m_ComName.GetWindowText(UserName);
			
			dlg.User=UserName;                        //获取用户名，作为登陆的UserID
			dlg.DoModal();
		}
		else
		{
			MessageBox("您输入的密码不正确！请重试！","系统提示",MB_OK|MB_ICONSTOP);
		
			this->m_EdtPassWard.SetWindowText("");
			this->m_EdtPassWard.SetFocus();
			this->Time=this->Time+1;
		}
	}
	else
	{
		MessageBox("您输入的用户不存在！","系统提示",MB_OK|MB_ICONSTOP);
		this->Time=this->Time+1;
	}
	LRst->Close();
}

void CDlogin::OnButexit() 
{
	this->OnCancel();	
}
