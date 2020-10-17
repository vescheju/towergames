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
 * returns the neighbor of the road in a certain direction
 * \param direction the direction of the neighbor
 * \returns a pointer to the neighbor
 */
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

