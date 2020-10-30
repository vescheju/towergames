/**
 * \file PumpkinTower.cpp
 *
 * \author Zach Arnold
 */


#include "pch.h"
#include "PumpkinTower.h"
#include "Game.h"
#include "Explosion.h"


/**
* Pumpkin Bomb Tower constructor
* \param game the whole game
*/
CPumpkinTower::CPumpkinTower(CGame* game) : CBombTower(game)
{
	SetImagePtr(mGame->GetImage(L"pumpkin-bomb.png"));
}


/**
 * Initialize Weapon function, initializes explosion in Bomb
 */
void CPumpkinTower::InitializeWeapon()
{
	std::shared_ptr<CExplosion> explosion = std::make_shared<CExplosion>(mGame);
	explosion->SetLocation(GetX(), GetY());
	mExplosion = explosion;
}


/**
* Add Weapon function, adds explosion to game mItemes
*/
void CPumpkinTower::AddWeapon()
{
	mGame->Add(mExplosion);
}
