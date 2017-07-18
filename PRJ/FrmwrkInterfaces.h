/* This header file machine-generated by mktyplib.exe */
/* Interface to type library: FrameworkInterfaces */

#ifndef _FrameworkInterfaces_H_
#define _FrameworkInterfaces_H_

DEFINE_GUID(LIBID_FrameworkInterfaces,0x547DA320,0xC764,0x11CE,0xA1,0xEC,0x44,0x45,0x53,0x54,0x00,0x00);

typedef BITMAPINFOHEADER FAR* LPDIB;

typedef struct _INSTANCEID {
    CLSID CodeSection;
    unsigned long DataSection;
    LPUNKNOWN InterfacePointer;
} INSTANCEID;

typedef enum {
    POINTER,
    SELECT,
    GRABBER,
    MENU,
    RECTANGLESELECTOR
} CURSOR;

typedef enum {
    DECREASE = 0,
    DECREASEFIXED = 1,
    INCREASE = 2,
    INCREASEFIXED = 3
} DS_ORDER_LEAF;

typedef struct _WINDOWPARAM {
    int Height;
    int Width;
    int XPos;
    int YPos;
    CURSOR CursorMode;
    HDC ScreenBufferDC;
    LPDIB ScreenBuffer;
} WINDOWPARAM;

typedef struct _WINDOWPARAM FAR* LPWINDOWPARAM;

typedef struct _BOUNDRECT {
    long XPos;
    long YPos;
    long Width;
    long Height;
} BOUNDRECT;

typedef struct _BOUNDRECT FAR* LPBOUNDRECT;

DEFINE_GUID(IID_ISurface,0x98A12AE0,0xCDEF,0x11CE,0xB7,0x4F,0xA6,0xCC,0x4F,0x1C,0xF9,0x34);

/* Definition of interface: ISurface */
DECLARE_INTERFACE_(ISurface, IUnknown)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;
#endif

    /* ISurface methods */
    STDMETHOD(GetSurfaceBits)(THIS_ LPDIB FAR* ppDIB) PURE;
    STDMETHOD(GetColorKey)(THIS_ COLORREF FAR* KeyColor) PURE;
};

typedef ISurface FAR* LPSURFACE;

DEFINE_GUID(IID_ILinkComponent,0x3E596402,0xCD70,0x11CE,0xA1,0xEC,0x44,0x45,0x53,0x54,0x00,0x00);

/* Definition of interface: ILinkComponent */
DECLARE_INTERFACE_(ILinkComponent, IUnknown)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;
#endif

    /* ILinkComponent methods */
    STDMETHOD(Link)(THIS_ LPVOID pInterface) PURE;
    STDMETHOD(Unlink)(THIS) PURE;
};

typedef ILinkComponent FAR* LPLINKCOMPONENT;

DEFINE_GUID(IID_IAVIDDSurfaceStream,0x0C6E5C62,0x017E,0x11CF,0xB7,0x50,0x44,0x45,0x53,0x54,0x00,0x00);

/* Definition of interface: IAVIDDSurfaceStream */
DECLARE_INTERFACE_(IAVIDDSurfaceStream, IUnknown)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;
#endif

    /* IAVIDDSurfaceStream methods */
    STDMETHOD(Create)(THIS_ long lParam1, long lParam2) PURE;
    STDMETHOD(Delete)(THIS_ long lStart, long lSamples) PURE;
    STDMETHOD(Info)(THIS_ AVISTREAMINFO FAR* psi, long lSize) PURE;
    STDMETHOD(FindSample)(THIS_ long lPos, long lFlags, long FAR* lPosFound) PURE;
    STDMETHOD(Read)(THIS_ long lStart, long lSamples, LPVOID lpBuffer, long cbBuffer, long FAR* plBytes, long FAR* plSamples) PURE;
    STDMETHOD(ReadData)(THIS_ LPVOID lp, long FAR* lpcb) PURE;
    STDMETHOD(ReadFormat)(THIS_ long lPos, LPVOID lpFormat, long FAR* lpcbFormat) PURE;
    STDMETHOD(SetFormat)(THIS_ long lPos, LPVOID lpFormat, long cbFormat) PURE;
    STDMETHOD(Write)(THIS_ long lStart, long lSamples, LPVOID lpBuffer, long cbBuffer, DWORD dwFlags, long FAR* plSampWritten, long FAR* plBytesWritten) PURE;
    STDMETHOD(WriteData)(THIS_ LPVOID lpBuffer, long cbBuffer) PURE;
    STDMETHOD(StartCompression)(THIS_ LPDIRECTDRAWSURFACE lpDDSurface) PURE;
    STDMETHOD(GetFrame)(THIS_ long lPos) PURE;
    STDMETHOD(GetPalette)(THIS_ LPDIRECTDRAWPALETTE lpDDPalette, long lPos) PURE;
    STDMETHOD(EndCompression)(THIS) PURE;
};

