#include "pch.h"
#include "BombTower.h"
#include <string>

const std::wstring BombTowerName = L"images/tower-bomb.png";

CBombTower::CBombTower(CGame* game) :
	CTower(game, BombTowerName)
{
}

/**
std::shared_ptr<xmlnode::CXmlNode>
CBombTower::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
}
*/