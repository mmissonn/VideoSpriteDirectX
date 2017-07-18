// AVITedoc.h : interface of the CAVITestDoc class
//
/////////////////////////////////////////////////////////////////////////////

class CAVITestDoc : public COleDocument
{
protected: // create from serialization only
	CAVITestDoc();
	DECLARE_DYNCREATE(CAVITestDoc)

// Attributes
public:

// Operations
public:

// Overrides
	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAVITestDoc)
	public:
	virtual BOOL OnNewDocument();
	//}}AFX_VIRTUAL

// Implementation
public:
	virtual ~CAVITestDoc();
	virtual void Serialize(CArchive& ar);   // overridden for document i/o
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	//{{AFX_MSG(CAVITestDoc)
	afx_msg void OnCreateavi();
	afx_msg void OnReadavi();
	//}}AFX_MSG
	DECLARE_MESSAGE_MAP()

	// Generated OLE dispatch map functions
	//{{AFX_DISPATCH(CAVITestDoc)
		// NOTE - the ClassWizard will add and remove member functions here.
		//    DO NOT EDIT what you see in these blocks of generated code !
	//}}AFX_DISPATCH
	DECLARE_DISPATCH_MAP()
};

/////////////////////////////////////////////////////////////////////////////
