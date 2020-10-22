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

/// bomb tower png file declaration
const std::wstring BombTowerName = L"images/tower-bomb.png";

/**
* Bomb Tower constructor
* \param game the whole game
*/
CBombTower::CBombTower(CGame* game, double timeToDetonate) : CTower(game)
{
	SetImage(BombTowerName);
	SetTimeTillFire(timeToDetonate);
	std::shared_ptr<CExplosion> explosion(new CExplosion(game));
	mExplosion = explosion;
	game->Add(explosion);
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
			// Fire explosion, set detonated to true for cleanup
			mExplosion->Detonate();
			mDetonated = true;
			SetFire(false);
		}
	}
	
}

/**
* Set's location of Tower and its explosion
* \param x X coordinate to set Tower and explosion at
* \param y Y coordinate to set Tower and explosion at
 */
void CBombTower::SetLocation(double x, double y)
{
	CItem::SetLocation(x, y);
	// set locations of ring with tower
	mExplosion->SetLocation(x, y);
}
