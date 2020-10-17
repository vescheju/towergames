
// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "Towers.h"
#include "ChildView.h"
#include "DoubleBufferDC.h"

using namespace Gdiplus;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CChildView

CChildView::CChildView()
{
}

CChildView::~CChildView()
{
}


BEGIN_MESSAGE_MAP(CChildView, CWnd)
	ON_WM_PAINT()
	ON_COMMAND(ID_LEVEL_LEVEL0, &CChildView::OnLevelLevel0)
	ON_COMMAND(ID_LEVEL_LEVEL1, &CChildView::OnLevelLevel1)
	ON_COMMAND(ID_LEVEL_LEVEL2, &CChildView::OnLevelLevel2)
	ON_COMMAND(ID_LEVEL_LEVEL3, &CChildView::OnLevelLevel3)
	ON_WM_ERASEBKGND()
END_MESSAGE_MAP()



// CChildView message handlers

BOOL CChildView::PreCreateWindow(CREATESTRUCT& cs) 
{
	if (!CWnd::PreCreateWindow(cs))
		return FALSE;

	cs.dwExStyle |= WS_EX_CLIENTEDGE;
	cs.style &= ~WS_BORDER;
	cs.lpszClass = AfxRegisterWndClass(CS_HREDRAW|CS_VREDRAW|CS_DBLCLKS, 
		::LoadCursor(nullptr, IDC_ARROW), reinterpret_cast<HBRUSH>(COLOR_WINDOW+1), nullptr);

	return TRUE;
}

void CChildView::OnPaint() 
{
	CPaintDC paintDC(this);     // device context for painting
	CDoubleBufferDC dc(&paintDC); // device context for painting
	Graphics graphics(dc.m_hDC);    // Create GDI+ graphics context

	// TODO: Add your message handler code here
	
	// Do not call CWnd::OnPaint() for painting messages
	mGame.OnDraw(&graphics);

	Pen pen(Color(0, 128, 0), 3);
	// graphics.DrawEllipse(&pen, 100, 125, 400, 50);
}

/*
* On pushing Level 0 Button in menu level 0 loads
*/
void CChildView::OnLevelLevel0()
{
	mGame.Load(L"level0.xml");
	Invalidate();
}


/*
* On pushing Level 1 Button in menu level 1 loads
*/
void CChildView::OnLevelLevel1()
{
	mGame.Load(L"level1.xml");
	Invalidate();
}


/*
* On pushing Level 2 Button in menu level 2 loads
*/
void CChildView::OnLevelLevel2()
{
	mGame.Load(L"level2.xml");
	Invalidate();
}


/*
* On pushing Level 3 Button in menu level 3 loads
*/
void CChildView::OnLevelLevel3()
{
	mGame.Load(L"level3.xml");
	Invalidate();
}


/**
 * Erase the background
 *
 * This is disabled to eliminate flicker
 * \param pDC Device context
 * \returns FALSE
 */
BOOL CChildView::OnEraseBkgnd(CDC* pDC)
{
	return FALSE;
}
