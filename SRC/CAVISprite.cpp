//=============================================================================
//						CORE VIDEO SPRITE TECHNOLOGY
//
//
//        PROGRAM: CAVISprite.cpp
//
//        PURPOSE: AVI Sprite static library
//				   
//
//        FUNCTIONS:
// 				CreateAVISpriteFromAVI
//				AVISpriteFileOpen
//
//		  AUTHOR:	Marc Missonnier 
//
//		  DATE:		october 1995
//        
//============================================================================

// Includes ---------------------------------------------------------------------
#include "CAVISprite.h"		// AVI Sprite definition





//=============================================================================
//
//        FUNCTION: CreateAVISpriteFromAVI
//        PURPOSE: Create a new COM AVI Sprite File
//
//        COMMENTS:
//				Create an video sprite AVI File from an existing AVI File
//				
//
//
//============================================================================
HRESULT CreateAVISpriteFromAVI(LPTSTR szSrcFilename, LPTSTR szDestFilename, 
							LPAVISPRITEFILE* ppAVISpriteFile)
{
    HRESULT  	hr = NOERROR;
    CAVISprite*	pObj = NULL;
	
			
	// Create new encoder
	pObj = new CAVISprite();
	
 
    if( pObj != NULL )
	{
		hr = pObj->Initialize( szSrcFilename, szDestFilename );
		if( hr!= NOERROR )
			return hr;
	   	hr = pObj->QueryInterface( IID_IAVISpriteFile, (LPVOID*)ppAVISpriteFile );
	}
	else
		hr = E_OUTOFMEMORY;
	
	return hr;

    
}

//=============================================================================
//
//        FUNCTION: AVISpriteFileOpen
//        PURPOSE: Open an existing video sprite AVI in read Mode
//
//        COMMENTS:
//				
//				
//
//
//============================================================================
HRESULT AVISpriteFileOpen(LPTSTR szSrcFilename, LPAVISPRITEFILE* ppAVISpriteFile)
{

    HRESULT  	hr = NOERROR;
    CAVISprite*	pObj = NULL;
	
			
	// Create new video sprite from an existing AVI
	pObj = new CAVISprite();
	
 
    if( pObj != NULL )
	{
		hr = pObj->Initialize( szSrcFilename );
		if( hr!= NOERROR )
			return hr;
	   	hr = pObj->QueryInterface( IID_IAVISpriteFile, (LPVOID*)ppAVISpriteFile );
	}
	else
		hr = E_OUTOFMEMORY;
	
	return hr;

}



//=============================================================================
//
//        Class			: CAVISprite
//        PURPOSE		: Constructor 
//
//        COMMENTS:
//				Create a new AVI file with new capabilities given an existing
//				AVI File. 
//
//
//============================================================================
CAVISprite::CAVISprite() 
{  

	// Initialize interfaces
	m_cRef = 0;
	m_pAVIFile = NULL; 			// Pointer to an AVI file
	m_ChromaKeyStream = NULL;	// Chromakeying stream
	m_PathStream = NULL;


}


//=============================================================================
//
//        Class 		: CAVISprite::Initialize
//        PURPOSE		: Initialize an AVISprite 
//
//        COMMENTS:
//				Copy an existing AVI file to a new AVI sprite file
//				
//
//============================================================================
HRESULT CAVISprite::Initialize(LPTSTR szSrcFilename, LPTSTR szDestFilename)
{
													
	// Init AVIFile Library
	AVIFileInit();


	// Copy source AVI file to destination AVI file
	// overwrite destination if file exists
	BOOL Success = CopyFile( szSrcFilename, szDestFilename, FALSE );

	if( !Success )
		return E_FAIL;


	// Open the destination AVI
	HRESULT	hr = AVIFileOpen(&m_pAVIFile, szDestFilename, OF_READWRITE, NULL);	
	    
	return hr;


}