typedef IAVIDDSurfaceStream FAR* LPAVIDDSURFACESTREAM;

DEFINE_GUID(IID_IAVIDirectSoundStream,0x0C6E5C61,0x017E,0x11CF,0xB7,0x50,0x44,0x45,0x53,0x54,0x00,0x00);

/* Definition of interface: IAVIDirectSoundStream */
DECLARE_INTERFACE_(IAVIDirectSoundStream, IUnknown)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;
#endif

    /* IAVIDirectSoundStream methods */
    STDMETHOD(Create)(THIS_ long lParam1, long lParam2) PURE;
    STDMETHOD(Delete)(THIS_ long lStart, long lSamples) PURE;
    STDMETHOD(Info)(THIS_ AVISTREAMINFO FAR* psi, long lSize) PURE;
    STDMETHOD(FindSample)(THIS_ long lPos, long lFlags, long FAR* lPosFound) PURE;
    STDMETHOD(Read)(THIS_ long lStart, long lSamples, LPVOID lpBuffer, long cbBuffer, long FAR* plBytes, long FAR* plSamples) PURE;
    STDMETHOD(ReadData)(THIS_ LPVOID lp, long FAR* lpcb) PURE;
    STDMETHOD(ReadFormat)(THIS_ long lPos, LPVOID lpFormat, long FAR* lpcbFormat) PURE;
    STDMETHOD(SetFormat)(THIS_ long lPos, LPVOID lpFormat, long cbFormat) PURE;
    STDMETHOD(Write)(THIS_ long lStart, long lSamples, LPVOID lpBuffer, long cbBuffer, DWORD dwFlags, long FAR* plSampWritten, long FAR* plBytesWritten) PURE;
    STDMETHOD(WriteData)(THIS_ LPVOID lpBuffer, long cbBuffer) PURE;
    STDMETHOD(StartCompression)(THIS_ LPDIRECTSOUNDBUFFER lpDirectSoundBuffer) PURE;
    STDMETHOD(GetAudioSample)(THIS_ long lPos, long lLength, DWORD dwSampleSize) PURE;
    STDMETHOD(EndCompression)(THIS) PURE;
};

typedef IAVIDirectSoundStream FAR* LPAVIDIRECTSOUNDSTREAM;

DEFINE_GUID(IID_IAVISpriteFile,0x2C84D940,0xFB37,0x11CE,0xB7,0x50,0x44,0x45,0x53,0x54,0x00,0x00);

/* Definition of interface: IAVISpriteFile */
DECLARE_INTERFACE_(IAVISpriteFile, IUnknown)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;
#endif

    /* IAVISpriteFile methods */
    STDMETHOD(Info)(THIS_ AVIFILEINFO FAR* pfi, long lSize) PURE;
    STDMETHOD(GetStream)(THIS_ PAVISTREAM FAR* ppStream, DWORD fccType, long lParam) PURE;
    STDMETHOD(CreateStream)(THIS_ PAVISTREAM FAR* ppStream, AVISTREAMINFO FAR* psi) PURE;
    STDMETHOD(WriteData)(THIS_ DWORD ckid, LPVOID lpData, long cbData) PURE;
    STDMETHOD(ReadData)(THIS_ DWORD ckid, LPVOID lpData, long FAR* lpcbData) PURE;
    STDMETHOD(EndRecord)(THIS) PURE;
    STDMETHOD(CreateChromaKeyStream)(THIS_ PAVISTREAM FAR* ppAVIStream, DWORD dwRate) PURE;
    STDMETHOD(CreatePathStream)(THIS_ PAVISTREAM FAR* ppAVIStream, DWORD dwRate) PURE;
    STDMETHOD(CreateDDSurfaceStream)(THIS_ LPAVIDDSURFACESTREAM FAR* ppAVIDDSurfaceStream, DWORD dwRate) PURE;
    STDMETHOD(CreateDirectSoundStream)(THIS_ LPAVIDIRECTSOUNDSTREAM FAR* ppAVIDSoundStream, DWORD dwRate) PURE;
    STDMETHOD(GetChromaKeyStream)(THIS_ PAVISTREAM FAR* ppAVIStream, DWORD dwNumber) PURE;
    STDMETHOD(GetPathStream)(THIS_ PAVISTREAM FAR* ppAVIStream, DWORD dwNumber) PURE;
    STDMETHOD(GetDDSurfaceStream)(THIS_ LPAVIDDSURFACESTREAM FAR* ppAVIDDSurfaceStream, DWORD dwNumber) PURE;
    STDMETHOD(GetDirectSoundStream)(THIS_ LPAVIDIRECTSOUNDSTREAM FAR* ppAVIDSoundStream, DWORD dwNumber) PURE;
};

