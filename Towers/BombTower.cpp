/**
 * \file BombTower.cpp
 *
 * \author Hithesh Yedlapati
 */

#include "pch.h"
#include "BombTower.h"
#include "Game.h"
#include "Explosion.h"
#include <string>


/**
* Bomb Tower constructor
* \param game the whole game
*/
CBombTower::CBombTower(CGame* game) : CTower(game)
{
}


/**
 * Update function, explodes if Fire attribute is true
 * \param elapsed Time since the class call
 */
void CBombTower::Update(double elapsed)
{
	if (mGame->GetButtonPressed())
	{
		// Update time till exploding
		UpdateTimeTillFire(elapsed);
		if (GetFire())
		{
			AddWeapon();
			// Fire explosion, set detonated to true for cleanup
			mExplosion->Detonate();
			mDetonated = true;
			SetFire(false);
		}
	}
}