//=============================================================================
//
//        Class 		: CAVISprite::Initialize
//        PURPOSE		: Initialize an AVISprite 
//
//        COMMENTS:
//				Open an existing AVI Sprite file in read mode
//				
//
//============================================================================
HRESULT CAVISprite::Initialize(LPTSTR szSrcFilename)
{
	// Init AVIFile Library
	AVIFileInit();

	// Open an AVI sprite file
	HRESULT	hr = AVIFileOpen(&m_pAVIFile, szSrcFilename, OF_SHARE_DENY_WRITE | OF_READ, NULL);	
	    
	return hr;

}


//=============================================================================
//
//        Class			: CAVISprite
//        PURPOSE		: Destructor 
//
//        COMMENTS:
//				Clean up code
//				
//
//
//============================================================================
CAVISprite::~CAVISprite()
{


	// Close AVI destination file
	AVIFileRelease( m_pAVIFile );

	// Exits the AVIFile library 
	AVIFileExit();

}



//=============================================================================
//
//        Interface		: IUnknown::QueryInterface
//        PURPOSE		: Interface dispatching
//
//        COMMENTS:
//				See IUnknown::QueryInterface 
//				The object exposes the following interface :
//					IAVISpriteFile
//				
//
//
//============================================================================
STDMETHODIMP CAVISprite::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
	
    *ppvObj = NULL;

	if(riid == IID_IUnknown)// IUnknown interface
        *ppvObj=this;
    else if( riid == IID_IAVISpriteFile)
        	*ppvObj=this;
	else 
    	return E_NOINTERFACE;
		

    //AddRef any interface we'll return.
    ((LPUNKNOWN)*ppvObj)->AddRef();
    return NOERROR;

}

//=============================================================================
//
//        Interface		: IUnknown::AddRef
//        PURPOSE		: Interface dispatching
//
//        COMMENTS:
//				See IUnknown::AddRef()
//				
//
//
//============================================================================
STDMETHODIMP_(ULONG) CAVISprite::AddRef(void)
{
    return ++m_cRef;
}


//=============================================================================
//
//        Interface		: IUnknown::Release
//        PURPOSE		: Interface dispatching
//
//        COMMENTS:
//				See IUnknown::Release()
//				
//
//
//============================================================================
STDMETHODIMP_(ULONG) CAVISprite::Release(void)
{
    if (0!=--m_cRef)
        return m_cRef;

    delete this;
    return 0;

}


//=============================================================================
//
//        Interface		: IAVISpriteFile::Info
//        PURPOSE		: Call default handler implementation
//
//        COMMENTS:
//				See IAVIFile::Info
//				We use AVIFile API to let a Video for Windows handler 
//				take care of the job.
//
//
//============================================================================
STDMETHODIMP CAVISprite::Info( AVIFILEINFO* pfi, LONG lSize)
{
 	return AVIFileInfo( m_pAVIFile, pfi, lSize);
}

//=============================================================================
//
//        Interface		: IAVISpriteFile::GetStream
//        PURPOSE		: Call default handler implementation
//
//        COMMENTS:
//				See IAVIFile::GetStream
//
//
//============================================================================
STDMETHODIMP CAVISprite::GetStream( PAVISTREAM* ppStream, DWORD fccType, LONG lParam)
{
	return AVIFileGetStream( m_pAVIFile, ppStream, fccType, lParam);
}

//=============================================================================
//
//        Interface		: IAVISpriteFile::CreateStream
//        PURPOSE		: Call default handler implementation
//
//        COMMENTS:
//				See IAVIFile::CreateStream
//
//
//============================================================================
STDMETHODIMP CAVISprite::CreateStream( PAVISTREAM* ppStream, AVISTREAMINFO* psi)
{
	return AVIFileCreateStream( m_pAVIFile, ppStream, psi);
}

