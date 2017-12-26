// RainFunction1.cpp: implementation of the CRainFunction class.
//
//////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "gunterLBMS.h"
#include "RainFunction.h"

#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[]=__FILE__;
#define new DEBUG_NEW
#endif
extern _ConnectionPtr cnn;
//////////////////////////////////////////////////////////////////////
// Construction/Destruction
//////////////////////////////////////////////////////////////////////

CRainFunction::CRainFunction()
{

}

CRainFunction::~CRainFunction()
{

}

/*��Ҫ����:                                     
	�������ݱ��м�¼����Զ�����ָ����ʽ�ı�š�
  ����:                                     
	TableName
	sLate�����ɵı��ǰ��λ�ı�־���ݡ�            
	nFlg:�������뷽ʽ�����Ϊ1 ,����Ϊ��־λ����ˮ������ SP00000001;
		���Ϊ2 ��Ϊ����ʱ����� �� RK031224-000001;
		ȱʡֵΪ1.
*/
CString CRainFunction::AutoNumber(CString TableName,CString sLater,int nflg)
								  
{
	CTime _time,_CurrentTime;
	CString MaxNumber,_sDay,_sYear,_sMonth,NewNumber,ReturnNumber,sSQL;
	int _Day,_Year,_Month;
	_RecordsetPtr AutoNumber_Rst;
	AutoNumber_Rst.CreateInstance(__uuidof(Recordset));
	::CoInitialize(NULL);
	_variant_t value;
	if(nflg==1)
	{
		sSQL.Format("SELECT MAX(���) as ����� FROM %s",TableName);
		AutoNumber_Rst = cnn->Execute((_bstr_t)sSQL,NULL,adCmdText);		
		value=AutoNumber_Rst->GetCollect("�����");
		if(value.vt==VT_NULL)
		{
			ReturnNumber.Format("%s00000001",sLater);
		}
		else
		{
			MaxNumber=(char*)(_bstr_t)value;
			MaxNumber=MaxNumber.Mid(3); 
			NewNumber.Format("%d",atoi(MaxNumber)+1);
			ReturnNumber.Format("%s%s",sLater,this->Padl(NewNumber,8,"0"));
		}
	}
	else
	{
		_time=_CurrentTime.GetCurrentTime(); 
		_Year=_time.GetYear();
		_Month=_time.GetMonth();
		_Day=_time.GetDay();
		_sDay.Format("%d",_Day);
		_sDay=this->Padl(_sDay,2,"0");
		_sMonth.Format("%d",_Month);
		_sMonth=this->Padl(_sMonth,2,"0");
		_sYear.Format("%d",_Year);
		_sYear=_sYear.Mid(2);
		sSQL.Format("SELECT MAX(Ʊ��) as ����� FROM %s",TableName);
		AutoNumber_Rst = cnn->Execute((_bstr_t)sSQL,NULL,adCmdText);		
		if(AutoNumber_Rst->_EOF)
		{
			ReturnNumber.Format("%s%s%s%s-000001  ",sLater,_sYear,_sMonth,_sDay);
			goto retu;
		}
		value=AutoNumber_Rst->GetCollect("�����");//ȡ�������
		if(value.vt==VT_NULL)
		{
			ReturnNumber.Format("%s%s%s%s-000001  ",sLater,_sYear,_sMonth,_sDay);
		}
		else
		{
			CString sOldDate,sNewDate;
			sOldDate=(char*)(_bstr_t)value;
			sOldDate=sOldDate.Mid(2,6);
			sNewDate.Format("%s%s%s",_sYear,_sMonth,_sDay);
			if(sOldDate==sNewDate)
			{
				MaxNumber.Format((char*)(_bstr_t)value);
				MaxNumber=MaxNumber.Mid(9);
				NewNumber.Format("%d",atoi(MaxNumber)+1);
				ReturnNumber.Format("%s%s%s%s-%s",sLater,_sYear,_sMonth,_sDay,this->Padl(NewNumber,6,"0"));
			}
			else
			{
				ReturnNumber.Format("%s%s%s%s-000001  ",sLater,_sYear,_sMonth,_sDay);		
			}
		}
	}
retu:	AutoNumber_Rst->Close();
	return ReturnNumber;
}
/*��Ҫ����:                                    
	ͨ���ֶη�����ֵ��š�     ����������        
  ����:                                          
	TableName��ָ��Ҫ���в�ѯ�����ݱ������ ��       
	field��ָ���ֶ����ơ�                            
	value: ָ���ֶε�ֵ��*/