typedef IAVISpriteFile FAR* LPAVISPRITEFILE;

DEFINE_GUID(IID_ILinkSurface,0x8F03D841,0xD009,0x11CE,0xA1,0xEC,0x44,0x45,0x53,0x54,0x00,0x00);

/* Definition of interface: ILinkSurface */
DECLARE_INTERFACE_(ILinkSurface, IUnknown)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;
#endif

    /* ILinkSurface methods */
    STDMETHOD(Link)(THIS_ LPSURFACE pSurface) PURE;
    STDMETHOD(Unlink)(THIS) PURE;
};

typedef ILinkSurface FAR* LPLINKSURFACE;

DEFINE_GUID(IID_IAbstractNode,0x3CA76640,0xAE0B,0x11CE,0xB9,0x79,0x83,0x8A,0x92,0xD8,0xA9,0xBD);

/* Definition of interface: IAbstractNode */
DECLARE_INTERFACE_(IAbstractNode, ILinkComponent)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* ILinkComponent methods */
    STDMETHOD(Link)(THIS_ LPVOID pInterface) PURE;
    STDMETHOD(Unlink)(THIS) PURE;
#endif

    /* IAbstractNode methods */
    STDMETHOD(GetNext)(THIS_ IAbstractNode FAR* FAR* pNode, LPVOID FAR* pInterface) PURE;
    STDMETHOD(GetPrevious)(THIS_ IAbstractNode FAR* FAR* pNode, LPVOID FAR* pInterface) PURE;
    STDMETHOD(GetCachedInterface)(THIS_ LPVOID FAR* pInterface) PURE;
};

typedef IAbstractNode FAR* LPABSTRACTNODE;

DEFINE_GUID(IID_IEditAbstractNode,0x48F656E0,0xAE0B,0x11CE,0xB9,0x79,0x83,0x8A,0x92,0xD8,0xA9,0xBD);

/* Definition of interface: IEditAbstractNode */
DECLARE_INTERFACE_(IEditAbstractNode, IAbstractNode)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* ILinkComponent methods */
    STDMETHOD(Link)(THIS_ LPVOID pInterface) PURE;
    STDMETHOD(Unlink)(THIS) PURE;

    /* IAbstractNode methods */
    STDMETHOD(GetNext)(THIS_ IAbstractNode FAR* FAR* pNode, LPVOID FAR* pInterface) PURE;
    STDMETHOD(GetPrevious)(THIS_ IAbstractNode FAR* FAR* pNode, LPVOID FAR* pInterface) PURE;
    STDMETHOD(GetCachedInterface)(THIS_ LPVOID FAR* pInterface) PURE;
#endif

    /* IEditAbstractNode methods */
    STDMETHOD(SetNext)(THIS_ LPABSTRACTNODE pNode) PURE;
    STDMETHOD(SetPrevious)(THIS_ LPABSTRACTNODE pNode) PURE;
    STDMETHOD(GetValueOfKey)(THIS_ LPVOID FAR* pValue) PURE;
    STDMETHOD(CompareKey)(THIS_ LPVOID pValue) PURE;
    STDMETHOD(GetTypeOfKey)(THIS_ int FAR* pType) PURE;
};

typedef IEditAbstractNode FAR* LPEDITABSTRACTNODE;

DEFINE_GUID(IID_IEditElementaryAbstract,0x2DA849C0,0xAE0B,0x11CE,0xB9,0x79,0x83,0x8A,0x92,0xD8,0xA9,0xBD);

