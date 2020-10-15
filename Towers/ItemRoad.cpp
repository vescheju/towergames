/**
 * \file ItemRoad.cpp
 *
 * \author Julius Eillya
 */

#include "pch.h"
#include "ItemRoad.h"

using namespace std;

CItemRoad::CItemRoad(CGame* game) : CItem(game) 
{

}

/**
 * Destructor
 */
CItemRoad::~CItemRoad()
{
}

void CItemRoad::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& declNode,
    const std::shared_ptr<xmlnode::CXmlNode>& itemNode)
{
    CItem::XmlLoad(declNode, itemNode);
    mRoadDirection = declNode->GetAttributeValue(L"type", L"");
}

