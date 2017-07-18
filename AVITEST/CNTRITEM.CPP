// cntritem.cpp : implementation of the CAVITestCntrItem class
//

#include "stdafx.h"
#include "AVITest.h"

#include "AVITedoc.h"
#include "cntritem.h"

#ifdef _DEBUG
#undef THIS_FILE
static char BASED_CODE THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////
// CAVITestCntrItem implementation

IMPLEMENT_SERIAL(CAVITestCntrItem, COleClientItem, 0)

CAVITestCntrItem::CAVITestCntrItem(CAVITestDoc* pContainer)
	: COleClientItem(pContainer)
{
	// TODO: add one-time construction code here
	
}

CAVITestCntrItem::~CAVITestCntrItem()
{
	// TODO: add cleanup code here
	
}

void CAVITestCntrItem::OnChange(OLE_NOTIFICATION nCode, DWORD dwParam)
{
	ASSERT_VALID(this);

	COleClientItem::OnChange(nCode, dwParam);

	// When an item is being edited (either in-place or fully open)
	//  it sends OnChange notifications for changes in the state of the
	//  item or visual appearance of its content.

	// TODO: invalidate the item by calling UpdateAllViews
	//  (with hints appropriate to your application)

	GetDocument()->UpdateAllViews(NULL);
		// for now just update ALL views/no hints
}

BOOL CAVITestCntrItem::OnChangeItemPosition(const CRect& rectPos)
{
	ASSERT_VALID(this);

	// During in-place activation CAVITestCntrItem::OnChangeItemPosition
	//  is called by the server to change the position of the in-place
	//  window.  Usually, this is a result of the data in the server
	//  document changing such that the extent has changed or as a result
	//  of in-place resizing.
	//
	// The default here is to call the base class, which will call
	//  COleClientItem::SetItemRects to move the item
	//  to the new position.

	if (!COleClientItem::OnChangeItemPosition(rectPos))
		return FALSE;

	// TODO: update any cache you may have of the item's rectangle/extent

	return TRUE;
}

void CAVITestCntrItem::OnGetItemPosition(CRect& rPosition)
{
	ASSERT_VALID(this);

	// During in-place activation, CAVITestCntrItem::OnGetItemPosition
	//  will be called to determine the location of this item.  The default
	//  implementation created from AppWizard simply returns a hard-coded
	//  rectangle.  Usually, this rectangle would reflect the current
	//  position of the item relative to the view used for activation.
	//  You can obtain the view by calling CAVITestCntrItem::GetActiveView.

	// TODO: return correct rectangle (in pixels) in rPosition

	rPosition.SetRect(10, 10, 210, 210);
}

void CAVITestCntrItem::OnDeactivateUI(BOOL bUndoable)
{
	COleClientItem::OnDeactivateUI(bUndoable);

	// Close an in-place active item whenever it removes the user
	//  interface.  The action here should match as closely as possible
	//  to the handling of the escape key in the view.

	Deactivate();   // nothing fancy here -- just deactivate the object
}

void CAVITestCntrItem::Serialize(CArchive& ar)
{
	ASSERT_VALID(this);

	// Call base class first to read in COleClientItem data.
	// Since this sets up the m_pDocument pointer returned from
	//  CAVITestCntrItem::GetDocument, it is a good idea to call
	//  the base class Serialize first.
	COleClientItem::Serialize(ar);

	// now store/retrieve data specific to CAVITestCntrItem
	if (ar.IsStoring())
	{
		// TODO: add storing code here
	}
	else
	{
		// TODO: add loading code here
	}
}

/////////////////////////////////////////////////////////////////////////////
// CAVITestCntrItem diagnostics

#ifdef _DEBUG
void CAVITestCntrItem::AssertValid() const
{
	COleClientItem::AssertValid();
}

void CAVITestCntrItem::Dump(CDumpContext& dc) const
{
	COleClientItem::Dump(dc);
}
#endif

/////////////////////////////////////////////////////////////////////////////
