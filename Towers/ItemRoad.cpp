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


/**
 * Sets the appropriate location pointers of this and road
 * if they are adjacent in the cardinal directions
 * \param road the road to try and set as the neighbor
 * \returns true if they were neighbors and set as so
 */
bool CItemRoad::SetNeighbor(CItemRoad* road)
{
    // convert the Roads location to the column row coordinate
    double rowThis = (GetY() - mTileLength / 2) / mTileLength;
    double colThis = (GetX() - mTileLength / 2) / mTileLength;

    // convert the potential neighbors location to column row coordinates
    double rowRoad = (road->GetY() - mTileLength / 2) / mTileLength;
    double colRoad = (road->GetX() - mTileLength / 2) / mTileLength;

    // make sure we arent comparing the same road
    //if (rowThis == rowRoad && colThis == colRoad) return false;
    
    if (fabs(rowThis - rowRoad) < DBL_EPSILON && fabs(colThis - colRoad) < DBL_EPSILON) return false;

    if (rowThis == rowRoad)
    {
        // they are in the same row
        if (abs(colThis - colRoad) == 1)
        {
            // they are neighbors
            if (colThis > colRoad) 
            {
                // road is west of this
                mWest = road;
            }
            else
            {
                // road is east of this
                mEast = road;
            }
            return true;
        }
    }
    else if (colThis == colRoad)
    {
        // they are in the same column
        if (abs(rowThis - rowRoad) == 1)
        {
            // they are neighbors
            if (rowThis > rowRoad)
            {
                // road is north of this
                mNorth = road;
            }
            else
            {
                // road is south of this
                mSouth = road;
            }
            return true;

        }

    }

    // they arent neighbors
    return false;
}

