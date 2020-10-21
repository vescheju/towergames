/**
 * \file Tower.cpp
 *
 * \author Hithesh Yedlapati
 */

#include "pch.h"
#include "Tower.h"
#include "Game.h"
#include <string>

class CGame;

/// Time between each firing
double TimeBetweenShots = 5;

/**
* Tower Constructor
* \param game the whole game
*/
CTower::CTower(CGame* game) : CItem(game)
{
}


/**
 * Updates the time till fire given elapsed period of time
 * \param elapsed double representing time elapsed in seconds
 */
void CTower::UpdateTimeTillFire(double elapsed)
{
	// calculate time until next fire
	mTimeTillFire -= elapsed;
	if (mTimeTillFire <= 0)
	{
		// if it's time to fire, reset timer and set fire attribute to true
		mTimeTillFire += TimeBetweenShots;
		mFire = true;
	}
}


