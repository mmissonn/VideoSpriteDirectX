//=============================================================================
//						CORE VIDEO SPRITE TECHNOLOGY
//
//        PROGRAM: 	CAVIDSS.cpp
//
//        PURPOSE: 	AVI Sprite static library
//
//        FUNCTIONS:
// 					CreateAVIDirectSoundStream
//
//		  AUTHOR:	Marc Missonnier 
//
//		  DATE:		october 1995
//
//        
//============================================================================

// Includes ---------------------------------------------------------------------
#include "CAVIDSS.h"		// AVI DirectSound stream definition



  


//=============================================================================
//
//        FUNCTION: CreateAVIDirectSoundStream
//        PURPOSE: Create a new COM AVI DirectSound buffer stream
//
//        COMMENTS:
//				Create a DirectSound stream from an audio stream
//				
//
//
//============================================================================
HRESULT CreateAVIDirectSoundStream( PAVISTREAM pAVIStream, LPAVIDIRECTSOUNDSTREAM* ppAVIDirectSoundStream )
{
    HRESULT  	hr = NOERROR;
    CAVIDirectSoundStream*	pObj = NULL;

	
			
	// Create new stream
	pObj = new CAVIDirectSoundStream( pAVIStream ); 
	
 
    if( pObj != NULL )
	   	hr = pObj->QueryInterface( IID_IAVIDirectSoundStream, (LPVOID*)ppAVIDirectSoundStream );
	else
		hr = E_OUTOFMEMORY;
	
	return hr;

    
}




//=============================================================================
//
//        Class			: CAVIDirectSoundStream
//        PURPOSE		: Constructor
//
//        COMMENTS:
//				Initialize the video stream used for delegation
//
//
//============================================================================
CAVIDirectSoundStream::CAVIDirectSoundStream(PAVISTREAM pAVIStream)
{  

	// Initialize video stream for delegation by containment
	m_cRef = 0;
	m_pAudioStream = pAVIStream;
	


}




//=============================================================================
//
//        Class			: CAVIDirectSoundStream
//        PURPOSE		: Destructor
//
//        COMMENTS:
//				Clean up code.
//
//
//============================================================================
CAVIDirectSoundStream::~CAVIDirectSoundStream()
{
	if( m_pAudioStream )
		m_pAudioStream->Release();

	if( m_lpDirectSoundBuffer )
		m_lpDirectSoundBuffer->Release();

}



//=============================================================================
//
//        Interface		: IUnknown::QueryInterface
//        PURPOSE		: Interface dispatching
//
//        COMMENTS:
//				See IUnknown::QueryInterface
//				The object exposes the following interface :
//					IAVIDirectSoundStream
//				
//
//
//============================================================================
STDMETHODIMP CAVIDirectSoundStream::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
	
    *ppvObj = NULL;

	if(riid == IID_IUnknown)// IUnknown interface
        *ppvObj=this;
    else if( riid == IID_IAVIDirectSoundStream)
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
//				See IUnknown::AddRef
//				
//
//
//============================================================================
STDMETHODIMP_(ULONG) CAVIDirectSoundStream::AddRef(void)
{
    return ++m_cRef;
}

//=============================================================================
//
//        Interface		: IUnknown::Release
//        PURPOSE		: Interface dispatching
//
//        COMMENTS:
//				See IUnknown::Release
//				
//
//
//============================================================================
STDMETHODIMP_(ULONG) CAVIDirectSoundStream::Release(void)
{
    if (0!=--m_cRef)
        return m_cRef;

    delete this;
    return 0;

}


//=============================================================================
//
//        Interface		: IAVIDirectSoundStream::Create
//        PURPOSE		: Call default handler implementation
//
//        COMMENTS:	
//				See IAVIStream::Create	
//				Wrap IAVIStream interface and delegate to the audio stream.
//
//
//============================================================================
STDMETHODIMP CAVIDirectSoundStream::Create( long lParam1, long lParam2)
{
	return 	m_pAudioStream->Create( lParam1, lParam2);
}


//=============================================================================
//
//        Interface		: IAVIDirectSoundStream::Delete
//        PURPOSE		: Call default handler implementation
//
//        COMMENTS:	
//				See IAVIStream::Delete
//
//
//============================================================================
STDMETHODIMP CAVIDirectSoundStream::Delete( long lStart, long lSamples)
{
	return 	m_pAudioStream->Delete( lStart, lSamples);
}

//=============================================================================
//
//        Interface		: IAVIDirectSoundStream::Info
//        PURPOSE		: Call default handler implementation
//
//        COMMENTS:	
//				See IAVIStream::Info
//
//
//============================================================================
STDMETHODIMP CAVIDirectSoundStream::Info( AVISTREAMINFO* psi, long lSize)
{
	
	if( AVIStreamInfo(m_pAudioStream, psi, lSize) )
		return E_FAIL;
	else
		return NOERROR;
}

//=============================================================================
//
//        Interface		: IAVIDirectSoundStream::FindSample
//        PURPOSE		: Call default handler implementation
//
//        COMMENTS:	
//				See IAVIStream::FindSample
//
//
//============================================================================
STDMETHODIMP CAVIDirectSoundStream::FindSample( long lPos, long lFlags, long FAR* lPosFound)
{
	*lPosFound = m_pAudioStream->FindSample( lPos, lFlags );

	if( *lPosFound == -1 )
		return E_FAIL;
	else
		return NOERROR;
}


