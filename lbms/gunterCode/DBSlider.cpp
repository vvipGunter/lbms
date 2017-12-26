// DBSlider.cpp : implementation file
//

#include "stdafx.h"
#include "gunterLBMS.h"
#include "DBSlider.h"
#include "RainFunction.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CDBSlider

CDBSlider::CDBSlider()
{
}

CDBSlider::~CDBSlider()
{
}


BEGIN_MESSAGE_MAP(CDBSlider, CSliderCtrl)
	//{{AFX_MSG_MAP(CDBSlider)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CDBSlider message handlers

BOOL CDBSlider::PreTranslateMessage(MSG* pMsg)   //Ô¤±àÒëÏûÏ¢
{
	int pos;
	CString sPos;
	if(pMsg->message==WM_LBUTTONDOWN || (pMsg->message==WM_KEYDOWN && (pMsg->wParam==37 ||pMsg->wParam==39)))
	{
		try{
		pos=this->GetPos();
		this->Recordset->MoveFirst();
		this->Recordset->Move(pos);
		this->Record=pos;
		sPos.Format("%d",pos);
		}
		catch(...)
		{
			return -1;
		}
	}
	return CSliderCtrl::PreTranslateMessage(pMsg);
}

void CDBSlider::Init()
{
	if(function.RecordCount(this->Recordset)>0)
	{
		this->SetRangeMax(function.RecordCount(this->Recordset),true);
		this->SetRangeMin(1,true);	
	}

}
