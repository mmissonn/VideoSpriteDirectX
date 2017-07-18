//=============================================================================
//						CORE VIDEO SPRITE TECHNOLOGY
//
//        PROGRAM: 	CAVIDDSurfaceStream.cpp
//
//        PURPOSE: 	AVI Sprite static library
//
//        FUNCTIONS:
// 					CreateAVIDDSurfaceStream
//
//		  AUTHOR:	Marc Missonnier 
//
//		  DATE:		october 1995
//
//        
//============================================================================

// Includes ---------------------------------------------------------------------
#include "CAVIDDS.h"		// AVI DirectDraw surface stream definition



  


//=============================================================================
//
//        FUNCTION: CreateAVIDDSurfaceStream
//        PURPOSE: Create a new COM AVI DirectDraw surface Stream
//
//        COMMENTS:
//				Create a DirectDraw Surface stream from a video stream
//				
//
//
//============================================================================
HRESULT CreateAVIDDSurfaceStream( PAVISTREAM pAVIStream, LPAVIDDSURFACESTREAM* ppAVIDDSurfaceStream )
{
    HRESULT  	hr = NOERROR;
    CAVIDDSurfaceStream*	pObj = NULL;

	
			
	// Create new stream
	pObj = new CAVIDDSurfaceStream( pAVIStream ); 
	
 
    if( pObj != NULL )
	   	hr = pObj->QueryInterface( IID_IAVIDDSurfaceStream, (LPVOID*)ppAVIDDSurfaceStream );
	else
		hr = E_OUTOFMEMORY;
	
	return hr;

    
}




//=============================================================================
//
//        Class			: CAVIDDSurfaceStream
//        PURPOSE		: Constructor
//
//        COMMENTS:
//				Initialize the video stream used for delegation
//
//
//============================================================================
CAVIDDSurfaceStream::CAVIDDSurfaceStream(PAVISTREAM pAVIStream)
{  

	// Initialize video stream for delegation by containment
	m_cRef = 0;
	m_pVideoStream = pAVIStream;
	m_pGetFrame	= NULL;

	// Initialize video format output								  
	m_bmi.biCompression 	= BI_RGB;
	m_bmi.biPlanes			= 1;
	m_bmi.biSize			= sizeof(BITMAPINFOHEADER);
	m_bmi.biBitCount		= 8;	// 8 bit / pixel
	m_bmi.biXPelsPerMeter	= 0;
	m_bmi.biYPelsPerMeter	= 0;
	m_bmi.biClrImportant	= 0;//256;
	m_bmi.biClrUsed			= 0;//256;

	


}




//=============================================================================
//
//        Class			: CAVIDDSurfaceStream
//        PURPOSE		: Destructor
//
//        COMMENTS:
//				Clean up code.
//
//
//============================================================================
CAVIDDSurfaceStream::~CAVIDDSurfaceStream()
{
	if( m_pVideoStream )
		m_pVideoStream->Release();

	if( m_lpDDSurface )
		m_lpDDSurface->Release();

}



