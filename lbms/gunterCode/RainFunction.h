// RainFunction1.h: interface for the CRainFunction class.
//
//////////////////////////////////////////////////////////////////////

#if !defined(AFX_RAINFUNCTION1_H__54826B61_5B0F_11D8_8750_5254AB32C8FB__INCLUDED_)
#define AFX_RAINFUNCTION1_H__54826B61_5B0F_11D8_8750_5254AB32C8FB__INCLUDED_

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000

class CRainFunction  
{
public:
	int GetRecno(_RecordsetPtr rst ,CString FieldName,CString FieldValue);
	CRainFunction();
	virtual ~CRainFunction();
	CString AutoNumber(CString TableName,CString sLater,int nflg);
	int NumberTOName(CString TableName, CString field,CString value);
	CString NumberTOName(CString TableName, CString Returnfield,CString field,CString value,int nflg);
	CString NumberTOName(CString TableName,int Number,CString field);
	CString CharToLetterCode(CString string);
	MSG* CMessage(CWnd* ParentWnd,MSG *Msg, CWnd *Wnd, CWnd *NextWnd);
	int AutoNumber(int nflg,CString TableName);
	int RecordCount(_RecordsetPtr rRecord);
	CString Padl(CString String, int digit, CString Fill,int Way=1);
	CTime CStringTOCTime(CString cDate);
	CString CTimeToCString(CTime date);
	void InPutFormat(int Type,CWnd* Wnd,MSG *Msg);
	void ADOError(_RecordsetPtr ADORecordset);

};

#endif // !defined(AFX_RAINFUNCTION1_H__54826B61_5B0F_11D8_8750_5254AB32C8FB__INCLUDED_)
