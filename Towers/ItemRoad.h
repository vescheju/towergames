/**
 * \file ItemRoad.h
 *
 * \author Julius Eillya
 *
 * A class that implements a road item
 */


#pragma once

#include "Item.h"


/**
 * A road item
 */
class CItemRoad : public CItem
{
public:
    CItemRoad(CGame* game);

    ///  Default constructor (disabled)
    CItemRoad() = delete;

    ///  Copy constructor (disabled)
    CItemRoad(const CItemRoad&) = delete;

    ~CItemRoad();


    /**
    * Returns the directions this road has
    * 
    * \returns the direction
    */
    std::wstring GetRoadDirection() { return mRoadDirection; }

    /**
    * sets the directions this road has
    *
    * \param direction the direction
    */
    void SetRoadDirection(std::wstring direction) { mRoadDirection = direction; }

    CItemRoad* GetNeighbor(std::wstring direction);

private:
    std::wstring mRoadDirection;    ///< The direction the road is going

    /// pointer to the road north of this road, nullptr if no 
    /// road is present
    CItemRoad* mNorth = nullptr;
    /// pointer to the road east of this road, nullptr if no 
    /// road is present
    CItemRoad* mEast = nullptr;
    /// pointer to the road south of this road, nullptr if no 
    /// road is present
    CItemRoad* mSouth = nullptr;
    /// pointer to the road west of this road, nullptr if no 
    /// road is present
    CItemRoad* mWest = nullptr;

};

