/**
 * \file BombTower.cpp
 *
 * \author Hithesh Yedlapati
 */

#include "pch.h"
#include "BombTower.h"
#include <string>

/// bomb tower png file declaration
const std::wstring bombTowerName = L"images/tower-bomb.png";

/**
* Bomb Tower constructor
* \param game the whole game
*/
CBombTower::CBombTower(CGame* game) :
	CTower(game)
{
	SetImage(bombTowerName);
}

