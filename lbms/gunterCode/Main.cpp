// Main.cpp : implementation file
// Main.cpp ��ִ���ļ�

//

//�������Ի��� ������ �������и��ֹ��ܵĲ˵�����
#include "stdafx.h"
#include "gunterLBMS.h"
#include "Main.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
#include "ClientStyle.h"
#include "Duty.h"
#include "DUser.h"


//�����ļ�  added
#include "opbooks.h"
#include "usersrights.h"
#include "outin.h"
//��ȡ��ǰ��ʱ��
#include "string.h"
#include"time.h"
/////////////////////////////////////////////////////////////////////////////
// CMain dialog


CMain::CMain(CWnd* pParent /*=NULL*/)
	: CDialog(CMain::IDD, pParent)
{
	//{{AFX_DATA_INIT(CMain)
	//}}AFX_DATA_INIT
}


void CMain::DoDataExchange(CDataExchange* pDX)
{
	CDialog::DoDataExchange(pDX);
	//{{AFX_DATA_MAP(CMain)
	DDX_Control(pDX, IDC_ButOP, m_ButOp);
	DDX_Control(pDX, IDC_ButUnit, m_ButUnit);
	DDX_Control(pDX, IDC_ButSort, m_ButSort);
	DDX_Control(pDX, IDC_ButMessage, m_ButMessage);
	DDX_Control(pDX, IDC_ButDuty, m_ButDuty);
	DDX_Control(pDX, IDC_ButCG, m_ButCG);
	DDX_Control(pDX, IDC_ButClime, m_ButClime);
	//}}AFX_DATA_MAP
}


BEGIN_MESSAGE_MAP(CMain, CDialog)
	//{{AFX_MSG_MAP(CMain)
	ON_BN_CLICKED(IDC_ButClime, OnButClime)
	ON_BN_CLICKED(IDC_ButUnit, OnButUnit)
	ON_BN_CLICKED(IDC_ButSort, OnButSort)
	ON_BN_CLICKED(IDC_ButMessage, OnButMessage)
	ON_BN_CLICKED(IDC_ButDuty, OnButDuty)
	ON_BN_CLICKED(IDC_ButCG, OnButCG)
	ON_BN_CLICKED(IDC_BUTADD, OnButadd)
	ON_WM_CTLCOLOR()
	ON_BN_CLICKED(IDC_ButOP, OnButOP)
	ON_WM_PAINT()
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CMain message handlers   CMain ��Ϣ����

