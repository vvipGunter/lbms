/* this file contains the actual definitions of */
/* the IIDs and CLSIDs */

/* link this file in with the server and any clients */


/* File created by MIDL compiler version 5.01.0164 */
/* at Fri Jun 25 17:52:59 2010
 */
/* Compiler settings for E:\gunter 6_25C++ͼ����Ϣ����ϵͳ[�ռ���]\lbms\gunterCode\Դ����.idl:
    Oicf (OptLev=i2), W1, Zp8, env=Win32, ms_ext, c_ext
    error checks: allocation ref bounds_check enum stub_data 
*/
//@@MIDL_FILE_HEADING(  )
#ifdef __cplusplus
extern "C"{
#endif 


#ifndef __IID_DEFINED__
#define __IID_DEFINED__

typedef struct _IID
{
    unsigned long x;
    unsigned short s1;
    unsigned short s2;
    unsigned char  c[8];
} IID;

#endif // __IID_DEFINED__

#ifndef CLSID_DEFINED
#define CLSID_DEFINED
typedef IID CLSID;
#endif // CLSID_DEFINED

const IID LIBID_MyLib = {0xCB720064,0x5988,0x11D8,{0x87,0x50,0x52,0x54,0xAB,0x32,0xC8,0xFB}};


#ifdef __cplusplus
}
#endif

