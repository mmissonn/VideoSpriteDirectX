/* This header file machine-generated by mktyplib.exe */
/* Interface to type library: OLEInterfaces */

#ifndef _OLEInterfaces_H_
#define _OLEInterfaces_H_

DEFINE_GUID(LIBID_OLEInterfaces,0xA4D78B20,0x6E05,0x1069,0x87,0x58,0x08,0x00,0x2B,0x2B,0xD6,0x4F);

DEFINE_GUID(IID_IClassFactory,0x990BA900,0xF45E,0x11CD,0x8C,0x3D,0x00,0xAA,0x00,0x4A,0xB3,0xB7);

/* Definition of interface: IClassFactory */
DECLARE_INTERFACE_(IClassFactory, IUnknown)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;
#endif

    /* IClassFactory methods */
    STDMETHOD(CreateInstance)(THIS_ LPUNKNOWN pUnkOuter, REFIID riid, LPVOID FAR* ppv) PURE;
    STDMETHOD(LockServer)(THIS_ BOOL fLock) PURE;
};

DEFINE_GUID(IID_IPersist,0x0000010C,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);

/* Definition of interface: IPersist */
DECLARE_INTERFACE_(IPersist, IUnknown)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;
#endif

    /* IPersist methods */
    STDMETHOD(GetClassID)(THIS_ LPCLSID pclsid) PURE;
};

DEFINE_GUID(IID_IPersistStream,0x00000109,0x0000,0x0000,0xC0,0x00,0x00,0x00,0x00,0x00,0x00,0x46);

/* Definition of interface: IPersistStream */
DECLARE_INTERFACE_(IPersistStream, IPersist)
{
#ifndef NO_BASEINTERFACE_FUNCS

    /* IUnknown methods */
    STDMETHOD(QueryInterface)(THIS_ REFIID riid, LPVOID FAR* ppvObj) PURE;
    STDMETHOD_(ULONG, AddRef)(THIS) PURE;
    STDMETHOD_(ULONG, Release)(THIS) PURE;

    /* IPersist methods */
    STDMETHOD(GetClassID)(THIS_ LPCLSID pclsid) PURE;
#endif

    /* IPersistStream methods */
    STDMETHOD(IsDirty)(THIS) PURE;
    STDMETHOD(Load)(THIS_ LPSTREAM pStm) PURE;
    STDMETHOD(Save)(THIS_ LPSTREAM pStm, BOOL fClearDirty) PURE;
    STDMETHOD(GetSizeMax)(THIS_ ULARGE_INTEGER FAR* pcbSize) PURE;
};

#endif
