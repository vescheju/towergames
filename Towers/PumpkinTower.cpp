/**
 * \file PumpkinTower.cpp
 *
 * \author Zach Arnold
 */


#include "pch.h"
#include "PumpkinTower.h"
#include "Game.h"
#include "Explosion.h"

/// Duration of each pumpkin tick in seconds
const double TickDuration = 0.2;

/**
* Pumpkin Bomb Tower constructor
* \param game the whole game
*/
CPumpkinTower::CPumpkinTower(CGame* game) : CBombTower(game)
{
	SetImagePtr(mGame->GetImage(L"pumpkin-bomb.png"));
}


/**
* Update function, expends on bomb tower update
* changes image pointer to create ticking effect
* \param elapsed Time since the class call
*/
void CPumpkinTower::Update(double elapsed)
{
	// upcast update call
	CBombTower::Update(elapsed);
	// find time left till detonation
	double time = CTower::GetTimeTillFire();

	// if 3 seconds left
	if (time <= 3)
	{
		// set light if in tick length window
		if (ceil(time) - time < TickDuration && !mLight)
		{
			SetImagePtr(mGame->GetImage(L"pumpkin-bomb-tick.png"));
			mLight = true;
		}
		// set light off if not in tick length window
		if (ceil(time) - time >= TickDuration && mLight)
		{
			SetImagePtr(mGame->GetImage(L"pumpkin-bomb.png"));
			mLight = false;
		}
	}
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
