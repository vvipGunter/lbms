// Դ����.cpp ��ΪӦ�ó�����class ����Ϊ
// ȫ��˵��  �������Ӧ�ó������ 

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
		//����-���ClassWizard ���������Ӻ��Ƴ�ӳ���
		//    DO NOT EDIT what you see in these blocks of generated code!
		//    ��Ҫ�༭�㿴�����Լ����ɵ���Щģ����룡
	//}}AFX_MSG
	ON_COMMAND(ID_HELP, CWinApp::OnHelp)
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMyApp construction

CMyApp::CMyApp()
{
	//TODO:������� �������
	//����������Ҫ��ʼ��ʵ����ʵ����
}

/////////////////////////////////////////////////////////////////////////////
//���ҽ��е�һ�� CMyApp ����
CMyApp theApp;
_ConnectionPtr cnn;
/////////////////////////////////////////////////////////////////////////////
// CMyApp ʵ����

BOOL CMyApp::InitInstance()
{


	AfxEnableControlContainer();
	//��ʼ��Connection����
	::CoInitialize(NULL);
	cnn.CreateInstance(__uuidof(Connection));
	//cnn->ConnectionString="uid=admin;pwd=111;DRIVER={Microsoft Access Driver (*.mdb)};DBQ=khzy.mdb;"; //����ACCESS���ݿ�  ok
                                   //����sql server ���ݿ�
	//cnn->ConnectionString="Provider=SQLOLEDB.1;Persist Security Info=False;User ID=sa;Initial Catalog=gunterBook;Data Source=.;pwd=sa1234;";  // ok
 	cnn->ConnectionString="DRIVER=SQL Server;Persist Security Info=False;User ID=sa;Initial Catalog=gunterBook;Server=.;PWD=sa1234;";       //ok
	cnn->Open(L"",L"",L"",adConnectUnspecified);


#ifdef _AFXDLL
	//Enable3dControls();		  // ���ڹ����DLL��ʹ��MFCʱ����
#else
	Enable3dControlsStatic();	//����̬���ӵ�MFCʱ����
#endif

	CDlogin dlg;
	//����ע�͵�2�ַ�����Ч
	//m_pMainWnd = &dlg;
	//AfxGetApp()->m_pMainWnd=&dlg;
	AfxGetApp()->m_pMainWnd=&dlg;
	int nResponse = dlg.DoModal();       //��ʾ����

	if (nResponse == IDOK)
	{
		//���������뿪(����)ʱ���������Ĵ��루���Ok��ť�Ա��˳�ʱ��
	}
	else if (nResponse == IDCANCEL)
	{
		//��Ӧ�ó������뿪/ʧȥ(����)ʱ���������Ĵ��루����رհ�ť�󵯳��Ի������ѡ��ȡ����ť�Ա㲻�˳�Ӧ�ó���ʱ��
	}
	//  ��Ӧ�ó���Ի����Ѿ��رպ󣬻���flase���������˳���ǰ���Ӧ�ó���
	//	�����������������Ӧ�ó������Ϣ��/��
	return false;
}
