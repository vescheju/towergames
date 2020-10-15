#include "pch.h"
#include "BombTower.h"
#include <string>

const std::wstring bombTowerName = L"images/tower-bomb.png";

CBombTower::CBombTower(CGame* game) :
	CTower(game)
{
	SetImage(bombTowerName);
}

