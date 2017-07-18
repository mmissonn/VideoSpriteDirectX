# Microsoft Visual C++ Generated NMAKE File, Format Version 2.00
# ** DO NOT EDIT **

# TARGTYPE "Win32 (x86) Static Library" 0x0104

!IF "$(CFG)" == ""
CFG=Win32 Debug
!MESSAGE No configuration specified.  Defaulting to Win32 Debug.
!ENDIF 

!IF "$(CFG)" != "Win32 Release" && "$(CFG)" != "Win32 Debug"
!MESSAGE Invalid configuration "$(CFG)" specified.
!MESSAGE You can specify a configuration when running NMAKE on this makefile
!MESSAGE by defining the macro CFG on the command line.  For example:
!MESSAGE 
!MESSAGE NMAKE /f "AVISprite.mak" CFG="Win32 Debug"
!MESSAGE 
!MESSAGE Possible choices for configuration are:
!MESSAGE 
!MESSAGE "Win32 Release" (based on "Win32 (x86) Static Library")
!MESSAGE "Win32 Debug" (based on "Win32 (x86) Static Library")
!MESSAGE 
!ERROR An invalid configuration is specified.
!ENDIF 

################################################################################
# Begin Project
# PROP Target_Last_Scanned "Win32 Debug"
CPP=cl.exe

!IF  "$(CFG)" == "Win32 Release"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 0
# PROP BASE Output_Dir "WinRel"
# PROP BASE Intermediate_Dir "WinRel"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 0
# PROP Output_Dir "WinRel"
# PROP Intermediate_Dir "WinRel"
OUTDIR=.\WinRel
INTDIR=.\WinRel

ALL : .\WinRel\AVISprite.lib .\WinRel\AVISprite.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

# ADD BASE CPP /nologo /W3 /GX /YX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /FR /c
# ADD CPP /nologo /W3 /GX /YX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS" /FR /c
CPP_PROJ=/nologo /W3 /GX /YX /O2 /D "WIN32" /D "NDEBUG" /D "_WINDOWS"\
 /FR$(INTDIR)/ /Fp$(OUTDIR)/"AVISprite.pch" /Fo$(INTDIR)/ /c 
CPP_OBJS=.\WinRel/
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"AVISprite.bsc" 
BSC32_SBRS= \
	.\WinRel\CLSID.SBR \
	.\WinRel\CAVISprite.sbr \
	.\WinRel\CAVIDDS.sbr \
	.\WinRel\CAVIDSS.sbr

.\WinRel\AVISprite.bsc : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LIB32=lib.exe
# ADD BASE LIB32 /NOLOGO
# ADD LIB32 /NOLOGO
LIB32_FLAGS=/NOLOGO /OUT:$(OUTDIR)\"AVISprite.lib" 
DEF_FLAGS=
DEF_FILE=
LIB32_OBJS= \
	.\WinRel\CLSID.OBJ \
	.\WinRel\CAVISprite.obj \
	.\WinRel\CAVIDDS.obj \
	.\WinRel\CAVIDSS.obj

.\WinRel\AVISprite.lib : $(OUTDIR)  $(DEF_FILE) $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
<<

!ELSEIF  "$(CFG)" == "Win32 Debug"

# PROP BASE Use_MFC 0
# PROP BASE Use_Debug_Libraries 1
# PROP BASE Output_Dir "WinDebug"
# PROP BASE Intermediate_Dir "WinDebug"
# PROP Use_MFC 0
# PROP Use_Debug_Libraries 1
# PROP Output_Dir "..\OBJ"
# PROP Intermediate_Dir "..\OBJ"
OUTDIR=..\OBJ
INTDIR=..\OBJ

ALL : \Projet\VisualFramework\AVISprite\OBJ\AVISprite.lib\
 \Projet\VisualFramework\AVISprite\OBJ\AVISprite.bsc

$(OUTDIR) : 
    if not exist $(OUTDIR)/nul mkdir $(OUTDIR)

# ADD BASE CPP /nologo /W3 /GX /Z7 /YX /Od /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FR /c
# ADD CPP /nologo /W3 /GX /Z7 /Od /I "..\INC" /D "WIN32" /D "_DEBUG" /D "_WINDOWS" /FR /c
# SUBTRACT CPP /YX
CPP_PROJ=/nologo /W3 /GX /Z7 /Od /I "..\INC" /D "WIN32" /D "_DEBUG" /D\
 "_WINDOWS" /FR$(INTDIR)/ /Fo$(INTDIR)/ /c 
