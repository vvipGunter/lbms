// 源程序.cpp : Defines the class behaviors for the application.
//

#include "stdafx.h"
#include "gunterLBMS.h"
#include <initguid.h>
#include "gunterLBMS_i.c"
#include "Dlogin.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CMyApp

BEGIN_MESSAGE_MAP(CMyApp, CWinApp)
	//{{AFX_MSG_MAP(CMyApp)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//    DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyApp construction

CMyApp::CMyApp()
{
	// TODO: add construction code here,
	// Place all significant initialization in InitInstance
}

/////////////////////////////////////////////////////////////////////////////
// The one and only CMyApp object

CMyApp theApp;
_ConnectionPtr cnn;
/////////////////////////////////////////////////////////////////////////////
// CMyApp initialization

BOOL CMyApp::InitInstance()
{


	AfxEnableControlContainer();
	//初始化Connection对象
	::CoInitialize(NULL);
	cnn.CreateInstance(__uuidof(Connection));
	//cnn->ConnectionString="uid=admin;pwd=111;DRIVER={Microsoft Access Driver (*.mdb)};DBQ=khzy.mdb;"; //连接ACCESS数据库  ok
                       //连接sql server 数据库
	//cnn->ConnectionString="Provider=SQLOLEDB.1;Persist Security Info=False;User ID=sa;Initial Catalog=gunterBook;Data Source=.;pwd=sa1234;";  // ok
 	cnn->ConnectionString="DRIVER=SQL Server;Persist Security Info=False;User ID=sa;Initial Catalog=gunterBook;Server=.;PWD=sa1234;";       //ok
	cnn->Open(L"",L"",L"",adConnectUnspecified);


#ifdef _AFXDLL
	//Enable3dControls();			// Call this when using MFC in a shared DLL
#else
	Enable3dControlsStatic();	// Call this when linking to MFC statically
#endif

	CDlogin dlg;
	m_pMainWnd = &dlg;
	int nResponse = dlg.DoModal();

	if (nResponse == IDOK)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with OK
	}
	else if (nResponse == IDCANCEL)
	{
		// TODO: Place code here to handle when the dialog is
		//  dismissed with Cancel
	}
	// Since the dialog has been closed, return FALSE so that we exit the
	//  application, rather than start the application's message pump.
	return FALSE;
}