//=============================================================================
//
//        Interface		: IAVIDirectSoundStream::Read
//        PURPOSE		: Call default handler implementation
//
//        COMMENTS:	
//				See IAVIStream::Read
//
//
//============================================================================
STDMETHODIMP CAVIDirectSoundStream::Read( long lStart, long lSamples, LPVOID lpBuffer, long cbBuffer, long* plBytes, long* plSamples)
{
	return m_pAudioStream->Read( lStart, lSamples, lpBuffer, cbBuffer, plBytes, plSamples);
}

//=============================================================================
//
//        Interface		: IAVIDirectSoundStream::ReadData
//        PURPOSE		: Call default handler implementation
//
//        COMMENTS:	
//				See IAVIStream::ReadData
//
//
//============================================================================
STDMETHODIMP CAVIDirectSoundStream::ReadData( LPVOID lp, long FAR* lpcb)
{
	return 	m_pAudioStream->ReadData( streamtypeAUDIO, lp, lpcb);
}

//=============================================================================
//
//        Interface		: IAVIDirectSoundStream::ReadFormat
//        PURPOSE		: Call default handler implementation
//
//        COMMENTS:	
//				See IAVIStream::ReadFormat
//
//
//============================================================================
STDMETHODIMP CAVIDirectSoundStream::ReadFormat( long lPos, LPVOID lpFormat, long* lpcbFormat)
{
	return 	m_pAudioStream->ReadFormat( lPos, lpFormat, lpcbFormat);
}

//=============================================================================
//
//        Interface		: IAVIDirectSoundStream::SetFormat
//        PURPOSE		: Call default handler implementation
//
//        COMMENTS:	
//				See IAVIStream::SetFormat
//
//
//============================================================================
STDMETHODIMP CAVIDirectSoundStream::SetFormat( long lPos, LPVOID lpFormat, long cbFormat)
{
	return m_pAudioStream->SetFormat( lPos, lpFormat, cbFormat);
}

//=============================================================================
//
//        Interface		: IAVIDirectSoundStream::Write
//        PURPOSE		: Call default handler implementation
//
//        COMMENTS:	
//				See IAVIStream::Write
//
//
//============================================================================
STDMETHODIMP CAVIDirectSoundStream::Write( long lStart, long lSamples, LPVOID lpBuffer, long cbBuffer, DWORD dwFlags, long* plSampWritten, long* plBytesWritten)
{
	return 	m_pAudioStream->Write( lStart, lSamples, lpBuffer, cbBuffer, dwFlags, plSampWritten, plBytesWritten);
}

//=============================================================================
//
//        Interface		: IAVIDirectSoundStream::WriteData
//        PURPOSE		: Call default handler implementation
//
//        COMMENTS:	
//				See IAVIStream::WriteData
//
//
//============================================================================
STDMETHODIMP CAVIDirectSoundStream::WriteData( LPVOID lpBuffer, long cbBuffer)
{
	return m_pAudioStream->WriteData( streamtypeAUDIO, lpBuffer, cbBuffer);
}



//=============================================================================
//
//        Interface		: IAVIDirectSoundStream::StartCompression
//        PURPOSE		: Start compression on a DirectSound buffer
//
//        COMMENTS:
//				Prepare a decompressor to use a DirectSound buffer with
//				a given format.
//
//
//============================================================================
STDMETHODIMP CAVIDirectSoundStream::StartCompression(LPDIRECTSOUNDBUFFER lpDirectSoundBuffer)
{

	
	
	if( lpDirectSoundBuffer )
	{

		// Keep a reference on audio buffer
		m_lpDirectSoundBuffer = lpDirectSoundBuffer;
		m_lpDirectSoundBuffer->AddRef();

		
		return NOERROR;
	}
	else
		return E_FAIL;	
}


//=============================================================================
//
//        Interface		: IAVIDirectSoundStream::GetAudioSample
//        PURPOSE		: Decompress an audio sample on a DirectSound Buffer
//
//        COMMENTS:
//
//
//============================================================================
STDMETHODIMP CAVIDirectSoundStream::GetAudioSample( long lPos, long lLength, DWORD dwSampleSize )
{

	LONG lRead = 0; 			// Number of samples read
	LONG lBufferReadSize = 0; 	// Number of bytes read
	LPVOID lpWrite1 = NULL;		// Pointer to audio data
	LPVOID lpWrite2 = NULL;		// Pointer to audio data
	DWORD dwLen1 = 0;
	DWORD dwLen2 = 0;

	HRESULT ddrval = m_lpDirectSoundBuffer->Lock( 0, dwSampleSize, 
							&((LPVOID)lpWrite1), &dwLen1, &((LPVOID)lpWrite2), &dwLen2, 0 );
	if( ddrval != DD_OK)
		return ddrval;



	ddrval = AVIStreamRead(m_pAudioStream, lPos, lLength, lpWrite1, dwSampleSize, &lBufferReadSize, &lRead);
	if( ddrval != NOERROR)
		return ddrval;
	

	ddrval = m_lpDirectSoundBuffer->Unlock( (LPVOID)lpWrite1, dwLen1, (LPVOID)lpWrite2, 0 );
	if( ddrval != DD_OK)
		return ddrval;

	
	
	return NOERROR;
   

}



//=============================================================================
//
//        Interface		: IAVIDirectSoundStream::EndCompression
//        PURPOSE		: End audio decompression
//
//        COMMENTS:
//
//
//============================================================================
STDMETHODIMP CAVIDirectSoundStream::EndCompression()
{


	return NOERROR;

}




