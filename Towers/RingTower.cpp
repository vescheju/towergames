/**
 * \file RingTower.cpp
 *
 * \author Hithesh Yedlapati
 */

#include "pch.h"
#include "RingTower.h"
#include <string>

/// ring tower png file
const std::wstring ringTowerName = L"images/tower-rings.png";

/**
* Ring Tower constructor
* \param game the whole game
*/
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