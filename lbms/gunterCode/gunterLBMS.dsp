# Microsoft Developer Studio Project File - Name="源程序" - Package Owner=<4>
# Microsoft Developer Studio Generated Build File, Format Version 6.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

CFG=源程序 - Win32 Debug
!MESSAGE This is not a valid makefile. To build this project using NMAKE,
!MESSAGE use the Export Makefile command and run
!MESSAGE 
!MESSAGE NMAKE /f "gunterLBMS.mak".
!MESSAGE 
!MESSAGE You can specify a configuration when running NMAKE
!MESSAGE by defining the macro CFG on the command line. For example:
!MESSAGE 
!MESSAGE NMAKE /f "gunterLBMS.mak" CFG="源程序 - Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "源程序 - Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE "源程序 - Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE 

# Begin Project
# PROP AllowPerConfigDependencies 0
# PROP Scc_ProjName ""
# PROP Scc_LocalPath ""
CPP=cl.exe
MTL=midl.exe
RSC=rc.exe

!IF  "$(CFG)" == "源程序 - Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "Release"
# PROP BASE Intermediate_Dir "Release"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "Release"
# PROP Intermediate_Dir "Release"
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /Yu"stdafx.h" /FD /c
# ADD BASE MTL /nologo /D "NDEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "NDEBUG" /win32
# ADD BASE RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /d "NDEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /machine:I386
# ADD LINK32 /nologo /subsystem:windows /machine:I386

!ELSEIF  "$(CFG)" == "源程序 - Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "Debug"
# PROP BASE Intermediate_Dir "Debug"
# PROP BASE Target_Dir ""
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "Debug"
# PROP Intermediate_Dir "Debug"
# PROP Ignore_Export_Lib 0
# PROP Target_Dir ""
# ADD BASE CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /Yu"stdafx.h" /FD /GZ /c
# ADD CPP /nologo /MDd /W3 /Gm /GX /ZI /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /D "_AFXDLL" /D "_MBCS" /FR /Yu"stdafx.h" /FD /GZ /c
# ADD BASE MTL /nologo /D "_DEBUG" /mktyplib203 /win32
# ADD MTL /nologo /D "_DEBUG" /win32
# ADD BASE RSC /l 0x804 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x804 /fo"Debug/gunterLBMS.res" /d "_DEBUG" /d "_AFXDLL"
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
LINK32=link.exe
# ADD BASE LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept
# ADD LINK32 /nologo /subsystem:windows /debug /machine:I386 /pdbtype:sept

!ENDIF 

# Begin Target

# Name "源程序 - Win32 Release"
# Name "源程序 - Win32 Debug"
# Begin Group "Source Files"

# PROP Default_Filter "cpp;c;cxx;rc;def;r;odl;idl;hpj;bat"
# Begin Source File

SOURCE=.\DBSlider.cpp
# End Source File
# Begin Source File

SOURCE=.\Dlg.cpp
# End Source File
# Begin Source File

SOURCE=.\Dlogin.cpp
# End Source File
# Begin Source File

SOURCE=.\DUser.cpp
# End Source File
# Begin Source File

SOURCE=.\Duty.cpp
# End Source File
# Begin Source File

SOURCE=.\IDD_books.cpp
# End Source File
# Begin Source File

SOURCE=.\Main.cpp
# End Source File
# Begin Source File

SOURCE=.\opbooks.cpp
# End Source File
# Begin Source File

SOURCE=.\outin.cpp
# End Source File
# Begin Source File

SOURCE=.\RainFunction.cpp
# End Source File
# Begin Source File

SOURCE=.\RainFunction.h
# End Source File
# Begin Source File

SOURCE=.\RecordComboBox.cpp
# End Source File
# Begin Source File

SOURCE=.\RecordEditBox.cpp
# End Source File
# Begin Source File

SOURCE=.\RecordList.cpp
# End Source File
# Begin Source File

SOURCE=.\RxButton.cpp
# End Source File
# Begin Source File

SOURCE=.\StdAfx.cpp
# ADD CPP /Yc"stdafx.h"
# End Source File
# Begin Source File

SOURCE=.\usersrights.cpp
# End Source File
# Begin Source File

SOURCE=".\源程序.cpp"
# End Source File
# Begin Source File

SOURCE=".\源程序.idl"
# ADD MTL /h "源程序_i.h" /iid "源程序_i.c" /Oicf
# End Source File
# Begin Source File

SOURCE=".\源程序.rc"
# End Source File
# End Group
# Begin Group "Header Files"

# PROP Default_Filter "h;hpp;hxx;hm;inl"
# Begin Source File

SOURCE=.\Clime.h
# End Source File
# Begin Source File

SOURCE=.\DBSlider.h
# End Source File
# Begin Source File

SOURCE=.\Dlg.h
# End Source File
# Begin Source File

SOURCE=.\Dlogin.h
# End Source File
# Begin Source File

SOURCE=.\DMessage.h
# End Source File
# Begin Source File

SOURCE=.\DUser.h
# End Source File
# Begin Source File

SOURCE=.\Duty.h
# End Source File
# Begin Source File

SOURCE=.\IDD_books.h
# End Source File
# Begin Source File

SOURCE=.\Main.h
# End Source File
# Begin Source File

SOURCE=.\opbooks.h
# End Source File
# Begin Source File