/* Definition of interface: IEditElementaryAbstract */
DECLARE_INTERFACE_(IEditElementaryAbstract, IUnknown)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;
#endif

    /* IEditElementaryAbstract methods */
    STDMETHOD(SetCursorAtFirstNode)(THIS) PURE;
    STDMETHOD(SetCursorAtLastNode)(THIS) PURE;
    STDMETHOD(SetCursorAtPosition)(THIS_ ULONG p_Position) PURE;
    STDMETHOD(SetCursorAt)(THIS_ IAbstractNode FAR* p_NodeIn) PURE;
    STDMETHOD(AppendNode)(THIS_ IAbstractNode FAR* p_NodeIn) PURE;
    STDMETHOD(InsertNodeAtCursor)(THIS_ IAbstractNode FAR* p_NodeIn) PURE;
    STDMETHOD(InsertNodeAtPosition)(THIS_ IAbstractNode FAR* p_NodeIn, ULONG p_Position) PURE;
    STDMETHOD(RemoveNode)(THIS_ IAbstractNode FAR* p_NodeIn) PURE;
    STDMETHOD(RemoveNodeAtCursor)(THIS_ IAbstractNode FAR* FAR* p_NodeOut) PURE;
    STDMETHOD(RemoveNodeAtPosition)(THIS_ ULONG p_Position, IAbstractNode FAR* FAR* p_NodeOut) PURE;
    STDMETHOD(GetFirstNode)(THIS_ IAbstractNode FAR* FAR* p_NodeOut) PURE;
    STDMETHOD(GetNextOfCurrentPosition)(THIS_ IAbstractNode FAR* FAR* p_NodeOut) PURE;
    STDMETHOD(GetNextOfNode)(THIS_ IAbstractNode FAR* p_NodeIn, IAbstractNode FAR* FAR* p_NodeOut) PURE;
    STDMETHOD(GetPreviousOfCurrentPosition)(THIS_ IAbstractNode FAR* FAR* p_NodeOut) PURE;
    STDMETHOD(GetPreviousOfNode)(THIS_ IAbstractNode FAR* p_NodeIn, IAbstractNode FAR* FAR* p_NodeOut) PURE;
    STDMETHOD(GetLastNode)(THIS_ IAbstractNode FAR* FAR* p_NodeOut) PURE;
    STDMETHOD(GetCurrentPosition)(THIS_ IAbstractNode FAR* FAR* p_NodeOut) PURE;
    STDMETHOD(GetNodeAtPosition)(THIS_ ULONG p_Position, IAbstractNode FAR* FAR* p_NodeOut) PURE;
    STDMETHOD(GetNumberOfNode)(THIS_ ULONG FAR* Nbr) PURE;
};

typedef IEditElementaryAbstract FAR* LPEDITELEMENTARYABSTRACT;

DEFINE_GUID(IID_IEditIndexAbstract,0x06CB8EC0,0xAE0B,0x11CE,0xB9,0x79,0x83,0x8A,0x92,0xD8,0xA9,0xBD);

/* Definition of interface: IEditIndexAbstract */
DECLARE_INTERFACE_(IEditIndexAbstract, IUnknown)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;
#endif

    /* IEditIndexAbstract methods */
    STDMETHOD(SetCursorAtFirstNode)(THIS) PURE;
    STDMETHOD(SetCursorAtLastNode)(THIS) PURE;
    STDMETHOD(SetCursorAt)(THIS_ IAbstractNode FAR* p_NodeIn) PURE;
    STDMETHOD(InsertNode)(THIS_ IAbstractNode FAR* p_NodeIn) PURE;
    STDMETHOD(RemoveNode)(THIS_ IAbstractNode FAR* p_NodeIn) PURE;
    STDMETHOD(RemoveNodeAtCursor)(THIS_ IAbstractNode FAR* FAR* p_NodeOut) PURE;
    STDMETHOD(GetFirstNode)(THIS_ IAbstractNode FAR* FAR* p_NodeOut) PURE;
    STDMETHOD(GetNextOfCurrentPosition)(THIS_ IAbstractNode FAR* FAR* p_NodeOut) PURE;
    STDMETHOD(GetNextOfNode)(THIS_ IAbstractNode FAR* p_NodeIn, IAbstractNode FAR* FAR* p_NodeOut) PURE;
    STDMETHOD(GetPreviousOfCurrentPosition)(THIS_ IAbstractNode FAR* FAR* p_NodeOut) PURE;
    STDMETHOD(GetPreviousOfNode)(THIS_ IAbstractNode FAR* p_NodeIn, IAbstractNode FAR* FAR* p_NodeOut) PURE;
    STDMETHOD(GetLastNode)(THIS_ IAbstractNode FAR* FAR* p_NodeOut) PURE;
    STDMETHOD(GetCurrentPosition)(THIS_ IAbstractNode FAR* FAR* p_NodeOut) PURE;
    STDMETHOD(GetNodeWithKey)(THIS_ LPVOID p_Key, IAbstractNode FAR* FAR* p_NodeOut) PURE;
    STDMETHOD(GetNumberOfNode)(THIS_ ULONG FAR* Nbr) PURE;
};