int CRainFunction::NumberTOName(CString TableName, CString field,CString value)
{
	_RecordsetPtr NumberTOName_rst;
	CString cSQL;
	_bstr_t val;
	int backnumber=0;
	NumberTOName_rst.CreateInstance(__uuidof(Recordset));
	cSQL.Format("SELECT * FROM %s WHERE %s='%s'",TableName,field,value);
	NumberTOName_rst=cnn->Execute((_bstr_t)cSQL,NULL,adCmdText);
	if(NumberTOName_rst->_EOF)
		goto end;
	else
	{
	val=NumberTOName_rst->GetCollect("���");
	backnumber=atoi((char*)(_bstr_t)val);
	}
end: NumberTOName_rst->Close();
	 return backnumber;
}

/*��Ҫ����:                                      
	ͨ���ֶη����ַ���Ż�ͨ���ַ���ŷ���ָ���ֶΡ� 
������:                                          
	TableName��ָ��Ҫ���в�ѯ�����ݱ������ ��       
	field��ָ���ֶ����� ��                           
	value: ָ���ֶε�ֵ��   ������������������������ 
	nflg: ��־ͨ���ֶη����ַ���Ż���ͨ���ַ���ŷ����ֶΡ�
		��nflg=1ʱ����ǰ��;nflg<>1���غ��ߡ�*/
CString CRainFunction::NumberTOName(CString TableName, CString Returnfield,CString field,CString value,int nflg)
{
	_RecordsetPtr NumberTOName_rst2;
	CString cSQL,backnumber;
	_bstr_t val;
	NumberTOName_rst2.CreateInstance(__uuidof(Recordset));
	cSQL.Format("SELECT * FROM %s WHERE %s='%s'",TableName,field,value);
	NumberTOName_rst2=cnn->Execute((_bstr_t)cSQL,NULL,adCmdText);
	if(NumberTOName_rst2->_EOF)
		backnumber.Format("WRONG");
	else
	{
		if(nflg==1)
		{
		val=NumberTOName_rst2->GetCollect("���");
		}
		else
		{
		val=NumberTOName_rst2->GetCollect((_variant_t)Returnfield);
		}
		backnumber.Format((char*)(_bstr_t)val);
	}	
	NumberTOName_rst2->Close();
	return backnumber;
}
/*��Ҫ����:                                      
	ͨ����ֵ��ŷ���ָ���ֶΡ� 
������:                                          
	TableName��ָ��Ҫ���в�ѯ�����ݱ������ ��       
	Number��ָ����ֵ�ͱ�š�                           
	field: ָ�����ص��ֶ�����*/
CString CRainFunction::NumberTOName(CString TableName,int Number,CString field)
{
	_RecordsetPtr NumberTOName_rst3;
	CString cSQL,backnumber="WRONG";
	_bstr_t val;
	NumberTOName_rst3.CreateInstance(__uuidof(Recordset));
	cSQL.Format("SELECT * FROM %s WHERE ���=%d",TableName,Number);
	NumberTOName_rst3=cnn->Execute((_bstr_t)cSQL,NULL,adCmdText);
	if(NumberTOName_rst3->_EOF)
		backnumber.Format("WRONG");
	else
	{
		val=NumberTOName_rst3->GetCollect((_variant_t)field);
		backnumber.Format((char*)(_bstr_t)val);
	}
	NumberTOName_rst3->Close();
	return backnumber;
}
/*��Ҫ����:                                      
	����ָ���ַ�����ƴ�����롣 
������:                                          
	String:Ҫ���ƴ��������ַ�����       
  ע�⣺
	�������Ӣ���ַ�����ʹ��ȫ�ǻ�����һ����Ǻ�����һ���ظ�*/
