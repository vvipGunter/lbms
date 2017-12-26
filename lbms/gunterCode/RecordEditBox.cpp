// RecordEditBox.cpp : implementation file
//

#include "stdafx.h"
#include "gunterLBMS.h"
#include "RecordEditBox.h"
#include "RainFunction.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CRecordEditBox

CRecordEditBox::CRecordEditBox()
{
}

CRecordEditBox::~CRecordEditBox()
{
}


BEGIN_MESSAGE_MAP(CRecordEditBox, CEdit)
	//{{AFX_MSG_MAP(CRecordEditBox)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRecordEditBox message handlers



BOOL CRecordEditBox::PreTranslateMessage(MSG* pMsg) 
{
	if(pMsg->message==WM_KEYDOWN && (pMsg->wParam==13 ||pMsg->wParam==9))
	{
		if(this->EmptyValidate==true)
		{
			CString sChar;
			this->GetWindowText(sChar);
			if(sChar.IsEmpty())
			{
				MessageBox("此字段不允许为空！","系统提示",MB_OK|MB_ICONSTOP);
				this->SetFocus();
			}
			else
			{
				pMsg->wParam=9;
			}
		}
		else
		{
			pMsg->wParam=9;	
		}
	}
	return CEdit::PreTranslateMessage(pMsg);
}	

void CRecordEditBox::Init(_RecordsetPtr Record,CString FieldName)
{
	CString Name;
	this->_Record=Record;
	this->_FieldName=FieldName;
	Name=(char*)(_bstr_t)_Record->GetCollect((_bstr_t)_FieldName);
	this->SetWindowText(Name);
}

