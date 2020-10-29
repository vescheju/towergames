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

const int PointX = 100;
const int PointY = 450;
const int PointYOffset = 200;
const int PointXOffset = -55;

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

	// Load level 3 text image
	mLevel3StartText = unique_ptr<Bitmap>(Bitmap::FromFile(L"images/level3start.png"));
	if (mLevel3StartText->GetLastStatus() != Ok)
	{
		AfxMessageBox(L"Failed to open images/level3start.png");
	}
	mLevel3EndText = unique_ptr<Bitmap>(Bitmap::FromFile(L"images/level3end.png"));
	if (mLevel3StartText->GetLastStatus() != Ok)
	{
		AfxMessageBox(L"Failed to open images/level3end.png");
	}
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

	FontFamily fontFamily(L"Arial");
	Gdiplus::Font font(&fontFamily,	38, FontStyleBold, UnitPixel);
	SolidBrush green(Color(0, 200, 0));

	wstringstream str;
	str << mGame->GetScore();

	graphics->DrawString(L"Score: ", -1,
		&font, PointF(1100, 100), &green);
	graphics->DrawString(str.str().c_str(), -1,
		&font, PointF(1150, 150), &green);


	Gdiplus::Font levelFont(&fontFamily, 100, FontStyleBold, UnitPixel);
	SolidBrush brown(Color(139, 69, 19));

	
	mRing->Draw(graphics);
	mBomb->Draw(graphics);
	mEight->Draw(graphics);

	
	// Draws each game level text
	if (mTimeSec < 2)
	{
		if (mGame->GetGameLevel() == 0)
		{
			graphics->DrawString(L"Level 0 Begin", -1, &levelFont, PointF(PointX - PointXOffset, PointY), &brown);
		}
		else if (mGame->GetGameLevel() == 1)
		{
			graphics->DrawString(L"Level 1 Begin", -1, &levelFont, PointF(PointX - PointXOffset, PointY), &brown);
		}
		else if (mGame->GetGameLevel() == 2)
		{
			graphics->DrawString(L"Level 2 Begin", -1, &levelFont, PointF(PointX - PointXOffset, PointY), &brown);
		}
		else
		{
			// Custom level 3 text
			if (mLevel3StartText != nullptr)
			{
				double wid = mLevel3StartText->GetWidth();
				double hit = mLevel3StartText->GetHeight();
				graphics->DrawImage(mLevel3StartText.get(),
					PointX, PointY - PointYOffset,
					mLevel3StartText->GetWidth(), mLevel3StartText->GetHeight());
			}
			else 
			{
				graphics->DrawString(L"Level 3 Begin", -1, &levelFont, PointF(PointX - PointXOffset, PointY), &brown);
			}
		}
	}
	else if (mTimeSec > 2 && !mGame->GetButtonPressed())
	{
		mGoButton->Draw(graphics);
	}
	// Displays the level complete
	if (mGame->GetDisplayEnd())
	{

		if (mTimeFreeze <= 0.00001 && mTimeFreeze >= -0.00001)
		{
			mTimeFreeze = mTimeSec;
		}
	
		if (mTimeSec - mTimeFreeze < 2)
		{
			// custom level complete image
			if (mLevel3EndText != nullptr && mGame->GetGameLevel() == 3)
			{
				double wid = mLevel3EndText->GetWidth();
				double hit = mLevel3EndText->GetHeight();
				graphics->DrawImage(mLevel3EndText.get(),
					PointX - 20, PointY - PointYOffset,
					mLevel3EndText->GetWidth(), mLevel3EndText->GetHeight());
			}
			else 
			{
				graphics->DrawString(L"Level Complete", -1, &levelFont, PointF(PointX - PointXOffset, PointY), &brown);
			}
			
		}
		else 
		{
			mEndGame = true;
			mTimeFreeze = 0;
		}
	}
	else
	{
		mEndGame = false;
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
shared_ptr<CTower> CGameMenu::MenuHitTest(double x, double y)
{
	if (mRing->HitTest(x, y)) 
	{
		std::shared_ptr<CRingTower> tower = std::make_shared<CRingTower>(mGame);
		return tower;
	}
	else if (mEight->HitTest(x, y)) 
	{
		std::shared_ptr<CTowerEight> tower = std::make_shared<CTowerEight>(mGame);
		return tower;
	}
	else if (mBomb->HitTest(x, y))
	{
		std::shared_ptr<CBombTower> tower = std::make_shared<CBombTower>(mGame);
		return tower;
	}
	else if (mGoButton->HitTest(x, y))
	{
		CGoVisitor visitor;
		mGame->Accept(&visitor);
		visitor.AddWeapons();
		mGame->TowersToFrontOfScreen(visitor.GetTowers());
		mGame->SetButtonPressed(true);
		return nullptr;
	}
	else
	{
		return nullptr;
	}
}