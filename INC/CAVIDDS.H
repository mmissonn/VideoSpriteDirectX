//==================================================================================================
//
// 		COMPONENT:	AVIDDSurfaceStream
//
//		PURPOSE:	Abstract a video stream throught a COM Component 
//
//		COMMENTS:
//				The IAVIDDSurfaceStream interface wrap the IAVIStream interface and extend the capabilities
//				of a video stream. A video frame can be decompressed directly on a DirectDraw surface.
//				This component will be obsolete when DirectVideo arrives.
//				
//		  AUTHOR:	Marc Missonnier 
//
//		  DATE:		october 1995
//				
//				
//
//==================================================================================================

#pragma warning(disable:4355)

// Includes ---------------------------------------------------------------------
#include "Hostenv.h"        // Host environnement declarations
#include "FrmwrkInterfaces.h"
#include "AVISprite.h"		// Global defines for video sprite




class CAVIDDSurfaceStream : public IAVIDDSurfaceStream
{

	private:
		LPVOID				m_pObj;				// Backpointer for delegation
		ULONG				m_cRef;				// Object reference count
		BITMAPINFOHEADER	m_bmi;				// Desired format for video output
		

	
	protected:
		PAVISTREAM			m_pVideoStream; 	// Pointer to a video stream
		PGETFRAME			m_pGetFrame;		// Pointer to an IGetFrame Interface
		LPDIRECTDRAWSURFACE m_lpDDSurface;		// Pointer to the surface where to decompress a video frame
		  		

    public:
        // Constructors and destructor
		
        CAVIDDSurfaceStream( PAVISTREAM pAVIStream );
        ~CAVIDDSurfaceStream();
        
        //Non-delegating object IUnknown
        STDMETHODIMP QueryInterface(REFIID riid, LPVOID FAR* ppvObj);
        STDMETHODIMP_(ULONG) AddRef(void);
        STDMETHODIMP_(ULONG) Release(void);

		// IAVIDDSurfaceStream delegating members
        STDMETHODIMP Create( long lParam1, long lParam2);
	    STDMETHODIMP Delete( long lStart, long lSamples);
	    STDMETHODIMP Info( AVISTREAMINFO* psi, long lSize);
	    STDMETHODIMP FindSample( long lPos, long lFlags, long FAR* lPosFound);
	    STDMETHODIMP Read( long lStart, long lSamples, LPVOID lpBuffer, long cbBuffer, long* plBytes, long* plSamples);
	    STDMETHODIMP ReadData( LPVOID lp, long FAR* lpcb);
	    STDMETHODIMP ReadFormat( long lPos, LPVOID lpFormat, long* lpcbFormat);
	    STDMETHODIMP SetFormat( long lPos, LPVOID lpFormat, long cbFormat);
	    STDMETHODIMP Write( long lStart, long lSamples, LPVOID lpBuffer, long cbBuffer, DWORD dwFlags, long* plSampWritten, long* plBytesWritten);
	    STDMETHODIMP WriteData( LPVOID lpBuffer, long cbBuffer);

		// IAVIDDSurfaceStream members
	    STDMETHODIMP StartCompression(LPDIRECTDRAWSURFACE lpDDSurface);
	    STDMETHODIMP GetFrame(long lPos);
		STDMETHODIMP GetPalette( LPDIRECTDRAWPALETTE lpDDPalette, long lPos);
		STDMETHODIMP EndCompression();

		    
    

	    
};			




