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

using namespace Gdiplus;

/**
 * Menu constructor
 * \param game The game this menu is a part of
 */
CGameMenu::CGameMenu(CGame* game) : CItem(game)
{
	std::shared_ptr<CRingTower> ringtower(new CRingTower(game));
	mRing = ringtower;
	ringtower->SetLocation(1200, 600);
	game->Add(ringtower);

	/**
	std::shared_ptr<CBombTower> bombtower(new CBombTower(game));
	mBomb = bombtower;
	bombtower->SetLocation(1100, 500);
	game->Add(bombtower);
	*/

	std::shared_ptr<CTowerEight> eighttower(new CTowerEight(game));
	mEight = eighttower;
	eighttower->SetLocation(1200, 400);
	game->Add(eighttower);

	/**
	std::shared_ptr<CGoButton> gobutton(new CGoButton(game));
	mGoButton = gobutton;
	gobutton->SetLocation(1200, 900);
	game->Add(gobutton);
	*/
	
}


/**
 * Destructor
 */
CGameMenu::~CGameMenu()
{
}

/**
* draw boundary for Menu
* \param graphics item to be drawn
*/
void CGameMenu::Draw(Gdiplus::Graphics* graphics)
{
	Pen pen(Color(255, 0, 0), 3);
	graphics->DrawRectangle(&pen, 1020, 0, 800, 1020);
}

void CGameMenu::SetLocation(double x, double y)
{
	CItem::SetLocation(x, y);
}