// AVITedoc.cpp : implementation of the CAVITestDoc class
//

#include "stdafx.h"
#include "AVITest.h"

#include "AVITedoc.h"
#include "cntritem.h"

#include <vfw.h>
#include "Hostenv.h"        // Host environnement declarations
#include "FrmwrkInterfaces.h"
#include "..\inc\AVISprite.h"
#include "ddraw.h"


#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAVITestDoc

IMPLEMENT_DYNCREATE(CAVITestDoc, COleDocument)

BEGIN_MESSAGE_MAP(CAVITestDoc, COleDocument)
	//{{AFX_MSG_MAP(CAVITestDoc)
	ON_COMMAND(ID_CREATEAVI, OnCreateavi)
	ON_COMMAND(ID_READAVI, OnReadavi)
	//}}AFX_MSG_MAP
	// Enable default OLE container implementation
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, COleDocument::OnUpdatePasteMenu)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE_LINK, COleDocument::OnUpdatePasteLinkMenu)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_LINKS, COleDocument::OnUpdateEditLinksMenu)
	ON_COMMAND(ID_OLE_EDIT_LINKS, COleDocument::OnEditLinks)
	ON_UPDATE_COMMAND_UI(ID_OLE_VERB_FIRST, COleDocument::OnUpdateObjectVerbMenu)
	ON_UPDATE_COMMAND_UI(ID_OLE_EDIT_CONVERT, COleDocument::OnUpdateObjectVerbMenu)
	ON_COMMAND(ID_OLE_EDIT_CONVERT, COleDocument::OnEditConvert)
	ON_COMMAND(ID_FILE_SEND_MAIL, OnFileSendMail)
	ON_UPDATE_COMMAND_UI(ID_FILE_SEND_MAIL, OnUpdateFileSendMail)
END_MESSAGE_MAP()

BEGIN_DISPATCH_MAP(CAVITestDoc, COleDocument)
	//{{AFX_DISPATCH_MAP(CAVITestDoc)
		// NOTE - the ClassWizard will add and remove mapping macros here.
		//      DO NOT EDIT what you see in these blocks of generated code!
	//}}AFX_DISPATCH_MAP
END_DISPATCH_MAP()

/////////////////////////////////////////////////////////////////////////////
// CAVITestDoc construction/destruction

CAVITestDoc::CAVITestDoc()
{
	// For most containers, using compound files is a good idea.
	EnableCompoundFile();

	// TODO: add one-time construction code here

	EnableAutomation();

	AfxOleLockApp();
}

CAVITestDoc::~CAVITestDoc()
{
	AfxOleUnlockApp();
}

BOOL CAVITestDoc::OnNewDocument()
{
	if (!COleDocument::OnNewDocument())
		return FALSE;

	// TODO: add reinitialization code here
	// (SDI documents will reuse this document)

	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CAVITestDoc serialization

void CAVITestDoc::Serialize(CArchive& ar)
{
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}

	// Calling the base class COleDocument enables serialization
	//  of the container document's COleClientItem objects.
	COleDocument::Serialize(ar);
}

/////////////////////////////////////////////////////////////////////////////
// CAVITestDoc diagnostics

#ifdef _DEBUG
void CAVITestDoc::AssertValid() const
{
	COleDocument::AssertValid();
}

void CAVITestDoc::Dump(CDumpContext& dc) const
{
	COleDocument::Dump(dc);
}									 
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CAVITestDoc commands

void CAVITestDoc::OnCreateavi() 
{
	LPAVISPRITEFILE lpAVISpriteFile = NULL;
	PAVISTREAM		pPathStream = NULL;
	PAVISTREAM		pChromaKeyStream = NULL;

	CreateAVISpriteFromAVI("D:\\tmp\\Welcome3.avi", "D:\\tmp\\Sprite.avi", &lpAVISpriteFile);	

	lpAVISpriteFile->CreatePathStream( &pPathStream, 30 ); 			// 30 fps
	lpAVISpriteFile->CreateChromaKeyStream( &pChromaKeyStream, 0 );	// chroma key never changes


	// Write 1 sample starting at position 1
	DDCOLORKEY ChromaKey = { 255, 255};

	AVIStreamWrite( pChromaKeyStream, 1, 1, &ChromaKey, sizeof(DDCOLORKEY), 0,NULL, NULL );

	
	
	// Write 15 samples starting at position 1
	AVIPATH Path[15];
	
	for( int i = 0; i < 15; i++)
	{
		Path[i].DeltaX = i;
		Path[i].DeltaY = 2*i;
		

	}
	
	AVIStreamWrite( pPathStream, 1, 15, Path, 15*sizeof(AVIPATH), 0, NULL, NULL );
	


	// Release the streams	
	AVIStreamRelease( pChromaKeyStream ); 

	AVIStreamRelease( pPathStream );
	
	// Release AVI file
	lpAVISpriteFile->Release();
	
}

void CAVITestDoc::OnReadavi() 
{

	LPAVISPRITEFILE lpAVISpriteFile = NULL;
	PAVISTREAM		pPathStream = NULL;
	PAVISTREAM		pChromaKeyStream = NULL;


	// Open an existing AVI sprite file
	AVISpriteFileOpen("D:\\tmp\\Sprite.avi", &lpAVISpriteFile);
	

	lpAVISpriteFile->GetChromaKeyStream( &pChromaKeyStream, 0 );
	lpAVISpriteFile->GetPathStream( &pPathStream, 0 );


	// Read both streams
	DDCOLORKEY ChromaKey = { 0, 0};
	AVIPATH Path[15];

	AVIStreamRead( pChromaKeyStream, 1, 1, &ChromaKey, sizeof(DDCOLORKEY), NULL, NULL );

	// Get number of samples in path stream
	LONG dwPathStreamLength = AVIStreamLength( pPathStream ) - 1;

	AVIStreamRead( pPathStream, 1, dwPathStreamLength, Path, dwPathStreamLength*sizeof(AVIPATH), NULL, NULL );


		
	// Release the streams	
	AVIStreamRelease( pChromaKeyStream ); 

	AVIStreamRelease( pPathStream );
	
	// Release AVI file
	lpAVISpriteFile->Release();
		
}
