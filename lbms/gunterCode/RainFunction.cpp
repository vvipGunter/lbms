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

/*主要功能:                                     
	根据数据表中记录情况自动生成指定格式的编号。
  参数:                                     
	TableName
	sLate：生成的编号前两位的标志内容。            
	nFlg:决定编码方式，如果为1 ,编码为标志位加流水号码如 SP00000001;
		如果为2 则为日期时间编码 如 RK031224-000001;
		缺省值为1.
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
		sSQL.Format("SELECT MAX(编号) as 最大编号 FROM %s",TableName);
		AutoNumber_Rst = cnn->Execute((_bstr_t)sSQL,NULL,adCmdText);		
		value=AutoNumber_Rst->GetCollect("最大编号");
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
		sSQL.Format("SELECT MAX(票号) as 最大编号 FROM %s",TableName);
		AutoNumber_Rst = cnn->Execute((_bstr_t)sSQL,NULL,adCmdText);		
		if(AutoNumber_Rst->_EOF)
		{
			ReturnNumber.Format("%s%s%s%s-000001  ",sLater,_sYear,_sMonth,_sDay);
			goto retu;
		}
		value=AutoNumber_Rst->GetCollect("最大编号");//取出最大编号
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
/*主要功能:                                    
	通过字段返回数值编号。     　　　　　        
  参数:                                          
	TableName：指定要进行查询的数据表的名称 。       
	field：指定字段名称。                            
	value: 指定字段的值。*/
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
	val=NumberTOName_rst->GetCollect("编号");
	backnumber=atoi((char*)(_bstr_t)val);
	}
end: NumberTOName_rst->Close();
	 return backnumber;
}

/*主要功能:                                      
	通过字段返回字符编号或通过字符编号返回指定字段。 
　参数:                                          
	TableName：指定要进行查询的数据表的名称 。       
	field：指定字段名称 。                           
	value: 指定字段的值。   　　　　　　　　　　　　 
	nflg: 标志通过字段返回字符编号还是通过字符编号返回字段。
		　nflg=1时返回前者;nflg<>1返回后者。*/
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
		val=NumberTOName_rst2->GetCollect("编号");
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
/*主要功能:                                      
	通过数值编号返回指定字段。 
　参数:                                          
	TableName：指定要进行查询的数据表的名称 。       
	Number：指定数值型编号。                           
	field: 指定返回的字段名。*/
