
//==================================================================================================
//
// 		COMPONENT:	AVISpriteFile
//
//		PURPOSE:	Abstract a video sprite file throught a COM Component 
//
//		COMMENTS:
//				The IAVISpriteFile interface wrap the IAVIFile interface and extend the capabilities
//				of an AVI file. A video sprite has a path and a chromakey so two new streams have
//				been created.
//				
//		  AUTHOR:	Marc Missonnier 
//
//		  DATE:		october 1995
//				
//
//==================================================================================================

#pragma warning(disable:4355)

// Includes ---------------------------------------------------------------------
#include "Hostenv.h"        // Host environnement declarations
#include "FrmwrkInterfaces.h"
#include "AVISprite.h"		// Global defines for video sprite


class CAVISprite : public IAVISpriteFile
{

	private:
		LPVOID				m_pObj;				// Backpointer for delegation
		ULONG				m_cRef;				// Object reference count
		
		

	
	protected:
		PAVIFILE			m_pAVIFile; 		// Pointer to an AVI file
		PAVISTREAM  		m_ChromaKeyStream;	// Chromakeying stream
		PAVISTREAM  		m_PathStream;	  	// Video sprite path Stream
		
		

    public:
        // Constructors and destructor
		
        CAVISprite();
        ~CAVISprite();

		// Initialization functions
	    HRESULT Initialize(LPTSTR szSrcFilename, LPTSTR szDestFilename);     
		HRESULT Initialize(LPTSTR szSrcFilename);
        
        //Non-delegating object IUnknown
        STDMETHODIMP QueryInterface(REFIID riid, LPVOID FAR* ppvObj);
        STDMETHODIMP_(ULONG) AddRef(void);
        STDMETHODIMP_(ULONG) Release(void);

		// IAVISpriteFile delegating members
	    STDMETHODIMP Info( AVIFILEINFO* pfi, LONG lSize);
		STDMETHODIMP GetStream( PAVISTREAM* ppStream, DWORD fccType, LONG lParam);
	    STDMETHODIMP CreateStream( PAVISTREAM* ppStream, AVISTREAMINFO* psi);
	    STDMETHODIMP WriteData( DWORD ckid, LPVOID lpData, LONG cbData);
	    STDMETHODIMP ReadData( DWORD ckid, LPVOID lpData, LONG FAR *lpcbData);
	    STDMETHODIMP EndRecord();

		// IAVISpriteFile members
		STDMETHODIMP CreateChromaKeyStream( PAVISTREAM* ppAVIStream, DWORD dwRate);
		STDMETHODIMP CreatePathStream( PAVISTREAM*  ppAVIStream, DWORD dwRate);
		STDMETHODIMP CreateDDSurfaceStream( LPAVIDDSURFACESTREAM* ppAVIDDSurfaceStream, DWORD dwRate);
	    STDMETHODIMP CreateDirectSoundStream( LPAVIDIRECTSOUNDSTREAM* ppAVIDSoundStream, DWORD dwRate);
		STDMETHODIMP GetChromaKeyStream( PAVISTREAM* ppAVIStream, DWORD dwNumber);
		STDMETHODIMP GetPathStream( PAVISTREAM* ppAVIStream, DWORD dwNumber);
	    STDMETHODIMP GetDDSurfaceStream( LPAVIDDSURFACESTREAM* ppAVIDDSurfaceStream, DWORD dwNumber);
	    STDMETHODIMP GetDirectSoundStream( LPAVIDIRECTSOUNDSTREAM* ppAVIDSoundStream, DWORD dwNumber);
		    

	    
};			