//=============================================================================
//
//        Interface		: IAVIFile::WriteData
//        PURPOSE		: Call default handler implementation
//
//        COMMENTS:
//				See IAVIFile::WriteData
//
//
//============================================================================
STDMETHODIMP CAVISprite::WriteData( DWORD ckid, LPVOID lpData, LONG cbData)
{
	return AVIFileWriteData( m_pAVIFile, ckid, lpData, cbData);
}

//=============================================================================
//
//        Interface		: IAVISpriteFile::ReadData
//        PURPOSE		: Call default handler implementation
//
//        COMMENTS:
//				See IAVIFile::ReadData
//
//
//============================================================================
STDMETHODIMP CAVISprite::ReadData( DWORD ckid, LPVOID lpData, LONG FAR *lpcbData)
{
	return AVIFileReadData( m_pAVIFile, ckid, lpData, lpcbData);
}

//=============================================================================
//
//        Interface		: IAVISpriteFile::EndRecord
//        PURPOSE		: Call default handler implementation
//
//        COMMENTS:
//				See IAVIFile::EndRecord
//
//
//============================================================================
STDMETHODIMP CAVISprite::EndRecord()
{
	return AVIFileEndRecord( m_pAVIFile ); 
}




//=============================================================================
//
//        Interface		: IAVISpriteFile::CreateChromaKeyStream
//        PURPOSE		: Create a new stream for chromakeying
//
//        COMMENTS:
//				Create a new stream inside an AVI file. The returned stream
//				is an AVISTREAM.
//
//
//============================================================================
STDMETHODIMP CAVISprite::CreateChromaKeyStream( PAVISTREAM* ppAVIStream, DWORD dwRate)
{
	
	// Create a new chroma key stream
	AVISTREAMINFO strhdr;

	// New chroma key stream
	// Fill chroma key stream header

	DDCOLORKEY ChromaKey = { 0, 0};
	DWORD dwChromaKeyFormat = sizeof(DDCOLORKEY);

	_fmemset(&strhdr, 0, sizeof(strhdr));
	strhdr.fccType                = streamtypeChromaKey;
	strhdr.fccHandler             = 0;
	strhdr.dwScale                = 1;
	strhdr.dwRate                 = dwRate;
	strhdr.dwSuggestedBufferSize  = dwChromaKeyFormat;

					
	HRESULT hr = AVIFileCreateStream(m_pAVIFile, &m_ChromaKeyStream, &strhdr);
	
	if (hr != AVIERR_OK) 
		return hr;


	// Set format for the chroma key stream 
	hr = AVIStreamSetFormat(m_ChromaKeyStream, 0, &ChromaKey, dwChromaKeyFormat);
	
	if (hr != AVIERR_OK) 
		return hr;

	*ppAVIStream = 	m_ChromaKeyStream;

	
	return NOERROR;
}


//=============================================================================
//
//        Interface		: IAVISpriteFile::CreatePathStream
//        PURPOSE		: Create a new stream for a sprite path
//
//        COMMENTS:
//				Create a new stream inside an AVI file. The returned stream
//				is an AVISTREAM.
//
//
//============================================================================
STDMETHODIMP CAVISprite::CreatePathStream( PAVISTREAM*  ppAVIStream, DWORD dwRate)
{

	// Create a video sprite path stream
	AVISTREAMINFO strhdr;

	// New path stream
	// Fill Path stream header
	DWORD dwVideoSpritePathFormat = 0;	

	AVIPATH VideoSpritePath = { 0, 0 };

	_fmemset(&strhdr, 0, sizeof(strhdr));
	strhdr.fccType                = streamtypePATH;
	strhdr.fccHandler             = 0;
	strhdr.dwScale                = 1;
	strhdr.dwRate                 = dwRate;
	strhdr.dwSuggestedBufferSize  = sizeof(AVIPATH);

					
	HRESULT hr = AVIFileCreateStream(m_pAVIFile, &m_PathStream, &strhdr);
	
	if (hr != AVIERR_OK) 
		return hr;


	// Set format for the path stream 
	dwVideoSpritePathFormat = sizeof(AVIPATH);
	
	hr = AVIStreamSetFormat(m_PathStream, 0, &VideoSpritePath, dwVideoSpritePathFormat);
	
	if (hr != AVIERR_OK) 
		return hr;
	
	*ppAVIStream = m_PathStream;


	return NOERROR;
}

