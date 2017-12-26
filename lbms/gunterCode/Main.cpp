// Main.cpp : implementation file
// Main.cpp ：执行文件

//

//这是主对话框 主窗体 在这里有各种功能的菜单操作
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


//导入文件  added
#include "opbooks.h"
#include "usersrights.h"
#include "outin.h"
//获取当前的时间
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
// CMain message handlers   CMain 消息出来

BOOL CMain::OnInitDialog()    //初始化CMain窗体
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
    MessageBox("恭喜您！您成功以"+successdengluUserID+"的身份登陆！","登陆用户信息",MB_OK|MB_ICONQUESTION); ////获取登陆的用户ID
    //mynowtime=this->getNowTime();
    //this->labelTime.SetWindowText(mynowtime);
	return TRUE;  // return TRUE unless you set the focus to a control
	              // EXCEPTION: OCX Property Pages should return FALSE
}

void CMain::OnButClime()    //系统设置  测试 test
{
	//CClime dlg;
   	//dlg.DoModal();
   	//下面一行先暂时注释掉
	/*CDuty c;
	c.DoModal();*/
	
	  CString mynowtime;
      mynowtime=this->getNowTime();
      MessageBox(mynowtime,"当前时间",MB_OK|MB_ICONSTOP);

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
   //MessageBox((char *)(_bstr_t)b,"当前时间",MB_OK|MB_ICONSTOP);
   //MessageBox(mynowtime,"当前时间",MB_OK|MB_ICONSTOP);
  //this->getNowTime();            //调用下面的函数getNowTime以获取当前的时间
	 //CClientStyle dlg;
     //dlg.DoModal();
}

//gunterADD   //获取当前系统的时间
CString CMain::getNowTime()
{
   time_t  nowtime;
   struct tm *local;
  // local=gmtime(&nowtime);        //获取世界标准世界
   nowtime=time(NULL);               //获取当前系统的时间，为long int型
   local=localtime(&nowtime);    //获取本地时间
   CString strNowTime;             //最后拼接成的字符串
   CString strYear,strMonth,strDay,strHour,strMin,strSec;
   ////由int型赋值并转化为string类型
   //strYear=(char *)(_bstr_t)(local->tm_year+1900);
   //strMonth=(char *)(_bstr_t)(local->tm_mon+1);
   //strDay=(char *)(_bstr_t)local->tm_mday;
   //strHour=(char *)(_bstr_t)local->tm_hour;
   //strMin=(char *)(_bstr_t)local->tm_min;
   //strSec=(char *)(_bstr_t)local->tm_sec;
   //合成为最后的字符串
  
   strNowTime=strYear+"年"+strMonth+"月"+strDay+"日"+" "+strHour+"时"+strMin+"分"+strSec+"秒";
   //MessageBox(strNowTime,"当前时间",MB_OK|MB_ICONSTOP);
   return strNowTime;
}
 
void CMain::OnButUnit()    //个人图书管理
{
	//CUnit dlg;
	//dlg.DoModal();	
    Copbooks c;
	c.DoModal();
}

void CMain::OnButSort() 
{
	MessageBox("对不起！暂时未开通!","温情提示",MB_OK|MB_ICONSTOP);
}

void CMain::OnButMessage()       //读者权限分配
{
	Cusersrights cusersrights;
	cusersrights.DoModal();


}

void CMain::OnButDuty()    //管理人员
{
	//CDuty dlg;
	//dlg.DoModal();

	MessageBox("对不起！暂时未开通!","温磬提示",MB_OK|MB_ICONSTOP);
	
}

void CMain::OnButCG()    //图书借阅信息
{
	Coutin coutin;
	coutin.DoModal();
}

void CMain::OnButadd() 
{
	
}

HBRUSH CMain::OnCtlColor(CDC* pDC, CWnd* pWnd, UINT nCtlColor)   //绘制应用程序窗体的背景模式和背景颜色等 返回刷子, 毛刷, 画笔
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
	// TODO: 在这添加需要的验证
	
	//CDialog::OnOK();
}

void CMain::OnButOP()      //用户管理
{
    CDUser dlg;
	dlg.DoModal();
	
}

void CMain::OnPaint() 
{
	CPaintDC dc(this); // device context for painting  //为设备上下文着色
	CRect rect;        //实例化一个Windows RECT structure
	this->GetWindowRect(&rect);  //返回值为bool
	CBitmap bit;                 //实例化一个位图
	//bit.LoadBitmap(IDB_BLACK);
	bit.LoadBitmap(IDB_BITMAP2);    //导入图片          //使用WINUSERAPI
	CDC memDC;                      //同样调用windows user API，即windows 用户API的CDC类来实例化一个CDC对象
	memDC.CreateCompatibleDC(&dc);  //创建一个与此设备兼容的DC（device context），DC即device context设备上下文
	memDC.SelectObject(&bit);
	dc.BitBlt(98,100,rect.Width(),rect.Height()-100,&memDC,0,100,SRCCOPY);
    //dc.BitBlt(100,110,rect.Width(),rect.Height(),&memDC,0,50,SRCCOPY);
	bit.DeleteObject();
	memDC.DeleteDC();

}
void CMain::PaintPic1()
{
    CPaintDC dc1(this); // device context for painting  //为设备上下文着色
	CRect rect1;        //实例化一个Windows RECT structure
	this->GetWindowRect(&rect1);  //返回值为bool
	CBitmap bit1;                 //实例化一个位图
	//bit.LoadBitmap(IDB_BLACK);
	bit1.LoadBitmap(IDB_USER);    //导入图片          //使用WINUSERAPI
	CDC memDC1;                      //同样调用windows user API，即windows 用户API的CDC类来实例化一个CDC对象
	memDC1.CreateCompatibleDC(&dc1);  //创建一个与此设备兼容的DC（device context），DC即device context设备上下文
	memDC1.SelectObject(&bit1);
	//dc.BitBlt(2,2,rect.Width(),rect.Height(),&memDC,0,0,SRCCOPY);
    dc1.BitBlt(2,2,rect1.Width(),rect1.Height(),&memDC1,0,0,SRCCOPY);
	bit1.DeleteObject();
	memDC1.DeleteDC();
}
void CMain::PaintPic2()
{
    CPaintDC dc(this); // device context for painting  //为设备上下文着色
	CRect rect;        //实例化一个Windows RECT structure
	this->GetWindowRect(&rect);  //返回值为bool
	CBitmap bit;                 //实例化一个位图
	//bit.LoadBitmap(IDB_BLACK);
	bit.LoadBitmap(IDB_BITMAP2);    //导入图片          //使用WINUSERAPI
	CDC memDC;                      //同样调用windows user API，即windows 用户API的CDC类来实例化一个CDC对象
	memDC.CreateCompatibleDC(&dc);  //创建一个与此设备兼容的DC（device context），DC即device context设备上下文
	memDC.SelectObject(&bit);
	//dc.BitBlt(2,2,rect.Width(),rect.Height(),&memDC,0,0,SRCCOPY);
    dc.BitBlt(100,100,100,100,&memDC,150,150,SRCCOPY);
	bit.DeleteObject();
	memDC.DeleteDC();
}
void CMain::PaintPic3()  //同时绘制2张图片
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
