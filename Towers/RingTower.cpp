#include "pch.h"
#include "RingTower.h"
#include <string>

const std::wstring RingTowerName = L"images/tower-rings.png";

CRingTower::CRingTower(CGame* game) :
	CTower(game, RingTowerName)
{
}

/**
std::shared_ptr<xmlnode::CXmlNode>
CRingTower::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
}
*/