//=============================================================================
//
//        Interface		: IAVISpriteFile::CreateDDSurfaceStream
//        PURPOSE		: Create a new stream for a DirectDraw surface
//
//        COMMENTS:
//				NOT IMPLEMENTED. Could be irrelevant
//
//
//============================================================================
STDMETHODIMP CAVISprite::CreateDDSurfaceStream( LPAVIDDSURFACESTREAM* ppAVIDDSurfaceStream, DWORD dwRate)
{
	return E_NOTIMPL;
}

//=============================================================================
//
//        Interface		: IAVISpriteFile::CreateDirectSoundStream
//        PURPOSE		: Create a new stream for a DirectSound object
//
//        COMMENTS:
//				NOT IMPLEMENTED.Could be irrelevant
//
//
//============================================================================
STDMETHODIMP CAVISprite::CreateDirectSoundStream( LPAVIDIRECTSOUNDSTREAM* ppAVIDSoundStream, DWORD dwRate)
{
	return E_NOTIMPL;
}

//=============================================================================
//
//        Interface		: IAVISpriteFile::GetChromaKeyStream
//        PURPOSE		: Get a chroma key stream inside an AVI file
//
//        COMMENTS:
//				Specify the stream number there could be more than one chromakey
//				stream.
//				
//
//
//============================================================================
STDMETHODIMP CAVISprite::GetChromaKeyStream( PAVISTREAM* ppAVIStream, DWORD dwNumber)
{
	return AVIFileGetStream(m_pAVIFile, ppAVIStream, streamtypeChromaKey, dwNumber);
}

//=============================================================================
//
//        Interface		: IAVISpriteFile::GetPathStream
//        PURPOSE		: Get a sprite path stream inside an AVI file
//
//        COMMENTS:
//				Specify the stream number there could be more than one sprite
//				path stream. Each sprite scenario could have a sprite path
//				stream.
//
//
//============================================================================
STDMETHODIMP CAVISprite::GetPathStream( PAVISTREAM* ppAVIStream, DWORD dwNumber)
{
	return AVIFileGetStream(m_pAVIFile, ppAVIStream, streamtypePATH, dwNumber);
}

//=============================================================================
//
//        Interface		: IAVISpriteFile::GetDDSurfaceStream
//        PURPOSE		: Get a DirectDraw surface stream inside an AVI file
//
//        COMMENTS:
//				Look for a video stream that is specialized with DirectDraw.
//				Specify the stream number there could be more than one video stream.
// 
//
//
//
//============================================================================
STDMETHODIMP CAVISprite::GetDDSurfaceStream( LPAVIDDSURFACESTREAM* ppAVIDDSurfaceStream, DWORD dwNumber)
{

	PAVISTREAM pAVIStream;
		
	// Get a video stream
	HRESULT hr = AVIFileGetStream(m_pAVIFile, &pAVIStream, streamtypeVIDEO, dwNumber );

	if( hr != AVIERR_OK )
		return hr;
	
	// Create an AVI surface stream from an existing video stream
	return CreateAVIDDSurfaceStream( pAVIStream, ppAVIDDSurfaceStream );
	

}


//=============================================================================
//
//        Interface		: IAVISpriteFile::GetDirectSoundStream
//        PURPOSE		: Get a DirectSound stream inside an AVI file
//
//        COMMENTS:
//				Look for an audio stream that is specialized with DirectSound.
//				Specify the stream number there could be more than one audio stream.
// 
//
//
//
//============================================================================
STDMETHODIMP CAVISprite::GetDirectSoundStream( LPAVIDIRECTSOUNDSTREAM* ppAVIDSoundStream, DWORD dwNumber)
{

	PAVISTREAM pAVIStream;
		
	// Get an audio stream
	HRESULT hr = AVIFileGetStream(m_pAVIFile, &pAVIStream, streamtypeAUDIO, dwNumber );

	if( hr != AVIERR_OK )
		return hr;
	
	// Create an AVI direct sound stream from an existing audio stream
	return CreateAVIDirectSoundStream( pAVIStream, ppAVIDSoundStream );

}







