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