typedef IEditIndexAbstract FAR* LPEDITINDEXABSTRACT;

DEFINE_GUID(IID_IBoundaryRectangle,0x547DA321,0xC764,0x11CE,0xA1,0xEC,0x44,0x45,0x53,0x54,0x00,0x00);

/* Definition of interface: IBoundaryRectangle */
DECLARE_INTERFACE_(IBoundaryRectangle, IUnknown)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;
#endif

    /* IBoundaryRectangle methods */
    STDMETHOD(Set)(THIS_ int Height, int Width, int XPos, int YPos) PURE;
    STDMETHOD(Get)(THIS_ int FAR* Height, int FAR* Width, int FAR* Xpos, int FAR* YPos) PURE;
    STDMETHOD(IsInside)(THIS_ int XPos, int YPos) PURE;
};

typedef IBoundaryRectangle FAR* LPBOUNDARYRECTANGLE;

DEFINE_GUID(IID_IName,0x5E2BA224,0xCF0F,0x11CE,0xA1,0xEC,0x44,0x45,0x53,0x54,0x00,0x00);

/* Definition of interface: IName */
DECLARE_INTERFACE_(IName, IUnknown)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;
#endif

    /* IName methods */
    STDMETHOD(SetNameOf)(THIS_ LPCTSTR Name) PURE;
    STDMETHOD(GetDisplayNameOf)(THIS_ LPCTSTR Name) PURE;
};

typedef IName FAR* LPNAME;

DEFINE_GUID(IID_IRectangleCollection,0x5E2BA227,0xCF0F,0x11CE,0xA1,0xEC,0x44,0x45,0x53,0x54,0x00,0x00);

/* Definition of interface: IRectangleCollection */
DECLARE_INTERFACE_(IRectangleCollection, IUnknown)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;
#endif

    /* IRectangleCollection methods */
    STDMETHOD(New)(THIS_ LPBOUNDRECT FAR* pBoundRect, int index, LPUNKNOWN pInterface) PURE;
    STDMETHOD(Find)(THIS_ int XPos, int YPos, LPABSTRACTNODE pNode, LPUNKNOWN pinterface) PURE;
    STDMETHOD(Remove)(THIS_ LPABSTRACTNODE pNode) PURE;
};

typedef IRectangleCollection FAR* LPRECTANGLECOLLECTION;

DEFINE_GUID(IID_IComponentFactory,0x522EAF22,0xCB4B,0x11CE,0xA1,0xEC,0x44,0x45,0x53,0x54,0x00,0x00);

/* Definition of interface: IComponentFactory */
DECLARE_INTERFACE_(IComponentFactory, IUnknown)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;
#endif

    /* IComponentFactory methods */
    STDMETHOD(Create)(THIS_ LPVOID CreationStructure) PURE;
    STDMETHOD(Destroy)(THIS) PURE;
};

typedef IComponentFactory FAR* LPCOMPONENTFACTORY;

DEFINE_GUID(IID_IUserEvent,0x547DA322,0xC764,0x11CE,0xA1,0xEC,0x44,0x45,0x53,0x54,0x00,0x00);

/* Definition of interface: IUserEvent */
DECLARE_INTERFACE_(IUserEvent, IUnknown)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;
#endif

    /* IUserEvent methods */
    STDMETHOD(SetMode)(THIS_ CURSOR CursorMode, int XPos, int YPos) PURE;
    STDMETHOD(MouseMove)(THIS_ int XPos, int YPos) PURE;
};

typedef IUserEvent FAR* LPUSEREVENT;

DEFINE_GUID(IID_IWindow,0x522EAF20,0xCB4B,0x11CE,0xA1,0xEC,0x44,0x45,0x53,0x54,0x00,0x00);

/* Definition of interface: IWindow */
DECLARE_INTERFACE_(IWindow, IBoundaryRectangle)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IBoundaryRectangle methods */
    STDMETHOD(Set)(THIS_ int Height, int Width, int XPos, int YPos) PURE;
    STDMETHOD(Get)(THIS_ int FAR* Height, int FAR* Width, int FAR* Xpos, int FAR* YPos) PURE;
    STDMETHOD(IsInside)(THIS_ int XPos, int YPos) PURE;
