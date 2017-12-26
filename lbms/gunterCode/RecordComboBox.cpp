// RecordComboBox.cpp : implementation file
//

#include "stdafx.h"
#include "gunterLBMS.h"
#include "RecordComboBox.h"
#include "RainFunction.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
extern _ConnectionPtr cnn;
/////////////////////////////////////////////////////////////////////////////
// CRecordComboBox

CRecordComboBox::CRecordComboBox()
{
}

CRecordComboBox::~CRecordComboBox()
{
}


BEGIN_MESSAGE_MAP(CRecordComboBox, CComboBox)
	//{{AFX_MSG_MAP(CRecordComboBox)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRecordComboBox message handlers

void CRecordComboBox::Init(CString FieldName)
{
	this->Field=FieldName;
	CString Text;
	for(int i=0;i<function.RecordCount(this->record);i++)
	{
		record->MoveFirst();
		record->Move(i);
		Text=(char*)(_bstr_t)record->GetCollect((_bstr_t)FieldName);
		this->AddString(Text);
	}
	this->SetWindowText("--");
}



BOOL CRecordComboBox::PreTranslateMessage(MSG* pMsg) 
{
	CString Text;
	this->GetWindowText(Text);
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
	if((this->GetParent()->FromHandle(pMsg->hwnd)->GetParent()->GetSafeHwnd()==this->GetSafeHwnd() || (this->GetSafeHwnd()==pMsg->hwnd))&&Text.IsEmpty()==false)
	{
		
		if(this->IDStyle==1)
			this->Recno=function.NumberTOName(this->DateBaseName,this->Field,Text);
		else
			this->sID=function.NumberTOName(this->DateBaseName,"编号",this->Field,Text,1);
	}

	return CComboBox::PreTranslateMessage(pMsg);
}