CString CRainFunction::CharToLetterCode(CString string)
{
	unsigned short i;     //�޷��Ŷ�����
	CString value,ReturnValue;
	char chr[3];
	BYTE bHeight;
	BYTE bLow;
	
	for(int m=0;m<=string.GetLength()-1;m=m+2)
	{
		if(m%2!=0)
		{
			if(m<string.GetLength()-1)
			m=m+1;

		}
		chr[0]=string.GetAt(m);
		if((((BYTE)chr[0]>=0x20&&(BYTE)chr[0]<=0x80)||(BYTE)chr[0]==0xbf))	
		{
			int StringLength=string.GetLength();
			if(m+1<StringLength)
			{
 				chr[1]=string.GetAt(m+1);			
				if(chr[1]<0)
				{
					chr[2]=0;
					bHeight=chr[1];
					bLow=chr[0];
					i=bHeight+bLow*256;
					value.Format("%s","K");	
				}
				else
				{	
					chr[1]=0;
					chr[2]=0;
					value.Format("");
					m++;
				}
			}
			else
			{
				chr[1]=0;
				chr[2]=0;
				value.Format("");
				m++;
			}
		}
		else
		{
			chr[1]=string.GetAt(m+1);
			chr[2]=0;
			bHeight=chr[1];
			bLow=chr[0];
			i=bHeight+bLow*256;
			if(i < (unsigned short)'��')
				value.Format("%s ",chr);
			if( i>= (unsigned short)'��'&& i<(unsigned short)'��')
				value.Format("A");
			if( i>= (unsigned short)'��'&& i<(unsigned short)'��')
				value.Format("B");
			if( i>= (unsigned short)'��'&& i<(unsigned short)'��')
				value.Format("C");
			if( i>= (unsigned short)'��'&& i<(unsigned short)'��')
				value.Format("D");
			if( i>= (unsigned short)'��'&& i<(unsigned short)'��')
				value.Format("E");
			if( i>= (unsigned short)'��'&& i<(unsigned short)'��')
				value.Format("F");
			if( i>= (unsigned short)'��'&& i<(unsigned short)'��')
				value.Format("G");
			if( i>= (unsigned short)'��'&& i<(unsigned short)'��')
				value.Format("H");
			if(( i>= (unsigned short)'��'&& i<(unsigned short)'��')|| i==(unsigned short)'��')
				value.Format("J");
			if( i>= (unsigned short)'��'&& i<(unsigned short)'��')
				value.Format("K");
			if( i>= (unsigned short)'��'&& i<(unsigned short)'��')
				value.Format("L");
			if( i>= (unsigned short)'��'&& i<(unsigned short)'��')
				value.Format("M");
			if( i>= (unsigned short)'��'&& i<(unsigned short)'Ŷ')
				value.Format("N");
			if( i>= (unsigned short)'Ŷ'&& i<(unsigned short)'ž')
				value.Format("O");
			if( i>= (unsigned short)'ž'&& i<(unsigned short)'��')
				value.Format("P");
			if( i>= (unsigned short)'��'&& i<(unsigned short)'Ȼ')
				value.Format("Q");
			if( i>= (unsigned short)'Ȼ'&& i<(unsigned short)'��')
				value.Format("R");
			if( i>= (unsigned short)'��'&& i<(unsigned short)'��')
				value.Format("S");
			if( i>= (unsigned short)'��'&& i<(unsigned short)'��')
				value.Format("T");
			if( i>= (unsigned short)'��'&& i<(unsigned short)'��')
				value.Format("W");
			if( i>= (unsigned short)'��'&& i<(unsigned short)'ѹ')
				value.Format("X");
			if( i>= (unsigned short)'ѹ'&& i<(unsigned short)'��')
				value.Format("Y");
			if( i>= (unsigned short)'��' && i!=(unsigned short)'�' && i!=(unsigned short)'ܰ' && i!=(unsigned short)'ܲ')
				value.Format("Z");
		}
	 ReturnValue=ReturnValue+value;
	}
	return ReturnValue;
}
/*��Ҫ����:                                      
	���õ��س���ʱ�����ƶ���˳�� 
������:                                          
	ParentWnd���������ڵĸ�����ָ�� ��       
	Msg��ָ����Ϣ��ָ�롣                           
	Wnd:��Ҫ�����Ķ���ָ�롣
	NextWnd:�����ƶ����Ķ���ָ��*/