#endif

    /* IWindow methods */
    STDMETHOD(show)(THIS) PURE;
    STDMETHOD(Hide)(THIS) PURE;
};

typedef IWindow FAR* LPWINDOW;

DEFINE_GUID(IID_ICompositeSurface,0x2B4EDED4,0xBB8D,0x11CE,0xA2,0xAC,0x52,0x41,0x53,0x48,0x00,0x01);

/* Definition of interface: ICompositeSurface */
DECLARE_INTERFACE_(ICompositeSurface, ISurface)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* ISurface methods */
    STDMETHOD(GetSurfaceBits)(THIS_ LPDIB FAR* ppDIB) PURE;
    STDMETHOD(GetColorKey)(THIS_ COLORREF FAR* KeyColor) PURE;
#endif

    /* ICompositeSurface methods */
    STDMETHOD(TransBitBlt)(THIS_ LPSURFACE pSurfaceSrc, int Xdest, int Ydest) PURE;
    STDMETHOD(OpaqueBitBlt)(THIS_ LPSURFACE pSurfaceSrc, int Xdest, int Ydest) PURE;
    STDMETHOD(GhostBitBlt)(THIS_ LPSURFACE pSurfaceSrc, int Xdest, int Ydest, int level) PURE;
    STDMETHOD(InvalidateSurface)(THIS_ LPBOUNDRECT pDirtyRect) PURE;
};

typedef ICompositeSurface FAR* LPCOMPOSITESURFACE;

DEFINE_GUID(IID_IOffscreenSurface,0x2B4EDED5,0xBB8D,0x11CE,0xA2,0xAC,0x52,0x41,0x53,0x48,0x00,0x01);

/* Definition of interface: IOffscreenSurface */
DECLARE_INTERFACE_(IOffscreenSurface, ISurface)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* ISurface methods */
    STDMETHOD(GetSurfaceBits)(THIS_ LPDIB FAR* ppDIB) PURE;
    STDMETHOD(GetColorKey)(THIS_ COLORREF FAR* KeyColor) PURE;
#endif

    /* IOffscreenSurface methods */
    STDMETHOD(GetWinGDC)(THIS_ HDC FAR* pdc) PURE;
    STDMETHOD(IsInside)(THIS_ int x, int y, BOOL FAR* Inside) PURE;
    STDMETHOD(MapToPalette)(THIS_ HPALETTE hPalette) PURE;
    STDMETHOD(SetColorKey)(THIS_ COLORREF KeyColor) PURE;
};

typedef IOffscreenSurface FAR* LPOFFSCREENSURFACE;

DEFINE_GUID(IID_IFlippableSurface,0x2B4EDED6,0xBB8D,0x11CE,0xA2,0xAC,0x52,0x41,0x53,0x48,0x00,0x01);

/* Definition of interface: IFlippableSurface */
DECLARE_INTERFACE_(IFlippableSurface, ICompositeSurface)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* ISurface methods */
    STDMETHOD(GetSurfaceBits)(THIS_ LPDIB FAR* ppDIB) PURE;
    STDMETHOD(GetColorKey)(THIS_ COLORREF FAR* KeyColor) PURE;

    /* ICompositeSurface methods */
    STDMETHOD(TransBitBlt)(THIS_ LPSURFACE pSurfaceSrc, int Xdest, int Ydest) PURE;
    STDMETHOD(OpaqueBitBlt)(THIS_ LPSURFACE pSurfaceSrc, int Xdest, int Ydest) PURE;
    STDMETHOD(GhostBitBlt)(THIS_ LPSURFACE pSurfaceSrc, int Xdest, int Ydest, int level) PURE;
    STDMETHOD(InvalidateSurface)(THIS_ LPBOUNDRECT pDirtyRect) PURE;
#endif

    /* IFlippableSurface methods */
    STDMETHOD(Flip)(THIS_ LPBOUNDRECT pDirtyRect) PURE;
    STDMETHOD(Lock)(THIS) PURE;
    STDMETHOD(Unlock)(THIS) PURE;
    STDMETHOD(GetPalette)(THIS_ HPALETTE FAR* phPalette) PURE;
};

typedef IFlippableSurface FAR* LPFLIPPABLESURFACE;

#endif