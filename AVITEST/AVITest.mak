# Microsoft Visual C++ Generated NMAKE File, Format Version 2.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Application" 0x0101

!IF "$(CFG)" == ""
CFG=Win32 Debug
!MESSAGE No configuration specified.  Defaulting to Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Win32 Debug" && "$(CFG)" != "Win32 Release"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "AVITest.mak" CFG="Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Win32 Debug" (based on "Win32 (x86) Application")
!MESSAGE "Win32 Release" (based on "Win32 (x86) Application")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

################################################################################
# Begin Project
# PROP Target_Last_Scanned "Win32 Debug"
MTL=MkTypLib.exe
CPP=cl.exe
RSC=rc.exe

!IF  "$(CFG)" == "Win32 Debug"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WinDebug"
# PROP BASE Intermediate_Dir "WinDebug"
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "WinDebug"
# PROP Intermediate_Dir "WinDebug"
OUTDIR=.\WinDebug
INTDIR=.\WinDebug

ALL : MTL_TLBS .\WinDebug\AVITest.exe .\WinDebug\AVITest.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

# ADD BASE MTL /nologo /D "_DEBUG" /win32
# ADD MTL /nologo /D "_DEBUG" /win32
MTL_PROJ=/nologo /D "_DEBUG" /win32 

MTL_TLBS : .\WinDebug\AVITest.tlb
# ADD BASE CPP /nologo /MD /W3 /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MD /W3 /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_MBCS" /D "_AFXDLL" /FR$(INTDIR)/ /Fp$(OUTDIR)/"AVITest.pch" /Yu"stdafx.h"\
 /Fo$(INTDIR)/ /Fd$(OUTDIR)/"AVITest.pdb" /c 
CPP_OBJS=.\WinDebug/
# ADD BASE RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "_DEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo$(INTDIR)/"AVITest.res" /d "_DEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"AVITest.bsc" 
BSC32_SBRS= \
	.\WinDebug\stdafx.sbr \
	.\WinDebug\AVITest.sbr \
	.\WinDebug\mainfrm.sbr \
	.\WinDebug\AVITedoc.sbr \
	.\WinDebug\AVITevw.sbr \
	.\WinDebug\cntritem.sbr

.\WinDebug\AVITest.bsc : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 /NOLOGO /SUBSYSTEM:windows /DEBUG /MACHINE:I386
# SUBTRACT BASE LINK32 /PDB:none
# ADD LINK32 ..\obj\AVISprite.lib vfw32.lib winmm.lib /NOLOGO /SUBSYSTEM:windows /DEBUG /MACHINE:I386
# SUBTRACT LINK32 /PDB:none
LINK32_FLAGS=..\obj\AVISprite.lib vfw32.lib winmm.lib /NOLOGO\
 /SUBSYSTEM:windows /INCREMENTAL:yes /PDB:$(OUTDIR)/"AVITest.pdb" /DEBUG\
 /MACHINE:I386 /OUT:$(OUTDIR)/"AVITest.exe" 
DEF_FILE=
LINK32_OBJS= \
	.\WinDebug\stdafx.obj \
	.\WinDebug\AVITest.obj \
	.\WinDebug\mainfrm.obj \
	.\WinDebug\AVITedoc.obj \
	.\WinDebug\AVITevw.obj \
	.\WinDebug\cntritem.obj \
	.\WinDebug\AVITest.res

.\WinDebug\AVITest.exe : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Win32 Release"

# PROP BASE Use_MFC 6
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WinRel"
# PROP BASE Intermediate_Dir "WinRel"
# PROP Use_MFC 6
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "WinRel"
# PROP Intermediate_Dir "WinRel"
OUTDIR=.\WinRel
INTDIR=.\WinRel

ALL : MTL_TLBS .\WinRel\AVITest.exe .\WinRel\AVITest.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

# ADD BASE MTL /nologo /D "NDEBUG" /win32
# ADD MTL /nologo /D "NDEBUG" /win32
MTL_PROJ=/nologo /D "NDEBUG" /win32 

