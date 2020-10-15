#include "pch.h"
#include "TowerEight.h"
#include <string>

/// towerEight filename
const std::wstring towerEightName = L"images/tower8.png";

/**
* TowerEight Constructor
* \param game the whole game
*/
CTowerEight::CTowerEight(CGame* game) :
	CTower(game)
{
	SetImage(towerEightName);
}

/**
std::shared_ptr<xmlnode::CXmlNode>
CTowerEight::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
}
*/