//******************************************************************************************

	// Create a destination AVI file
	//hr = AVIFileOpen(&m_pDestfile, szDestFilename, OF_WRITE | OF_CREATE, NULL);	
	    
	//if (hr != AVIERR_OK)
	//	return;

	//BYTE* lpFormat = NULL;			// Pointer to a stream format structure
	//LONG cbFormat = 0;				// Size of format structure


	//PAVISTREAM lpDestStream = NULL;		// Pointer to IStream interface for a destination stream
	//PAVISTREAM lpEditStream = NULL; 	// Pointer to IStream interface for an editable stream
	//AVISTREAMINFO StreamInfo;			// Information about stream

		// Create destination stream
		//AVIFileCreateStream( m_pDestfile, &lpDestStream, &StreamInfo);

		//CreateEditableStream( &lpEditStream, lpSrcStream);

		//EditStreamClone(lpEditStream, &lpDestStream);


		   // Get stream header
    	//AVIStreamInfo(lpSrcStream, &StreamInfo, sizeof(StreamInfo)); 

		// Read format and data from stream
		//AVIStreamReadFormat(lpSrcStream, AVIStreamStart(lpSrcStream), NULL, &cbFormat);
		//lpFormat = new BYTE[cbFormat];
		//AVIStreamReadFormat(lpSrcStream, AVIStreamStart(lpSrcStream), lpFormat, &cbFormat);

		//AVIStreamRead(lpSrcStream, 0, LONG lSamples, 
    //LPVOID lpBuffer, LONG cbBuffer, LONG FAR * plBytes, 
    //LONG FAR * plSamples);

		// Write format and data in destination stream
		//AVIStreamSetFormat(lpDestStream, 0, lpFormat, cbFormat);
		//delete lpFormat;

		//AVIStreamWrite(lpDestStream, 0, LONG lSamples, 
    //LPVOID lpBuffer, LONG cbBuffer, DWORD dwFlags, 
    //LONG FAR * plSampWritten, LONG FAR * plBytesWritten);
	


	/*
	// Open an existing AVI source file
	hr = AVIFileOpen(&pfile, szSrcFilename, OF_READ | OF_SHARE_DENY_WRITE, NULL);

	if (hr != AVIERR_OK)
		return;


	PAVISTREAM lpSrcStream[MAXSTREAM]; 					// Array of Streams 
	int nStreams = 0;									// Number of streams in source file
	LPAVICOMPRESSOPTIONS lpCompressOptions[MAXSTREAM]; 	// Array of AVICOMPRESSOPTIONS

    // Get all the streams from the source file
	for( int i = 0; i++; (hr == AVIERR_OK) & (i < MAXSTREAM) )
	{    
		// Access any FourCC
    	hr = AVIFileGetStream( pFile, &lpSrcStream[i], 0, i++ );

	}

	nStreams = i;


	// Fill the compress option array
	// ....

	// Clone the source file
	AVISaveV( szDestFilename, NULL, NULL, nStreams, lpSrcStream, lpCompressOptions);


	// Release all the source streams
	for( i = 0; i++; i < nStreams)
		AVIStreamRelease( lpSrcStream[i] );


	// Open the destination AVI
	hr = AVIFileOpen(&m_pDestfile, szDestFilename, OF_WRITE, NULL);	
	    
	if (hr != AVIERR_OK)
		return;


	// Create new streams with the given capabilities 

	
		


	// Close AVI source file
	AVIFileRelease( pFile );
	*/