CString CRainFunction::NumberTOName(CString TableName,int Number,CString field)
{
	_RecordsetPtr NumberTOName_rst3;
	CString cSQL,backnumber="WRONG";
	_bstr_t val;
	NumberTOName_rst3.CreateInstance(__uuidof(Recordset));
	cSQL.Format("SELECT * FROM %s WHERE 编号=%d",TableName,Number);
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
/*主要功能:                                      
	返回指定字符串的拼音简码。 
　参数:                                          
	String:要获得拼音简码的字符串。       
  注意：
	如果输入英文字符。请使用全角或输入一个半角后输入一个控格*/
CString CRainFunction::CharToLetterCode(CString string)
{
	unsigned short i;     //无符号短整型
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
			if(i < (unsigned short)'啊')
				value.Format("%s ",chr);
			if( i>= (unsigned short)'啊'&& i<(unsigned short)'芭')
				value.Format("A");
			if( i>= (unsigned short)'芭'&& i<(unsigned short)'擦')
				value.Format("B");
			if( i>= (unsigned short)'擦'&& i<(unsigned short)'搭')
				value.Format("C");
			if( i>= (unsigned short)'搭'&& i<(unsigned short)'蛾')
				value.Format("D");
			if( i>= (unsigned short)'蛾'&& i<(unsigned short)'发')
				value.Format("E");
			if( i>= (unsigned short)'发'&& i<(unsigned short)'噶')
				value.Format("F");
			if( i>= (unsigned short)'噶'&& i<(unsigned short)'哈')
				value.Format("G");
			if( i>= (unsigned short)'哈'&& i<(unsigned short)'击')
				value.Format("H");
			if(( i>= (unsigned short)'击'&& i<(unsigned short)'喀')|| i==(unsigned short)'科')
				value.Format("J");
			if( i>= (unsigned short)'喀'&& i<(unsigned short)'垃')
				value.Format("K");
			if( i>= (unsigned short)'垃'&& i<(unsigned short)'妈')
				value.Format("L");
			if( i>= (unsigned short)'妈'&& i<(unsigned short)'拿')
				value.Format("M");
			if( i>= (unsigned short)'拿'&& i<(unsigned short)'哦')
				value.Format("N");
			if( i>= (unsigned short)'哦'&& i<(unsigned short)'啪')
				value.Format("O");
			if( i>= (unsigned short)'啪'&& i<(unsigned short)'期')
				value.Format("P");
			if( i>= (unsigned short)'期'&& i<(unsigned short)'然')
				value.Format("Q");
			if( i>= (unsigned short)'然'&& i<(unsigned short)'撒')
				value.Format("R");
			if( i>= (unsigned short)'撒'&& i<(unsigned short)'塌')
				value.Format("S");
			if( i>= (unsigned short)'塌'&& i<(unsigned short)'挖')
				value.Format("T");
			if( i>= (unsigned short)'挖'&& i<(unsigned short)'昔')
				value.Format("W");
			if( i>= (unsigned short)'昔'&& i<(unsigned short)'压')
				value.Format("X");
			if( i>= (unsigned short)'压'&& i<(unsigned short)'匝')
				value.Format("Y");
			if( i>= (unsigned short)'匝' && i!=(unsigned short)'炜' && i!=(unsigned short)'馨' && i!=(unsigned short)'懿')
				value.Format("Z");
		}
	 ReturnValue=ReturnValue+value;
	}
	return ReturnValue;
}
/*主要功能:                                      
	设置当回车键时焦点移动的顺序。 
　参数:                                          
	ParentWnd：对象所在的父窗口指针 。       
	Msg：指定消息的指针。                           
	Wnd:需要操作的对象指针。
	NextWnd:焦点移动到的对象指针*/
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
/*主要功能:                                      
	自动生成数值型编号。 
　参数:
	nflg:未用，设置为0                                                 
	TableName:需要操作的数据表的名称。*/
int CRainFunction::AutoNumber(int nflg,CString TableName)
{
	_RecordsetPtr AutoNumber_Rst2;
	AutoNumber_Rst2.CreateInstance(__uuidof(Recordset));
	
	CString sSQL;
	_variant_t value;
	int nNumber=1;
	sSQL.Format("SELECT MAX(编号) as 最大编号 FROM %s",TableName);
	AutoNumber_Rst2 = cnn->Execute((_bstr_t)sSQL,NULL,adCmdText);		
	value=AutoNumber_Rst2->GetCollect("最大编号");
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
/*主要功能:                                      
	返回指定记录集中记录的个数。 
　参数:                                          
	rRecord：指定数据集 。*/
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
/*主要功能:                                      
	在字符中前添加指定个数的字符。 
　参数:                                          
	String：源字符串 。       
	digit：字符串的长度。                           
	fill: 添充的字符串*/
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

/*主要功能:                                      
	将时间字符串转换成CTime类型。 
　参数:                                          
	cDate：指定字符型字符串 。       
  注意:
	cDate是YYYY-MM-DD型式。*/
CTime CRainFunction::CStringTOCTime(CString cDate)
{
	int nYear,nMonth,nDay,iFChar,iSChar;
	CString cYear,cMonth,cDay;
	CTime tDate;
	//取出“-”的位置
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
/*主要功能:                                      
	将CTime类型数据转换在时间字符串。 
　参数:                                          
	date:CTime类型数据 。 */
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
/*主要功能:                                      
	设置某一Wnd对象中允许输入数字或小数点。
	如果为1，则可以输入小数点
　参数:                                          
	Wnd：需要设置的对象指针 。       
	Msg：消息指针。*/
void CRainFunction::InPutFormat(int Type,CWnd* Wnd,MSG *Msg)
{
	if(Type==1)
	{
		if(Msg->hwnd==Wnd->GetSafeHwnd() && Msg->message==WM_KEYDOWN 
			&& (Msg->wParam<48 || Msg->wParam>57)&&(Msg->wParam<96 || Msg->wParam>105)&& Msg->wParam!=110  && Msg->wParam!=190  && Msg->wParam!=8 && Msg->wParam!=13 )
		{
			Msg->wParam=0x1d;//将响应更改为按下Ctrl键
		}

	}
}
/*主要功能:                                      
	测试ADO错误
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
