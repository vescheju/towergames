/**
 * \file Menu.cpp
 *
 * \author Julius Eillya
 */

#include "pch.h"
#include "Menu.h"
#include "Game.h"
#include "Item.h"
#include "RingTower.h"
#include "BombTower.h"
#include "TowerEight.h"
#include "GoButton.h"
#include "GoVisitor.h"

#include <sstream>

using namespace Gdiplus;
using namespace std;

/**
 * Menu constructor
 * \param game The game this menu is a part of
 */
CGameMenu::CGameMenu(CGame* game) : CItem(game)
{
	
	std::shared_ptr<CRingTower> ringtower(new CRingTower(game));
	mRing = ringtower;
	ringtower->SetLocation(1170, 600);

	
	std::shared_ptr<CBombTower> bombtower(new CBombTower(game));
	mBomb = bombtower;
	bombtower->SetLocation(1170, 500);
	

	std::shared_ptr<CTowerEight> eighttower(new CTowerEight(game));
	mEight = eighttower;
	eighttower->SetLocation(1170, 400);

	
	std::shared_ptr<CGoButton> gobutton(new CGoButton(game));
	mGoButton = gobutton;
	gobutton->SetLocation(1170, 900);
}


/**
 * Destructor
 */
CGameMenu::~CGameMenu()
{
}

/**
* draw boundary for Menu
* add scoreboard text
* \param graphics item to be drawn
*/
void CGameMenu::Draw(Gdiplus::Graphics* graphics)
{
	SolidBrush brush(Color(0, 0, 0));
	graphics->FillRectangle(&brush, 1024, 0, 200, 1024);

	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily,	24);
	SolidBrush green(Color(0, 200, 0));

	wstringstream str;
	str << mGame->GetScore();

	graphics->DrawString(L"Score: ", -1,
		&font, PointF(1100, 100), &green);
	graphics->DrawString(str.str().c_str(), -1,
		&font, PointF(1150, 150), &green);


	Gdiplus::Font levelFont(&fontFamily, 100);
	SolidBrush brown(Color(139, 69, 19));

	
	mRing->Draw(graphics);
	mBomb->Draw(graphics);
	mEight->Draw(graphics);

	

	if (mTimeSec < 2)
	{
		if (mGame->GetGameLevel() == 0)
		{
			graphics->DrawString(L"Level 0 Begin", -1, &levelFont, PointF(100, 450), &brown);
		}
		else if (mGame->GetGameLevel() == 1)
		{
			graphics->DrawString(L"Level 1 Begin", -1, &levelFont, PointF(100, 450), &brown);
		}
		else if (mGame->GetGameLevel() == 2)
		{
			graphics->DrawString(L"Level 2 Begin", -1, &levelFont, PointF(100, 450), &brown);
		}
		else
		{
			graphics->DrawString(L"Level 3 Begin", -1, &levelFont, PointF(100, 450), &brown);
		}
	}
	else if (mTimeSec > 2 && !mGame->GetButtonPressed())
	{
		mGoButton->Draw(graphics);
	}

	

}

/** set location of menu
	* \param x location of item along x axis
	* \param y location of item along y axis
	*/
void CGameMenu::SetLocation(double x, double y)
{
	CItem::SetLocation(x, y);
}


/// Handle updates for animation
/// \param elapsed The time since the last update
void CGameMenu::Update(double elapsed)
{
	mTimeSec += elapsed;

	if (!mGame->GetButtonPressed())
	{
		mGoButton->Update(elapsed);
	}
}


/**
 * sees if an element of the menu was clicked on
 * \param x the x coordinate
 * \param y the y coordinate
 * \returns nullptr if nothing was clicked on or the clicked object
 */
shared_ptr<CTower> CGameMenu::MenuHitTest(int x, int y)
{
	if (mRing->HitTest(x, y)) 
	{
		std::shared_ptr<CRingTower> tower(new CRingTower(mGame));
		return tower;
	}
	else if (mEight->HitTest(x, y)) 
	{
		std::shared_ptr<CTowerEight> tower(new CTowerEight(mGame));
		return tower;
	}
	else if (mBomb->HitTest(x, y))
	{
		std::shared_ptr<CBombTower> tower(new CBombTower(mGame));
		return tower;
	}
	else if (mGoButton->HitTest(x, y))
	{
		mGame->SetButtonPressed(true);
		CGoVisitor visitor;
		mGame->Accept(&visitor);
		return nullptr;
	}
	else
	{
		return nullptr;
	}
}