BOOL CMain::OnInitDialog()    //��ʼ��CMain����
{
	CDialog::OnInitDialog();
	CRainFunction function;
//	this->m_StaOP.SetWindowText(function.Padl(User,20," ",2));
	this->m_ButClime.Bitmap(IDB_BUT_NOMAL,IDB_BUT_DOWN);
	this->m_ButOp.Bitmap(IDB_BUT_NOMAL,IDB_BUT_DOWN);
	this->m_ButCG.Bitmap(IDB_BUT_NOMAL,IDB_BUT_DOWN);
	this->m_ButDuty.Bitmap(IDB_BUT_NOMAL,IDB_BUT_DOWN);
	this->m_ButMessage.Bitmap(IDB_BUT_NOMAL,IDB_BUT_DOWN);
	this->m_ButSort.Bitmap(IDB_BUT_NOMAL,IDB_BUT_DOWN);
	this->m_ButUnit.Bitmap(IDB_BUT_NOMAL,IDB_BUT_DOWN);


    //CString mynowtime;
    CString successdengluUserID;
    successdengluUserID=this->User;
    MessageBox("��ϲ�������ɹ���"+successdengluUserID+"����ݵ�½��","��½�û���Ϣ",MB_OK|MB_ICONQUESTION); ////��ȡ��½���û�ID
    //mynowtime=this->getNowTime();
    //this->labelTime.SetWindowText(mynowtime);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CMain::OnButClime()    //ϵͳ����  ���� test
{
	//CClime dlg;
   	//dlg.DoModal();
   	//����һ������ʱע�͵�
	/*CDuty c;
	c.DoModal();*/
	
	  CString mynowtime;
      mynowtime=this->getNowTime();
      MessageBox(mynowtime,"��ǰʱ��",MB_OK|MB_ICONSTOP);

   // this->labelTime.SetWindowText(mynowtime);
   /*
	Copbooks copbooks;
	copbooks.DoModal();
	*/
    
    


	/*
   clock_t start=clock();
   clock_t end=clock();
   int a=(end-start)/CLK_TCK;
   int b=start/CLK_TCK;
   */
    
    //mynowtime=this->getNowTime();
   //MessageBox((char *)(_bstr_t)b,"��ǰʱ��",MB_OK|MB_ICONSTOP);
   //MessageBox(mynowtime,"��ǰʱ��",MB_OK|MB_ICONSTOP);
  //this->getNowTime();            //��������ĺ���getNowTime�Ի�ȡ��ǰ��ʱ��
	 //CClientStyle dlg;
     //dlg.DoModal();
}

//gunterADD   //��ȡ��ǰϵͳ��ʱ��
CString CMain::getNowTime()
{
   time_t  nowtime;
   struct tm *local;
  // local=gmtime(&nowtime);        //��ȡ�����׼����
   nowtime=time(NULL);               //��ȡ��ǰϵͳ��ʱ�䣬Ϊlong int��
   local=localtime(&nowtime);    //��ȡ����ʱ��
   CString strNowTime;             //���ƴ�ӳɵ��ַ���
   CString strYear,strMonth,strDay,strHour,strMin,strSec;
   ////��int�͸�ֵ��ת��Ϊstring����
   //strYear=(char *)(_bstr_t)(local->tm_year+1900);
   //strMonth=(char *)(_bstr_t)(local->tm_mon+1);
   //strDay=(char *)(_bstr_t)local->tm_mday;
   //strHour=(char *)(_bstr_t)local->tm_hour;
   //strMin=(char *)(_bstr_t)local->tm_min;
   //strSec=(char *)(_bstr_t)local->tm_sec;
   //�ϳ�Ϊ�����ַ���
  
   strNowTime=strYear+"��"+strMonth+"��"+strDay+"��"+" "+strHour+"ʱ"+strMin+"��"+strSec+"��";
   //MessageBox(strNowTime,"��ǰʱ��",MB_OK|MB_ICONSTOP);
   return strNowTime;
}
 
void CMain::OnButUnit()    //����ͼ�����
{
	//CUnit dlg;
	//dlg.DoModal();	
    Copbooks c;
	c.DoModal();
}

void CMain::OnButSort() 
{
	MessageBox("�Բ�����ʱδ��ͨ!","������ʾ",MB_OK|MB_ICONSTOP);
}

void CMain::OnButMessage()       //����Ȩ�޷���
{
	Cusersrights cusersrights;
	cusersrights.DoModal();


}

void CMain::OnButDuty()    //������Ա
{
	//CDuty dlg;
	//dlg.DoModal();

	MessageBox("�Բ�����ʱδ��ͨ!","������ʾ",MB_OK|MB_ICONSTOP);
	
}

void CMain::OnButCG()    //ͼ�������Ϣ
{
	Coutin coutin;
	coutin.DoModal();
}

void CMain::OnButadd() 
{
	
}

HBRUSH CMain::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)   //����Ӧ�ó�����ı���ģʽ�ͱ�����ɫ�� ����ˢ��, ëˢ, ����
{
	HBRUSH hbr = CDialog::OnCtlColor(pDC, pWnd, nCtlColor);
	/*
	if(pWnd==&m_StaOP)
	{
	//	pDC->SetBkMode(TRANSPARENT);
		pDC->SetBkColor(RGB(255,255,255));	
	}
	*/	
	// TODO: Return a different brush if the default is not desired
	return hbr;
}

void CMain::OnOK() 
{
	// TODO: ���������Ҫ����֤
	
	//CDialog::OnOK();
}

void CMain::OnButOP()      //�û�����
{
    CDUser dlg;
	dlg.DoModal();
	
}

