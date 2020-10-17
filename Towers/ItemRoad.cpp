/**
 * \file ItemRoad.cpp
 *
 * \author Julius Eillya
 */

#include "pch.h"
#include "ItemRoad.h"

using namespace std;


/**
 * Constructor
 * \param game The game the item is a part of
 */
CItemRoad::CItemRoad(CGame* game) : CItem(game) 
{

}

/**
 * Destructor
 */
CItemRoad::~CItemRoad()
{
}


/**
 * This is the road class version that loads the attributes common
 * to all road items
 * \param declNode The decleration for a single object
 * \param itemNode The node that is now labeled
 */
void CItemRoad::XmlLoad(const std::shared_ptr<xmlnode::CXmlNode>& declNode,
    const std::shared_ptr<xmlnode::CXmlNode>& itemNode)
{
    CItem::XmlLoad(declNode, itemNode);
    mRoadDirection = declNode->GetAttributeValue(L"type", L"");
}

CItemRoad* CItemRoad::GetNeighbor(wstring direction) 
{
    if (direction == L"N")
    {
        return mNorth;
    }
    else if (direction == L"E")
    {
        return mEast;
    }
    else if (direction == L"S")
    {
        return mSouth;
    }
    else if (direction == L"W")
    {
        return mWest;
    }
    
    return nullptr;
}

