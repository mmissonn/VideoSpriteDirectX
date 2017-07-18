// cntritem.h : interface of the CAVITestCntrItem class
//

class CAVITestDoc;
class CAVITestView;

class CAVITestCntrItem : public COleClientItem
{
	DECLARE_SERIAL(CAVITestCntrItem)

// Constructors
public:
	CAVITestCntrItem(CAVITestDoc* pContainer = NULL);
		// Note: pContainer is allowed to be NULL to enable IMPLEMENT_SERIALIZE.
		//  IMPLEMENT_SERIALIZE requires the class have a constructor with
		//  zero arguments.  Normally, OLE items are constructed with a
		//  non-NULL document pointer.

// Attributes
public:
	CAVITestDoc* GetDocument()
		{ return (CAVITestDoc*)COleClientItem::GetDocument(); }
	CAVITestView* GetActiveView()
		{ return (CAVITestView*)COleClientItem::GetActiveView(); }

	// ClassWizard generated virtual function overrides
	//{{AFX_VIRTUAL(CAVITestCntrItem)
	public:
	virtual void OnChange(OLE_NOTIFICATION wNotification, DWORD dwParam);
	protected:
	virtual void OnGetItemPosition(CRect& rPosition);
	virtual void OnDeactivateUI(BOOL bUndoable);
	virtual BOOL OnChangeItemPosition(const CRect& rectPos);
	//}}AFX_VIRTUAL

// Implementation
public:
	~CAVITestCntrItem();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif
	virtual void Serialize(CArchive& ar);
};

/////////////////////////////////////////////////////////////////////////////
