/**
 * \file Explosion.cpp
 *
 * \author Justin Vesche
 */

#include "pch.h"
#include "Explosion.h"

/**
* explosion consturctor
* \param game the whole game
*/
CExplosion::CExplosion(CGame* game) : CWeapon(game)
{
}

/**
 * Update function, if explosion has been detonated, subtract time from mTimeDetonated
 * \param elapsed Time since the class call
 */
void CExplosion::Update(double elapsed)
{
	if (mDetonated)
	{
		mTimeDetonated -= elapsed;
	}
}