MSG* CRainFunction::CMessage(CWnd* ParentWnd,MSG *Msg, CWnd *Wnd, CWnd *NextWnd)
{
	CString ClassString_Down,ClassString_Up;
	ClassString_Down=Wnd->GetRuntimeClass()->m_lpszClassName;
	ClassString_Up=NextWnd->GetRuntimeClass()->m_lpszClassName;
	if(ClassString_Down=="CComboBox")
	{
		if(Wnd->GetStyle()==1342243586)
		{
			if (ParentWnd->FromHandle(Msg->hwnd)->GetParent()->GetSafeHwnd()==Wnd->GetSafeHwnd() &&Msg->message==WM_KEYDOWN && (Msg->wParam==39||Msg->wParam==13))
			{
				NextWnd->SetFocus();
				Msg->wParam=0x1d;
			}
		}
		else
		{
			if(Msg->hwnd==Wnd->GetSafeHwnd() && Msg->message==WM_KEYDOWN && (Msg->wParam==13||Msg->wParam==39))
			{
				NextWnd->SetFocus();
				Msg->wParam=0x1d;
			}
		}
	}
	else
	{
		if(Msg->hwnd==Wnd->GetSafeHwnd() && Msg->message==WM_KEYDOWN && (Msg->wParam==13||Msg->wParam==40))
		{
		NextWnd->SetFocus();
		Msg->wParam=0x1d;
		}
	}
	if(ClassString_Up=="CComboBox")
	{
		if(Wnd->GetStyle()==1342243586)
		{
			if (ParentWnd->FromHandle(Msg->hwnd)->GetParent()->GetSafeHwnd()==NextWnd->GetSafeHwnd() &&Msg->message==WM_KEYDOWN && (Msg->wParam==37))
			{
				Wnd->SetFocus();
				Msg->wParam=0x1d;
			}
		}
		else
		{
			if(Msg->hwnd==NextWnd->GetSafeHwnd() && Msg->message==WM_KEYDOWN && Msg->wParam==37)
			{
				Wnd->SetFocus();
				Msg->wParam=0x1d;
			}
		}
	}
	else
	{
		if(Msg->hwnd==NextWnd->GetSafeHwnd() && Msg->message==WM_KEYDOWN && Msg->wParam==38)
		{
		Wnd->SetFocus();
		Msg->wParam=0x1d;
		}
	}
	return Msg;
}
/*��Ҫ����:                                      
	�Զ�������ֵ�ͱ�š� 
������:
	nflg:δ�ã�����Ϊ0                                                 
	TableName:��Ҫ���������ݱ�����ơ�*/
int CRainFunction::AutoNumber(int nflg,CString TableName)
{
	_RecordsetPtr AutoNumber_Rst2;
	AutoNumber_Rst2.CreateInstance(__uuidof(Recordset));
	
	CString sSQL;
	_variant_t value;
	int nNumber=1;
	sSQL.Format("SELECT MAX(���) as ����� FROM %s",TableName);
	AutoNumber_Rst2 = cnn->Execute((_bstr_t)sSQL,NULL,adCmdText);		
	value=AutoNumber_Rst2->GetCollect("�����");
	if(value.vt==VT_NULL)
	{
		nNumber=1;
	}
	else
	{
		nNumber=atoi((char*)(_bstr_t)value)+1;
	}
	AutoNumber_Rst2->Close();

	return nNumber;
}
/*��Ҫ����:                                      
	����ָ����¼���м�¼�ĸ����� 
������:                                          
	rRecord��ָ�����ݼ� ��*/