//=============================================================================
//
//        Interface		: IUnknown::QueryInterface
//        PURPOSE		: Interface dispatching
//
//        COMMENTS:
//				See IUnknown::QueryInterface
//				The object exposes the following interface :
//					IAVIDDSurfaceStream
//				
//
//
//============================================================================
STDMETHODIMP CAVIDDSurfaceStream::QueryInterface(REFIID riid, LPVOID FAR* ppvObj)
{
	
    *ppvObj = NULL;

	if(riid == IID_IUnknown)// IUnknown interface
        *ppvObj=this;
    else if( riid == IID_IAVIDDSurfaceStream)
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
STDMETHODIMP_(ULONG) CAVIDDSurfaceStream::AddRef(void)
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
STDMETHODIMP_(ULONG) CAVIDDSurfaceStream::Release(void)
{
    if (0!=--m_cRef)
        return m_cRef;

    delete this;
    return 0;

}


//=============================================================================
//
//        Interface		: IAVIDDSurfaceStream::Create
//        PURPOSE		: Call default handler implementation
//
//        COMMENTS:	
//				See IAVIStream::Create	
//				Wrap IAVIStream interface and delegate to the video stream.
//
//
//============================================================================
STDMETHODIMP CAVIDDSurfaceStream::Create( long lParam1, long lParam2)
{
	return 	m_pVideoStream->Create( lParam1, lParam2);
}


//=============================================================================
//
//        Interface		: IAVIDDSurfaceStream::Delete
//        PURPOSE		: Call default handler implementation
//
//        COMMENTS:	
//				See IAVIStream::Delete
//
//
//============================================================================
STDMETHODIMP CAVIDDSurfaceStream::Delete( long lStart, long lSamples)
{
	return 	m_pVideoStream->Delete( lStart, lSamples);
}

//=============================================================================
//
//        Interface		: IAVIDDSurfaceStream::Info
//        PURPOSE		: Call default handler implementation
//
//        COMMENTS:	
//				See IAVIStream::Info
//
//
//============================================================================
STDMETHODIMP CAVIDDSurfaceStream::Info( AVISTREAMINFO* psi, long lSize)
{
	
	if( AVIStreamInfo(m_pVideoStream, psi, lSize) )
		return E_FAIL;
	else
		return NOERROR;
}

//=============================================================================
//
//        Interface		: IAVIDDSurfaceStream::FindSample
//        PURPOSE		: Call default handler implementation
//
//        COMMENTS:	
//				See IAVIStream::FindSample
//
//
//============================================================================
STDMETHODIMP CAVIDDSurfaceStream::FindSample( long lPos, long lFlags, long FAR* lPosFound)
{
	*lPosFound = m_pVideoStream->FindSample( lPos, lFlags );

	if( *lPosFound == -1 )
		return E_FAIL;
	else
		return NOERROR;
}


//=============================================================================
//
//        Interface		: IAVIDDSurfaceStream::Read
//        PURPOSE		: Call default handler implementation
//
//        COMMENTS:	
//				See IAVIStream::Read
//
//
//============================================================================
STDMETHODIMP CAVIDDSurfaceStream::Read( long lStart, long lSamples, LPVOID lpBuffer, long cbBuffer, long* plBytes, long* plSamples)
{
	return m_pVideoStream->Read( lStart, lSamples, lpBuffer, cbBuffer, plBytes, plSamples);
}

//=============================================================================
//
//        Interface		: IAVIDDSurfaceStream::ReadData
//        PURPOSE		: Call default handler implementation
//
//        COMMENTS:	
//				See IAVIStream::ReadData
//
//
//============================================================================
STDMETHODIMP CAVIDDSurfaceStream::ReadData( LPVOID lp, long FAR* lpcb)
{
	return 	m_pVideoStream->ReadData( streamtypeVIDEO, lp, lpcb);
}

//=============================================================================
//
//        Interface		: IAVIDDSurfaceStream::ReadFormat
//        PURPOSE		: Call default handler implementation
//
//        COMMENTS:	
//				See IAVIStream::ReadFormat
//
//
//============================================================================
STDMETHODIMP CAVIDDSurfaceStream::ReadFormat( long lPos, LPVOID lpFormat, long* lpcbFormat)
{
	return 	m_pVideoStream->ReadFormat( lPos, lpFormat, lpcbFormat);
}

//=============================================================================
//
//        Interface		: IAVIDDSurfaceStream::SetFormat
//        PURPOSE		: Call default handler implementation
//
//        COMMENTS:	
//				See IAVIStream::SetFormat
//
//
//============================================================================
STDMETHODIMP CAVIDDSurfaceStream::SetFormat( long lPos, LPVOID lpFormat, long cbFormat)
{
	return m_pVideoStream->SetFormat( lPos, lpFormat, cbFormat);
}

//=============================================================================
//
//        Interface		: IAVIDDSurfaceStream::Write
//        PURPOSE		: Call default handler implementation
//
//        COMMENTS:	
//				See IAVIStream::Write
//
//
//============================================================================
STDMETHODIMP CAVIDDSurfaceStream::Write( long lStart, long lSamples, LPVOID lpBuffer, long cbBuffer, DWORD dwFlags, long* plSampWritten, long* plBytesWritten)
{
	return 	m_pVideoStream->Write( lStart, lSamples, lpBuffer, cbBuffer, dwFlags, plSampWritten, plBytesWritten);
}

//=============================================================================
//
//        Interface		: IAVIDDSurfaceStream::WriteData
//        PURPOSE		: Call default handler implementation
//
//        COMMENTS:	
//				See IAVIStream::WriteData
//
//
//============================================================================
STDMETHODIMP CAVIDDSurfaceStream::WriteData( LPVOID lpBuffer, long cbBuffer)
{
	return m_pVideoStream->WriteData( streamtypeVIDEO, lpBuffer, cbBuffer);
}









//=============================================================================
//
//        Interface		: IAVIDDSurfaceStream::StartCompression
//        PURPOSE		: Start compression on a DirectDraw surface
//
//        COMMENTS:
//				Prepare a decompressor to use a DirectDraw surface with
//				a given format.
//
//
//============================================================================
STDMETHODIMP CAVIDDSurfaceStream::StartCompression(LPDIRECTDRAWSURFACE lpDDSurface)
{

	/*	
	if( lpDDSurface )
	{

		// Keep a reference on the surface
		m_lpDDSurface = lpDDSurface;
		m_lpDDSurface->AddRef();

		DDSURFACEDESC DDSurfDesc;
		
		

		DDSurfDesc.dwSize = sizeof(DDSurfDesc);
		lpDDSurface->GetSurfaceDesc( &DDSurfDesc );

		// Initialize bitmap info with surface description
		m_bmi.biHeight 			= DDSurfDesc.dwHeight; 
		m_bmi.biWidth  			= DDSurfDesc.dwWidth; 
		m_bmi.biSizeImage		= DDSurfDesc.dwHeight * DDSurfDesc.dwWidth;
		
		
		// Get an IGetFrame interface
		m_pGetFrame = AVIStreamGetFrameOpen( m_pVideoStream, &m_bmi);	

		

		if( m_pGetFrame ) 
			return NOERROR;
		else
			return E_FAIL;

	}
	else
		return E_FAIL;
	*/
	
	
	if( lpDDSurface )
	{

		// Keep a reference on the surface
		m_lpDDSurface = lpDDSurface;
		m_lpDDSurface->AddRef();

		// Get an IGetFrame interface on a video stream
		m_pGetFrame = AVIStreamGetFrameOpen( m_pVideoStream, NULL);
		
		if( m_pGetFrame )
		{
	   
			DDSURFACEDESC DDSurfDesc;

			// Make a copy of the bitmap inside the surface
			// Lock returns a memory pointer to the top of the surface.    

			DDSurfDesc.dwSize = sizeof(DDSurfDesc);
		
		    while ( lpDDSurface->Lock( NULL, &DDSurfDesc, 0, NULL ) == DDERR_WASSTILLDRAWING );


			// Set format of decompressed video frame
			// Initialize bitmap info with surface description
			m_bmi.biHeight 		= -( (LONG) (DDSurfDesc.dwHeight) ); 
			m_bmi.biWidth  		= DDSurfDesc.dwWidth; 
			m_bmi.biSizeImage	= DDSurfDesc.dwHeight * DDSurfDesc.dwWidth;

			
			// Does not work with 8 bits / pixel video format 
			// Why ??
			HRESULT hr = m_pGetFrame->SetFormat( &m_bmi, DDSurfDesc.lpSurface, 0, 0, DDSurfDesc.dwWidth, DDSurfDesc.dwHeight );
			
			
			//HRESULT hr = m_pGetFrame->SetFormat( (LPBITMAPINFOHEADER) (1), DDSurfDesc.lpSurface, 0, 0, DDSurfDesc.dwWidth, DDSurfDesc.dwHeight);

		 	lpDDSurface->Unlock( NULL );

			return hr;
		}
		else
			return E_FAIL;
	}
	else
		return E_FAIL;	
}


//=============================================================================
//
//        Interface		: IAVIDDSurfaceStream::GetFrame
//        PURPOSE		: Decompress a video frame on a DirectDraw surface
//
//        COMMENTS:
//
//
//============================================================================
STDMETHODIMP CAVIDDSurfaceStream::GetFrame( long lPos)
{

	
	DDSURFACEDESC DDSurfDesc;

	// Make a copy of the bitmap inside the surface
	// Lock returns a memory pointer to the top of the surface.    

	DDSurfDesc.dwSize = sizeof(DDSurfDesc);
		
    while ( m_lpDDSurface->Lock( NULL, &DDSurfDesc, 0, NULL ) == DDERR_WASSTILLDRAWING );

	
	
	m_pGetFrame->GetFrame( lPos );


 	m_lpDDSurface->Unlock( NULL );
	
	
	return NOERROR;
   

}



/*
STDMETHODIMP CAVIDDSurfaceStream::GetFrame( long lPos )
{

	
	// Get a decompressed video frame
	LPBITMAPINFOHEADER pFrame = (LPBITMAPINFOHEADER) AVIStreamGetFrame( m_pGetFrame, lPos );

	if( pFrame == NULL )
		return E_FAIL;


	


	DDSURFACEDESC DDSurfDesc;

	// Make a copy of the bitmap inside the surface
	// Lock returns a memory pointer to the top of the surface.    

	DDSurfDesc.dwSize = sizeof(DDSurfDesc);
		
    while ( m_lpDDSurface->Lock( NULL, &DDSurfDesc, 0, NULL ) == DDERR_WASSTILLDRAWING );
   
		    
    // Copy bits from system memory to video memory.
	// y order is inverted
    LPSTR lpBits = (LPSTR)DDSurfDesc.lpSurface;
	LPSTR lpSrc;

	LONG Height = DDSurfDesc.dwHeight;
	LONG Width	= DDSurfDesc.dwWidth;
	
	
	if( pFrame->biClrUsed != 0 )
		lpSrc = (LPSTR)( (LPBYTE)(pFrame) + (UINT)(pFrame)->biSize + (UINT)(pFrame->biClrUsed*sizeof(RGBQUAD)) + (UINT)(DDSurfDesc.dwHeight*DDSurfDesc.dwWidth) );
	else	
		lpSrc = (LPSTR)( (LPBYTE)(pFrame) + (UINT)(pFrame)->biSize + (UINT)((1<<pFrame->biBitCount)*sizeof(RGBQUAD)) + (UINT)(DDSurfDesc.dwHeight*DDSurfDesc.dwWidth) );			
	
	
	LONG SurfaceStride;

	if( DDSurfDesc.lPitch == 0 )
		SurfaceStride = Width;
	else
		SurfaceStride  = DDSurfDesc.lPitch;
		
			

    for(int i=0; i < Height; i++)
    {
		lpSrc -= Width;
        memcpy( lpBits, lpSrc, Width );
        lpBits += SurfaceStride;
        
    }

    m_lpDDSurface->Unlock( NULL );
	
	
	return NOERROR;
	


}
*/

//=============================================================================
//
//        Interface		: IAVIDDSurfaceStream::GetPalette
//        PURPOSE		: Decompress a frame on a DirectDraw palette
//
//        COMMENTS:
//				Set new entries for a DirectDraw palette with the video frame 
//				palette.
//
//
//============================================================================
STDMETHODIMP CAVIDDSurfaceStream::GetPalette( LPDIRECTDRAWPALETTE lpDDPalette, long lPos )
{

	// Keep a reference on Palette
	lpDDPalette->AddRef();

	// Get a decompressed video frame
	LPBITMAPINFOHEADER pFrame = (LPBITMAPINFOHEADER) AVIStreamGetFrame( m_pGetFrame, lPos );

	if( pFrame == NULL )
		return E_FAIL;

	/*
	// DEBUG output
	char	szDebug[512];
	
	wsprintf( szDebug, " biCompression = %d\n biPlanes = %d\n biSize = %d\n biBitCount = %d\n biXPelsPerMeter = %d\n biYPelsPerMeter = %d\n biClrImportant = %d\n  biClrUsed= %d\n biWidth = %d\n biHeight = %d\n biSizeImage = %d\n", 
				pFrame->biCompression,
				pFrame->biPlanes,				
				pFrame->biSize,			
				pFrame->biBitCount,		
				pFrame->biXPelsPerMeter,	
				pFrame->biYPelsPerMeter,	
				pFrame->biClrImportant,			
				pFrame->biClrUsed,
				pFrame->biWidth,
				pFrame->biHeight,
				pFrame->biSizeImage );				
		
	OutputDebugString( szDebug );
	*/
		
	// Fill palette entries
	PALETTEENTRY 		ColorTable[256];	// Palette entries
	RGBQUAD*            Palette;			// Colors
	int					NumColors   = 0; 	// Number of colors in palette
	

	// Get a pointer to a color table
	Palette = ((RGBQUAD*)((LPBYTE)(pFrame) + (int)(pFrame)->biSize));

	// Determine if we have 4 or 8 bits per pixel
	if( pFrame->biBitCount == 4 )
	{
		NumColors = 16;
		
	}
	else if( pFrame->biBitCount >= 8 )
	{
		NumColors = 256;
		

	}
		
    for( int i = 0; i < NumColors; i++ )
    {
        ColorTable[i].peRed 	= Palette[i].rgbRed;
        ColorTable[i].peGreen 	= Palette[i].rgbGreen;
        ColorTable[i].peBlue 	= Palette[i].rgbBlue;
    }
    
	
	HRESULT hr = lpDDPalette->SetEntries( 0, 0, NumColors, ColorTable );


	// Release palette
	lpDDPalette->Release();


	return hr;

}


//=============================================================================
//
//        Interface		: IAVIDDSurfaceStream::EndCompression
//        PURPOSE		: End compression
//
//        COMMENTS:
//
//============================================================================
STDMETHODIMP CAVIDDSurfaceStream::EndCompression()
{

	// Release IGetFrame pointer
	int hr = AVIStreamGetFrameClose(m_pGetFrame);

	m_pGetFrame = NULL;
	

	if( hr )
		return E_FAIL;
	else
		return NOERROR;

}




/*
	// Create a DirectDraw surface
	HRESULT hr;

	if(	m_pDDSurfDesc )
	{
		// NOT IMPLEMENTED YET...
		return E_NOTIMPL;

		//hr = m_pDD->CreateSurface( m_pDDSurfDesc, lplpDDSurface, NULL); 

	}
	else
	{
		// We should create a DDPalette with the color table and
		// associate it to the DDSurface...
		
		// unresolved issue : the lpSurface pointer will not be valid on the next call
		// should we make a copy ?

		DDSURFACEDESC DDSurfDesc;
		
		DDSurfDesc.dwFlags = DDSD_CAPS | DDSD_HEIGHT | DDSD_WIDTH; //| DDSD_LPSURFACE;

		DDSurfDesc.dwHeight 		= pFrame->biHeight;
		DDSurfDesc.dwWidth  		= pFrame->biWidth;
	    
		
		//DDSurfDesc.lpSurface  		= (LPSTR)( (LPBYTE)(pFrame) + (UINT)(pFrame)->biSize + (UINT)(pFrame->biClrUsed*sizeof(RGBQUAD)) );
		

		DDSurfDesc.ddsCaps.dwCaps 	= DDSCAPS_OFFSCREENPLAIN | DDSCAPS_SYSTEMMEMORY;
		
		DDSurfDesc.dwSize 			= sizeof( DDSurfDesc );

		hr = m_lpDD->CreateSurface( &DDSurfDesc, lplpDDSurface, NULL ); 

		if( hr != DD_OK	 )
			return hr;
	 */
