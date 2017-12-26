// 源程序.cpp ：为应用程序定义class 的行为
// 全局说明  针对整个应用程序而言 

#include "stdafx.h"
#include "gunterLBMS.h"
#include "initguid.h"
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
		//主意-这个ClassWizard 将在这儿添加和移除映射宏
		//    DO NOT EDIT what you see in these blocks of generated code!
		//    不要编辑你看到的自己生成的这些模块代码！
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyApp construction

CMyApp::CMyApp()
{
	//TODO:在这添加 构造代码
	//放置所有重要初始化实例的实例化
}

/////////////////////////////////////////////////////////////////////////////
//有且仅有的一个 CMyApp 对象
CMyApp theApp;
_ConnectionPtr cnn;
/////////////////////////////////////////////////////////////////////////////
// CMyApp 实例化

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
	//Enable3dControls();		  // 当在共享的DLL中使用MFC时调用
#else
	Enable3dControlsStatic();	//当静态连接到MFC时调用
#endif

	CDlogin dlg;
	//下面注释的2种方法等效
	//m_pMainWnd = &dlg;
	//AfxGetApp()->m_pMainWnd=&dlg;
	AfxGetApp()->m_pMainWnd=&dlg;
	int nResponse = dlg.DoModal();       //显示窗体

	if (nResponse == IDOK)
	{
		//当程序窗体离开(解体)时用来操作的代码（点击Ok按钮以便退出时）
	}
	else if (nResponse == IDCANCEL)
	{
		//当应用程序窗体离开/失去(解体)时用来操作的代码（点击关闭按钮后弹出对话框后又选择取消按钮以便不退出应用程序时）
	}
	//  当应用程序对话框已经关闭后，还回flase所以我们退出当前这个应用程序，
	//	而不是重新启动这个应用程序的信息池/泵
	return false;
}