SOURCE=.\outin.h
# End Source File
# Begin Source File

SOURCE=.\RecordComboBox.h
# End Source File
# Begin Source File

SOURCE=.\RecordEditBox.h
# End Source File
# Begin Source File

SOURCE=.\RecordList.h
# End Source File
# Begin Source File

SOURCE=.\Resource.h
# End Source File
# Begin Source File

SOURCE=.\RxButton.h
# End Source File
# Begin Source File

SOURCE=.\StdAfx.h
# End Source File
# Begin Source File

SOURCE=.\usersrights.h
# End Source File
# Begin Source File

SOURCE=".\源程序.h"
# End Source File
# End Group
# Begin Group "Resource Files"

# PROP Default_Filter "ico;cur;bmp;dlg;rc2;rct;bin;rgs;gif;jpg;jpeg;jpe"
# Begin Source File

SOURCE=.\Bmp\1.bmp
# End Source File
# Begin Source File

SOURCE=.\11.bmp
# End Source File
# Begin Source File

SOURCE=.\12.bmp
# End Source File
# Begin Source File

SOURCE=.\Bmp\2.bmp
# End Source File
# Begin Source File

SOURCE=.\21.bmp
# End Source File
# Begin Source File

SOURCE=.\22.bmp
# End Source File
# Begin Source File

SOURCE=.\Bmp\3.bmp
# End Source File
# Begin Source File

SOURCE=.\31.bmp
# End Source File
# Begin Source File

SOURCE=.\32.bmp
# End Source File
# Begin Source File

SOURCE=.\Bmp\4.bmp
# End Source File
# Begin Source File

SOURCE=.\41.bmp
# End Source File
# Begin Source File

SOURCE=.\42.bmp
# End Source File
# Begin Source File

SOURCE=.\Bmp\5.bmp
# End Source File
# Begin Source File

SOURCE=.\51.bmp
# End Source File
# Begin Source File

SOURCE=.\52.bmp
# End Source File
# Begin Source File

SOURCE=.\Bmp\6.bmp
# End Source File
# Begin Source File

SOURCE=.\61.bmp
# End Source File
# Begin Source File

SOURCE=.\62.bmp
# End Source File
# Begin Source File

SOURCE=.\res\99.bmp
# End Source File
# Begin Source File

SOURCE=.\Bmp\abc.bmp
# End Source File
# Begin Source File

SOURCE=.\Bmp\Add.bmp
# End Source File
# Begin Source File

SOURCE=.\BMP\bgPic.bmp
# End Source File
# Begin Source File

SOURCE=.\Bmp\BLACK.bmp
# End Source File
# Begin Source File

SOURCE=.\Bmp\Close.bmp
# End Source File
# Begin Source File

SOURCE=.\Close.bmp
# End Source File
# Begin Source File

SOURCE=.\res\cursor1.cur
# End Source File
# Begin Source File

SOURCE=.\BMP\DOWN.bmp
# End Source File
# Begin Source File

SOURCE=.\BMP\gcxy.bmp
# End Source File
# Begin Source File

SOURCE=.\BMP\gunter.bmp
# End Source File
# Begin Source File

SOURCE=.\icon1.ico
# End Source File
# Begin Source File

SOURCE=.\icon2.ico
# End Source File
# Begin Source File

SOURCE=.\icon3.ico
# End Source File
# Begin Source File

SOURCE=.\icon4.ico
# End Source File
# Begin Source File

SOURCE=.\res\icon4.ico
# End Source File
# Begin Source File

SOURCE=.\logo.bmp
# End Source File
# Begin Source File

SOURCE=.\Bmp\Min.bmp
# End Source File
# Begin Source File

SOURCE=.\Min.bmp
# End Source File
# Begin Source File

SOURCE=.\BMP\MOVE.bmp
# End Source File
# Begin Source File

SOURCE=.\BMP\NONAL.bmp
# End Source File
# Begin Source File

SOURCE=.\BMP\OPDOWN.bmp
# End Source File
# Begin Source File

SOURCE=.\BMP\OPNONAL.bmp
# End Source File
# Begin Source File

SOURCE=.\PENCIL.ICO
# End Source File
# Begin Source File

SOURCE=.\Bmp\User.bmp
# End Source File
# Begin Source File

SOURCE=.\BMP\zw.bmp
# End Source File
# Begin Source File

SOURCE=".\帮助.ico"
# End Source File
# Begin Source File

SOURCE=".\BMP\客户信息管理系统.bmp"
# End Source File
# Begin Source File

SOURCE=".\客户职务管理.bmp"
# End Source File
# Begin Source File

SOURCE=".\库存查询.ico"
# End Source File
# Begin Source File

SOURCE=".\销售查询.ico"
# End Source File
# Begin Source File

SOURCE=".\res\源程序.ico"
# End Source File
# Begin Source File

SOURCE=".\res\源程序.rc2"
# End Source File
# Begin Source File

SOURCE=".\源程序.rgs"
# End Source File
# End Group
# Begin Source File

SOURCE=.\Debug\MSADO15.tlh
# End Source File
# Begin Source File

SOURCE=.\ReadMe.txt
# End Source File
# End Target
# End Project
# Section 源程序 : {00000000-0000-0000-0000-000000000000}
# 	1:6:IDR_MY:103
# End Section
