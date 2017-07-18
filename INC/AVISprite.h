//=============================================================================
//						CORE VIDEO SPRITE TECHNOLOGY
//
//
//        HEADER: 	AVISprite.h
//
//        PURPOSE: 	AVI Video Sprite global definitions 
//
//				   
//		  AUTHOR:	Marc Missonnier 
//
//		  DATE:		october 1995
//
//        
//============================================================================


// Constructors -------------------------------------------------------------
HRESULT CreateAVISpriteFromAVI(LPTSTR szSrcFilename, LPTSTR szDestFilename, 
							LPAVISPRITEFILE* ppAVISpriteFile);

HRESULT AVISpriteFileOpen(LPTSTR szSrcFilename, LPAVISPRITEFILE* ppAVISpriteFile );

HRESULT CreateAVIDDSurfaceStream( PAVISTREAM pAVIStream, LPAVIDDSURFACESTREAM* ppAVIDDSurfaceStream );

HRESULT CreateAVIDirectSoundStream( PAVISTREAM pAVIStream, LPAVIDIRECTSOUNDSTREAM* ppAVIDirectSoundStream );



// Global defines -----------------------------------------------------------
#define streamtypePATH			mmioFOURCC('P', 'A', 'T', 'H') // FourCC for video path
#define streamtypeChromaKey		mmioFOURCC('C', 'K', 'E', 'Y') // FourCC for ChromaKeying

// A Path is a vector indicating displacement
typedef struct _AVIPATH 
{
	DWORD DeltaX;
	DWORD DeltaY;

} AVIPATH;
