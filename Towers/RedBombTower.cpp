/**
 * \file RedBombTower.cpp
 *
 * \author Zach Arnold
 */


#include "pch.h"
#include "RedBombTower.h"
#include "Game.h"
#include "Explosion.h"


/**
* Red Bomb Tower constructor
* \param game the whole game
*/
CRedBombTower::CRedBombTower(CGame* game) : CBombTower(game)
{
	SetImagePtr(mGame->GetImage(L"tower-bomb.png"));
}

/**
 * Initialize Weapon function, initializes explosion in Bomb
 */
void CRedBombTower::InitializeWeapon()
{
	std::shared_ptr<CExplosion> explosion = std::make_shared<CExplosion>(mGame);
	explosion->SetLocation(GetX(), GetY());
	mExplosion = explosion;
}


/**
* Add Weapon function, adds explosion to game mItemes
*/
void CRedBombTower::AddWeapon()
{
	mGame->Add(mExplosion);
}