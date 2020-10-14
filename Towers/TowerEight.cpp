#include "pch.h"
#include "TowerEight.h"
#include <string>

const std::wstring TowerEightName = L"images/tower8.png";

CTowerEight::CTowerEight(CGame* game) :
	CTower(game, TowerEightName)
{
}

/**
std::shared_ptr<xmlnode::CXmlNode>
CTowerEight::XmlSave(const std::shared_ptr<xmlnode::CXmlNode>& node)
{
}
*/