#include "pch.h"
#include "RingTower.h"
#include <string>

const std::wstring ringTowerName = L"images/tower-rings.png";

CRingTower::CRingTower(CGame* game) :
	CTower(game)
{
	SetImage(ringTowerName);
}

/**
std::shared_ptr<xmlnode::CXmlNode>
CRingTower::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
}
*/