void CMain::OnPaint() 
{
	CPaintDC dc(this); // device context for painting  //Ϊ�豸��������ɫ
	CRect rect;        //ʵ����һ��Windows RECT structure
	this->GetWindowRect(&rect);  //����ֵΪbool
	CBitmap bit;                 //ʵ����һ��λͼ
	//bit.LoadBitmap(IDB_BLACK);
	bit.LoadBitmap(IDB_BITMAP2);    //����ͼƬ          //ʹ��WINUSERAPI
	CDC memDC;                      //ͬ������windows user API����windows �û�API��CDC����ʵ����һ��CDC����
	memDC.CreateCompatibleDC(&dc);  //����һ������豸���ݵ�DC��device context����DC��device context�豸������
	memDC.SelectObject(&bit);
	dc.BitBlt(98,100,rect.Width(),rect.Height()-100,&memDC,0,100,SRCCOPY);
    //dc.BitBlt(100,110,rect.Width(),rect.Height(),&memDC,0,50,SRCCOPY);
	bit.DeleteObject();
	memDC.DeleteDC();

}
void CMain::PaintPic1()
{
    CPaintDC dc1(this); // device context for painting  //Ϊ�豸��������ɫ
	CRect rect1;        //ʵ����һ��Windows RECT structure
	this->GetWindowRect(&rect1);  //����ֵΪbool
	CBitmap bit1;                 //ʵ����һ��λͼ
	//bit.LoadBitmap(IDB_BLACK);
	bit1.LoadBitmap(IDB_USER);    //����ͼƬ          //ʹ��WINUSERAPI
	CDC memDC1;                      //ͬ������windows user API����windows �û�API��CDC����ʵ����һ��CDC����
	memDC1.CreateCompatibleDC(&dc1);  //����һ������豸���ݵ�DC��device context����DC��device context�豸������
	memDC1.SelectObject(&bit1);
	//dc.BitBlt(2,2,rect.Width(),rect.Height(),&memDC,0,0,SRCCOPY);
    dc1.BitBlt(2,2,rect1.Width(),rect1.Height(),&memDC1,0,0,SRCCOPY);
	bit1.DeleteObject();
	memDC1.DeleteDC();
}
void CMain::PaintPic2()
{
    CPaintDC dc(this); // device context for painting  //Ϊ�豸��������ɫ
	CRect rect;        //ʵ����һ��Windows RECT structure
	this->GetWindowRect(&rect);  //����ֵΪbool
	CBitmap bit;                 //ʵ����һ��λͼ
	//bit.LoadBitmap(IDB_BLACK);
	bit.LoadBitmap(IDB_BITMAP2);    //����ͼƬ          //ʹ��WINUSERAPI
	CDC memDC;                      //ͬ������windows user API����windows �û�API��CDC����ʵ����һ��CDC����
	memDC.CreateCompatibleDC(&dc);  //����һ������豸���ݵ�DC��device context����DC��device context�豸������
	memDC.SelectObject(&bit);
	//dc.BitBlt(2,2,rect.Width(),rect.Height(),&memDC,0,0,SRCCOPY);
    dc.BitBlt(100,100,100,100,&memDC,150,150,SRCCOPY);
	bit.DeleteObject();
	memDC.DeleteDC();
}
void CMain::PaintPic3()  //ͬʱ����2��ͼƬ
{
	CPaintDC dc1(this),dc2(this);
	CRect rect1,rect2;
	this->GetWindowRect(&rect1);
	this->GetWindowRect(&rect2);
	CBitmap bit1,bit2;
	bit1.LoadBitmap(IDB_BITMAP2);
	bit2.LoadBitmap(IDB_USER);
	CDC memDC1,memDC2;
	memDC1.CreateCompatibleDC(&dc1);
    memDC1.SelectObject(&bit1);
    memDC2.CreateCompatibleDC(&dc2);
	memDC2.SelectObject(&bit2);
    dc1.BitBlt(100,100,100,100,&memDC1,150,150,SRCCOPY);
    dc2.BitBlt(2,2,rect2.Width(),rect2.Height(),&memDC2,150,150,SRCCOPY);
    bit1.DeleteObject();
	bit2.DeleteObject();
	memDC1.DeleteDC();
	memDC2.DeleteDC();
	
}