int CRainFunction::RecordCount(_RecordsetPtr rRecord)
{
	int recordcount=0;
	try{
	rRecord->MoveFirst();
	}
	catch(...)
	{
		return 0;
	}
	if(rRecord->_EOF)
		return 0;
	while (!rRecord->_EOF)
	{
		rRecord->MoveNext();
		recordcount=recordcount+1;	
	}
	return recordcount;
}	
/*��Ҫ����:                                      
	���ַ���ǰ���ָ���������ַ��� 
������:                                          
	String��Դ�ַ��� ��       
	digit���ַ����ĳ��ȡ�                           
	fill: �����ַ���*/
CString CRainFunction::Padl(CString String, int digit, CString Fill,int Way)
{
	int Padl_n;
	CString Padl_string;
	Padl_string.Empty();
	for(Padl_n=1;Padl_n<=digit-String.GetLength();Padl_n++)
	{
	Padl_string=Padl_string+Fill;
	}
	if(Way==1)
		return Padl_string+String;
	else
		return String+Padl_string;
}

/*��Ҫ����:                                      
	��ʱ���ַ���ת����CTime���͡� 
������:                                          
	cDate��ָ���ַ����ַ��� ��       
  ע��:
	cDate��YYYY-MM-DD��ʽ��*/
CTime CRainFunction::CStringTOCTime(CString cDate)
{
	int nYear,nMonth,nDay,iFChar,iSChar;
	CString cYear,cMonth,cDay;
	CTime tDate;
	//ȡ����-����λ��
	iFChar=cDate.Find("-",0);	
	iSChar=cDate.Find("-",iFChar+1);
	cYear=cDate.Left(4);
	cMonth=cDate.Mid(iFChar+1,iSChar-(iFChar+1));
	cDay=cDate.Mid(iSChar+1);
	
	
	
	nYear=atoi(cYear);
	nMonth=atoi(cMonth);
	nDay=atoi(cDay);
	
	tDate=CTime::CTime(nYear,nMonth,nDay,0,0,0);
	return tDate;
}
/*��Ҫ����:                                      
	��CTime��������ת����ʱ���ַ����� 
������:                                          
	date:CTime�������� �� */
CString CRainFunction::CTimeToCString(CTime date)
{
	int nYear,nMonth,nDay;
	CString sDate;
	nYear=date.GetYear();
	nMonth=date.GetMonth();
	nDay=date.GetDay();
	sDate.Format("%d-%d-%d",nYear,nMonth,nDay);
	return sDate;
}
/*��Ҫ����:                                      
	����ĳһWnd�����������������ֻ�С���㡣
	���Ϊ1�����������С����
������:                                          
	Wnd����Ҫ���õĶ���ָ�� ��       
	Msg����Ϣָ�롣*/
void CRainFunction::InPutFormat(int Type,CWnd* Wnd,MSG *Msg)
{
	if(Type==1)
	{
		if(Msg->hwnd==Wnd->GetSafeHwnd() && Msg->message==WM_KEYDOWN 
			&& (Msg->wParam<48 || Msg->wParam>57)&&(Msg->wParam<96 || Msg->wParam>105)&& Msg->wParam!=110  && Msg->wParam!=190  && Msg->wParam!=8 && Msg->wParam!=13 )
		{
			Msg->wParam=0x1d;//����Ӧ����Ϊ����Ctrl��
		}

	}
}
/*��Ҫ����:                                      
	����ADO����
*/
void CRainFunction::ADOError(_RecordsetPtr ADORecordset)
{
	ErrorsPtr pErrors=cnn->GetErrors();
	for (int i=0;i<pErrors->GetCount();i++)
	{
		_bstr_t desc=pErrors->GetItem((long)i)->GetDescription();
		AfxMessageBox(desc);
	}
}


int CRainFunction::GetRecno(_RecordsetPtr rst, CString FieldName, CString FieldValue)
{
	CString value;
	int Recno;
	if(this->RecordCount(rst)<=0)
		Recno=-1;
	else
	{
		for(int i=0;i<this->RecordCount(rst);i++)
		{
			rst->MoveFirst();
			rst->Move(i);
			value=(char*)(_bstr_t)rst->GetCollect((_bstr_t)FieldName);
			if(value==FieldValue)
			{
				Recno=i+1;
				goto ret;
			}	
		}
	}
ret: return Recno;
}