CPP_OBJS=.\..\OBJ/
BSC32=bscmake.exe
# ADD BASE BSC32 /nologo
# ADD BSC32 /nologo
BSC32_FLAGS=/nologo /o$(OUTDIR)/"AVISprite.bsc" 
BSC32_SBRS= \
	\Projet\VisualFramework\AVISprite\OBJ\CLSID.SBR \
	\Projet\VisualFramework\AVISprite\OBJ\CAVISprite.sbr \
	\Projet\VisualFramework\AVISprite\OBJ\CAVIDDS.sbr \
	\Projet\VisualFramework\AVISprite\OBJ\CAVIDSS.sbr

\Projet\VisualFramework\AVISprite\OBJ\AVISprite.bsc : $(OUTDIR)  $(BSC32_SBRS)
    $(BSC32) @<<
  $(BSC32_FLAGS) $(BSC32_SBRS)
<<

LIB32=lib.exe
# ADD BASE LIB32 /NOLOGO
# ADD LIB32 /NOLOGO
LIB32_FLAGS=/NOLOGO /OUT:$(OUTDIR)\"AVISprite.lib" 
DEF_FLAGS=
DEF_FILE=
LIB32_OBJS= \
	\Projet\VisualFramework\AVISprite\OBJ\CLSID.OBJ \
	\Projet\VisualFramework\AVISprite\OBJ\CAVISprite.obj \
	\Projet\VisualFramework\AVISprite\OBJ\CAVIDDS.obj \
	\Projet\VisualFramework\AVISprite\OBJ\CAVIDSS.obj

\Projet\VisualFramework\AVISprite\OBJ\AVISprite.lib : $(OUTDIR)  $(DEF_FILE)\
 $(LIB32_OBJS)
    $(LIB32) @<<
  $(LIB32_FLAGS) $(DEF_FLAGS) $(LIB32_OBJS)
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

SOURCE=\Projet\VisualFramework\AVISprite\SRC\CLSID.CPP
DEP_CLSID=\
	\Projet\INC\HOSTENV.H\
	\Projet\INC\FrmwrkInterfaces.h

!IF  "$(CFG)" == "Win32 Release"

.\WinRel\CLSID.OBJ :  $(SOURCE)  $(DEP_CLSID) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Debug"

\Projet\VisualFramework\AVISprite\OBJ\CLSID.OBJ :  $(SOURCE)  $(DEP_CLSID)\
 $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Projet\VisualFramework\AVISprite\SRC\CAVISprite.cpp
DEP_CAVIS=\
	\GDK\sdk\inc\ddraw.h\
	\Projet\VisualFramework\AVISprite\INC\CAVISprite.h\
	\Projet\INC\HOSTENV.H\
	\Projet\INC\FrmwrkInterfaces.h\
	\Projet\VisualFramework\AVISprite\INC\AVISprite.h

!IF  "$(CFG)" == "Win32 Release"

.\WinRel\CAVISprite.obj :  $(SOURCE)  $(DEP_CAVIS) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Debug"

\Projet\VisualFramework\AVISprite\OBJ\CAVISprite.obj :  $(SOURCE)  $(DEP_CAVIS)\
 $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Projet\VisualFramework\AVISprite\SRC\CAVIDDS.cpp
DEP_CAVID=\
	\Projet\VisualFramework\AVISprite\INC\CAVIDDS.h\
	\Projet\INC\HOSTENV.H\
	\Projet\INC\FrmwrkInterfaces.h\
	\Projet\VisualFramework\AVISprite\INC\AVISprite.h\
	\GDK\sdk\inc\ddraw.h\
	\GDK\sdk\inc\dsound.h

!IF  "$(CFG)" == "Win32 Release"

.\WinRel\CAVIDDS.obj :  $(SOURCE)  $(DEP_CAVID) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Debug"

\Projet\VisualFramework\AVISprite\OBJ\CAVIDDS.obj :  $(SOURCE)  $(DEP_CAVID)\
 $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ENDIF 

# End Source File
################################################################################
# Begin Source File

SOURCE=\Projet\VisualFramework\AVISprite\SRC\CAVIDSS.cpp
DEP_CAVIDS=\
	\Projet\VisualFramework\AVISprite\INC\CAVIDSS.h\
	\Projet\INC\HOSTENV.H\
	\Projet\INC\FrmwrkInterfaces.h\
	\Projet\VisualFramework\AVISprite\INC\AVISprite.h\
	\GDK\sdk\inc\ddraw.h\
	\GDK\sdk\inc\dsound.h

!IF  "$(CFG)" == "Win32 Release"

.\WinRel\CAVIDSS.obj :  $(SOURCE)  $(DEP_CAVIDS) $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ELSEIF  "$(CFG)" == "Win32 Debug"

\Projet\VisualFramework\AVISprite\OBJ\CAVIDSS.obj :  $(SOURCE)  $(DEP_CAVIDS)\
 $(INTDIR)
   $(CPP) $(CPP_PROJ)  $(SOURCE) 

!ENDIF 

# End Source File
# End Group
# End Project
################################################################################
