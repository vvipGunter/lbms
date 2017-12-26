// RecordList.cpp : implementation file
//

#include "stdafx.h"
#include "gunterLBMS.h"
#include "RecordList.h"
#include "RainFunction.h"
#include "RecordComboBox.h"
#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif
/////////////////////////////////////////////////////////////////////////////
// CRecordList

CRecordList::CRecordList()
{
}

CRecordList::~CRecordList()
{
}


BEGIN_MESSAGE_MAP(CRecordList, CListBox)
	//{{AFX_MSG_MAP(CRecordList)
		// NOTE - the ClassWizard will add and remove mapping macros here.
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CRecordList message handlers

void CRecordList::Init(CString FieldName)
{
	CString Text;
	this->Field=FieldName;
	for(int i=0;i<function.RecordCount(record);i++)
	{
		record->MoveFirst();
		record->Move(i);
		Text=(char*)(_bstr_t)record->GetCollect((_bstr_t)FieldName);
		this->AddString(Text);
	}
}

BOOL CRecordList::PreTranslateMessage(MSG* pMsg) 
{
	CString Text;
	int ID;
	if(pMsg->message==WM_LBUTTONUP)
	{
		try{
		if(this->GetCurSel()==-1)
			return 0;
		this->GetText(this->GetCurSel(),Text);
		ID=function.NumberTOName(this->DateBaseName,this->Field,Text);
		this->Recno=ID;
		}
		catch(...)
		{
			return 0;
		}
	}
	return CListBox::PreTranslateMessage(pMsg);
}
