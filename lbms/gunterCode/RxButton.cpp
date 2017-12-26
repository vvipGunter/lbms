// RxButton.cpp : implementation file
//

#include "stdafx.h"
#include "gunterLBMS.h"
#include "RxButton.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRxButton

CRxButton::CRxButton()
{

}

CRxButton::~CRxButton()
{
}


BEGIN_MESSAGE_MAP(CRxButton, CButton)
	//{{AFX_MSG_MAP(CRxButton)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRxButton message handlers


void CRxButton::DrawItem(LPDRAWITEMSTRUCT lpDrawItemStruct)    ////写左边的按钮的图片及文本
{
	CDC* pDC;
	pDC=CDC::FromHandle(lpDrawItemStruct->hDC);
	UINT state=lpDrawItemStruct->itemState;
	CRect rect=lpDrawItemStruct->rcItem;

	CBitmap bitDown,bitNomal;
	bitNomal.LoadBitmap(m_ResDown);
	bitDown.LoadBitmap(m_ResNoNal);
	CDC NomalDC,DownDC;
	NomalDC.CreateCompatibleDC(pDC);
	DownDC.CreateCompatibleDC(pDC);
	NomalDC.SelectObject(bitNomal);
	DownDC.SelectObject(bitDown);
	
	if(state&ODS_FOCUS)
		pDC->SetTextColor(RGB(0,0,255));
	else
		pDC->SetTextColor(RGB(255,255,255));

	if(state&ODS_SELECTED)
	{
		pDC->BitBlt(0,0,100,100,&DownDC,0,0,SRCCOPY);
		pDC->SetTextColor(RGB(0,0,0));
	}
	else
	{
		pDC->BitBlt(0,0,100,100,&NomalDC,0,0,SRCCOPY);
	}
//写按钮文本
	pDC->SetBkMode(TRANSPARENT);
	CString sCaption;
	this->GetWindowText(sCaption);
	pDC->DrawText(sCaption,rect,DT_CENTER|DT_VCENTER|DT_SINGLELINE);	
	bitNomal.DeleteObject();
	bitDown.DeleteObject();
	NomalDC.DeleteDC();
	DownDC.DeleteDC();

}

void CRxButton::Bitmap(UINT ResNoNal,UINT ResDown)
{
	m_ResDown=ResDown;
	m_ResNoNal=ResNoNal;
}

//DEL void CRxButton::Drawit(CDC* pDC,UINT ResID)
//DEL {
//DEL 	
//DEL 	CDC memDC;
//DEL 	CBitmap bit;
//DEL 	CBitmap* pbit;
//DEL 	COLORREF Col,OldCol;
//DEL 	BITMAP bitstruct;
//DEL 	bit.LoadBitmap(ResID);
//DEL 	bit.GetBitmap(&bitstruct);
//DEL 	
//DEL 	memDC.CreateCompatibleDC(pDC);
//DEL 	pbit=memDC.SelectObject(&bit);
//DEL 
//DEL 	OldCol=memDC.GetPixel(0,0);
//DEL 	for(int x=0;x<bitstruct.bmWidth;x++)
//DEL 	{
//DEL 		for(int y=0;y<bitstruct.bmHeight;y++)
//DEL 		{
//DEL 			Col=memDC.GetPixel(x,y);
//DEL 			if(Col!=OldCol)
//DEL 				pDC->SetPixel(x,y,Col);
//DEL 		}
//DEL 	}
//DEL 	memDC.DeleteDC();
//DEL 	::DeleteObject(&bit);
//DEL 	::DeleteObject(pbit);
//DEL }




void CRxButton::PreSubclassWindow() 
{

	
	CButton::PreSubclassWindow();
}
