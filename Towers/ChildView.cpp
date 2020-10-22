/**
 * \file ChildView.cpp
 *
 * \author Ian Masterson
 */


// ChildView.cpp : implementation of the CChildView class
//

#include "pch.h"
#include "framework.h"
#include "Towers.h"
#include "ChildView.h"
#include "DoubleBufferDC.h"
#include "TowerEight.h"
#include "BombTower.h"
#include "RingTower.h"
#include "GoButton.h"
#include "Menu.h"
#include "Scoreboard.h"

using namespace Gdiplus;
#ifdef _DEBUG
#define new DEBUG_NEW
#endif


/// Frame duration in milliseconds
const int FrameDuration = 30;

/// Maximum amount of time to allow for elapsed
const double MaxElapsed = 0.050;

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
	ON_WM_TIMER()
	ON_WM_LBUTTONUP()
	ON_WM_LBUTTONDOWN()
	ON_WM_MOUSEMOVE()
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



/**
 * This function is called to draw in the window.
 *
 * This function is called in response to a drawing message
 * whenever we need to redraw the window on the screen.
 * It is responsible for painting the window.
 */
void CChildView::OnPaint() 
{
	if (mFirstDraw)
	{
		mFirstDraw = false;
		SetTimer(1, FrameDuration, nullptr);

		/*
		 * Initialize the elapsed time system
		 */
		LARGE_INTEGER time, freq;
		QueryPerformanceCounter(&time);
		QueryPerformanceFrequency(&freq);

		mLastTime = time.QuadPart;
		mTimeFreq = double(freq.QuadPart);
	}

	/*
	 * Compute the elapsed time since the last draw
	 */
	LARGE_INTEGER time;
	QueryPerformanceCounter(&time);
	long long diff = time.QuadPart - mLastTime;
	double elapsed = double(diff) / mTimeFreq;
	mLastTime = time.QuadPart;

	//
	// Prevent tunnelling
	//
	while (elapsed > MaxElapsed)
	{
		mGame.Update(MaxElapsed);

		elapsed -= MaxElapsed;
	}

	// Consume any remaining time
	if (elapsed > 0)
	{
		mGame.Update(elapsed);
	}
	
	CPaintDC paintDC(this);
	CDoubleBufferDC dc(&paintDC); // device context for painting
	Graphics graphics(dc.m_hDC);
	

	CRect rect;
	GetClientRect(&rect);

	mGame.OnDraw(&graphics, rect.Width(), rect.Height());
	
}

/**
* On pushing Level 0 Button in menu level 0 loads
*/
void CChildView::OnLevelLevel0()
{
	mGame.Load(L"level0.xml");
	std::shared_ptr<CTowerEight> tower(new CTowerEight(&mGame));
	tower->SetLocation(400, 350);
	mGame.Add(tower);
	std::shared_ptr<CTowerEight> tower2(new CTowerEight(&mGame));
	tower2->SetLocation(225, 425);
	mGame.Add(tower2);
	std::shared_ptr<CRingTower> tower3(new CRingTower(&mGame));
	tower3->SetLocation(500, 400);
	mGame.Add(tower3);
	std::shared_ptr<CBombTower> tower4(new CBombTower(&mGame, 3));
	tower4->SetLocation(80, 520);
	mGame.Add(tower4);

	Invalidate();
}


/**
* On pushing Level 1 Button in menu level 1 loads
*/
void CChildView::OnLevelLevel1()
{
	mGame.Load(L"level1.xml");
	Invalidate();
}


/**
* On pushing Level 2 Button in menu level 2 loads
*/
void CChildView::OnLevelLevel2()
{
	mGame.Load(L"level2.xml");
	Invalidate();
}


/**
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


/**
 * Handle timer events
 * \param nIDEvent The timer event ID
 */
void CChildView::OnTimer(UINT_PTR nIDEvent)
{
	Invalidate();
	CWnd::OnTimer(nIDEvent);
}

/**
 * Called when the left mouse button is released
 * \param nFlags Flags associated with the mouse button release
 * \param point Where the button was pressed
 */
void CChildView::OnLButtonUp(UINT nFlags, CPoint point)
{
	mGame.OnLButtonUp(nFlags, point);

	CWnd::OnLButtonUp(nFlags, point);
}

/**
 * Called when there is a left mouse button press
 * \param nFlags Flags associated with the mouse button press
 * \param point Where the button was pressed
*/
void CChildView::OnLButtonDown(UINT nFlags, CPoint point)
{
	mGame.OnLButtonDown(nFlags, point);

	CWnd::OnLButtonDown(nFlags, point);
}

/**
 * Called when the mouse is moved
 * \param nFlags Flags associated with the mouse movement
 * \param point Where the button was pressed
 */
void CChildView::OnMouseMove(UINT nFlags, CPoint point)
{
	mGame.OnMouseMove(nFlags, point);

	CWnd::OnMouseMove(nFlags, point);
}
