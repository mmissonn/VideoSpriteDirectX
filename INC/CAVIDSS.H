//==================================================================================================
//
// 		COMPONENT:	AVIDirectSoundStream
//
//		PURPOSE:	Abstract a sound stream throught a COM Component 
//
//		COMMENTS:
//				The IAVIDirectSoundStream interface wrap the IAVIStream interface and extend the capabilities
//				of an audio stream. An audio sample can be decompressed directly on a DirectSound buffer.
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




class CAVIDirectSoundStream : public IAVIDirectSoundStream
{

	private:
		LPVOID				m_pObj;					// Backpointer for delegation
		ULONG				m_cRef;					// Object reference count
		
		

	
	protected:
		PAVISTREAM			m_pAudioStream; 		// Pointer to an audio stream
		LPDIRECTSOUNDBUFFER m_lpDirectSoundBuffer;	// Pointer to the buffer where to decompress an audio sample
		  		

    public:
        // Constructors and destructor
		
        CAVIDirectSoundStream( PAVISTREAM pAVIStream );
        ~CAVIDirectSoundStream();
        
        //Non-delegating object IUnknown
        STDMETHODIMP QueryInterface(REFIID riid, LPVOID FAR* ppvObj);
        STDMETHODIMP_(ULONG) AddRef(void);
        STDMETHODIMP_(ULONG) Release(void);

		// IAVIDirectSoundStream delegating members
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

		// IAVIDirectSoundStream members
	    STDMETHODIMP StartCompression(LPDIRECTSOUNDBUFFER lpDirectSoundBuffer);
	    STDMETHODIMP GetAudioSample( long lPos, long lLength, DWORD dwSampleSize );
		STDMETHODIMP EndCompression();

		    
    

	    
};			