MTL_TLBS : .\WinRel\AVITest.tlb
# ADD BASE CPP /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /c
# ADD CPP /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D "_MBCS" /D "_AFXDLL" /FR /Yu"stdafx.h" /c
CPP_PROJ=/nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_MBCS" /D "_AFXDLL" /FR$(INTDIR)/ /Fp$(OUTDIR)/"AVITest.pch" /Yu"stdafx.h"\
 /Fo$(INTDIR)/ /c 
CPP_OBJS=.\WinRel/
# ADD BASE RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
# ADD RSC /l 0x409 /d "NDEBUG" /d "_AFXDLL"
RSC_PROJ=/l 0x409 /fo$(INTDIR)/"AVITest.res" /d "NDEBUG" /d "_AFXDLL" 
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"AVITest.bsc" 
BSC32_SBRS= \
	.\WinRel\stdafx.sbr \
	.\WinRel\AVITest.sbr \
	.\WinRel\mainfrm.sbr \
	.\WinRel\AVITedoc.sbr \
	.\WinRel\AVITevw.sbr \
	.\WinRel\cntritem.sbr

.\WinRel\AVITest.bsc : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LINK32=link.exe
# ADD BASE LINK32 /NOLOGO /SUBSYSTEM:windows /MACHINE:I386
# SUBTRACT BASE LINK32 /PDB:none
# ADD LINK32 /NOLOGO /SUBSYSTEM:windows /MACHINE:I386
# SUBTRACT LINK32 /PDB:none
LINK32_FLAGS=/NOLOGO /SUBSYSTEM:windows /INCREMENTAL:no\
 /PDB:$(OUTDIR)/"AVITest.pdb" /MACHINE:I386 /OUT:$(OUTDIR)/"AVITest.exe" 
DEF_FILE=
LINK32_OBJS= \
	.\WinRel\stdafx.obj \
	.\WinRel\AVITest.obj \
	.\WinRel\mainfrm.obj \
	.\WinRel\AVITedoc.obj \
	.\WinRel\AVITevw.obj \
	.\WinRel\cntritem.obj \
	.\WinRel\AVITest.res

.\WinRel\AVITest.exe : $(OUTDIR)  $(DEF_FILE) $(LINK32_OBJS)
    $(LINK32) @<<
  $(LINK32_FLAGS) $(LINK32_OBJS)
<<

!ENDIF 

.c{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cpp{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

.cxx{$(CPP_OBJS)}.obj:
   $(CPP) $(CPP_PROJ) $<  

################################################################################
# Begin Group "Source Files"

################################################################################
# Begin Source File

SOURCE=.\stdafx.cpp
DEP_STDAF=\
	.\stdafx.h

!IF  "$(CFG)" == "Win32 Debug"

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

.\WinDebug\stdafx.obj :  $(SOURCE)  $(DEP_STDAF) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /Zi /Od /D "_DEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_MBCS" /D "_AFXDLL" /FR$(INTDIR)/ /Fp$(OUTDIR)/"AVITest.pch" /Yc"stdafx.h"\
 /Fo$(INTDIR)/ /Fd$(OUTDIR)/"AVITest.pdb" /c  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Release"

# ADD BASE CPP /Yc"stdafx.h"
# ADD CPP /Yc"stdafx.h"

.\WinRel\stdafx.obj :  $(SOURCE)  $(DEP_STDAF) $(INTDIR)
   $(CPP) /nologo /MD /W3 /GX /O2 /D "NDEBUG" /D "WIN32" /D "_WINDOWS" /D\
 "_MBCS" /D "_AFXDLL" /FR$(INTDIR)/ /Fp$(OUTDIR)/"AVITest.pch" /Yc"stdafx.h"\
 /Fo$(INTDIR)/ /c  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\AVITest.cpp
DEP_AVITE=\
	.\stdafx.h\
	.\AVITest.h\
	.\mainfrm.h\
	.\AVITedoc.h\
	.\AVITevw.h

!IF  "$(CFG)" == "Win32 Debug"

.\WinDebug\AVITest.obj :  $(SOURCE)  $(DEP_AVITE) $(INTDIR)\
 .\WinDebug\stdafx.obj

!ELSEIF  "$(CFG)" == "Win32 Release"

.\WinRel\AVITest.obj :  $(SOURCE)  $(DEP_AVITE) $(INTDIR) .\WinRel\stdafx.obj

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\mainfrm.cpp
DEP_MAINF=\
	.\stdafx.h\
	.\AVITest.h\
	.\mainfrm.h

!IF  "$(CFG)" == "Win32 Debug"

.\WinDebug\mainfrm.obj :  $(SOURCE)  $(DEP_MAINF) $(INTDIR)\
 .\WinDebug\stdafx.obj

!ELSEIF  "$(CFG)" == "Win32 Release"

.\WinRel\mainfrm.obj :  $(SOURCE)  $(DEP_MAINF) $(INTDIR) .\WinRel\stdafx.obj

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\AVITedoc.cpp
DEP_AVITED=\
	.\stdafx.h\
	.\AVITest.h\
	.\AVITedoc.h\
	.\cntritem.h\
	\projet\INC\Hostenv.h\
	\projet\INC\FrmwrkInterfaces.h\
	..\inc\AVISprite.h\
	\gdk\sdk\inc\ddraw.h

!IF  "$(CFG)" == "Win32 Debug"

.\WinDebug\AVITedoc.obj :  $(SOURCE)  $(DEP_AVITED) $(INTDIR)\
 .\WinDebug\stdafx.obj

!ELSEIF  "$(CFG)" == "Win32 Release"

.\WinRel\AVITedoc.obj :  $(SOURCE)  $(DEP_AVITED) $(INTDIR) .\WinRel\stdafx.obj

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\AVITevw.cpp
DEP_AVITEV=\
	.\stdafx.h\
	.\AVITest.h\
	.\AVITedoc.h\
	.\cntritem.h\
	.\AVITevw.h

!IF  "$(CFG)" == "Win32 Debug"

.\WinDebug\AVITevw.obj :  $(SOURCE)  $(DEP_AVITEV) $(INTDIR)\
 .\WinDebug\stdafx.obj

!ELSEIF  "$(CFG)" == "Win32 Release"

.\WinRel\AVITevw.obj :  $(SOURCE)  $(DEP_AVITEV) $(INTDIR) .\WinRel\stdafx.obj

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\cntritem.cpp
DEP_CNTRI=\
	.\stdafx.h\
	.\AVITest.h\
	.\AVITedoc.h\
	.\cntritem.h

!IF  "$(CFG)" == "Win32 Debug"

.\WinDebug\cntritem.obj :  $(SOURCE)  $(DEP_CNTRI) $(INTDIR)\
 .\WinDebug\stdafx.obj

!ELSEIF  "$(CFG)" == "Win32 Release"

.\WinRel\cntritem.obj :  $(SOURCE)  $(DEP_CNTRI) $(INTDIR) .\WinRel\stdafx.obj

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\AVITest.rc
DEP_AVITES=\
	.\res\AVITest.ico\
	.\res\AVITedoc.ico\
	.\res\toolbar.bmp\
	.\res\AVITest.rc2

!IF  "$(CFG)" == "Win32 Debug"

.\WinDebug\AVITest.res :  $(SOURCE)  $(DEP_AVITES) $(INTDIR)
   $(RSC) /l 0x409 /fo$(INTDIR)/"AVITest.res" /i "$(OUTDIR)" /d "_DEBUG" /d\
 "_AFXDLL"  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Release"

.\WinRel\AVITest.res :  $(SOURCE)  $(DEP_AVITES) $(INTDIR)
   $(RSC) /l 0x409 /fo$(INTDIR)/"AVITest.res" /i "$(OUTDIR)" /d "NDEBUG" /d\
 "_AFXDLL"  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=.\readme.txt
# End Source File
################################################################################
# Begin Source File

SOURCE=.\AVITest.odl

!IF  "$(CFG)" == "Win32 Debug"

.\WinDebug\AVITest.tlb :  $(SOURCE)  $(OUTDIR)
   $(MTL) /nologo /D "_DEBUG" /tlb $(OUTDIR)/"AVITest.tlb" /win32  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Release"

.\WinRel\AVITest.tlb :  $(SOURCE)  $(OUTDIR)
   $(MTL) /nologo /D "NDEBUG" /tlb $(OUTDIR)/"AVITest.tlb" /win32  $(SOURCE) 

!ENDIF 

# End Source File
# End Group
# End Project
################################################################################
