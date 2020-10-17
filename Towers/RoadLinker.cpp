/**
 * \file RoadLinker.cpp
 *
 * \author Ian Masterson
 */

#include "pch.h"
#include "RoadLinker.h"

 /**
      * Visit a CItemRoad object and add it to the 
      * mRoads vector
      * \param road Road item we are visiting
      */
void CRoadLinker::VisitRoad(CItemRoad* road)
{
    mRoads.push_back(road);
}

/**
 * iterates through the road class and links roads based off of their location
 */
void CRoadLinker::LinkRoads()
{
    // iterate through the roads
    for (int i = 0; i < static_cast<int>(mRoads.size()); ++i)
    {
        // the road to compare to the other roads in the vector
        CItemRoad* road = mRoads[i];
        // iterate through the rest of the roads
        for (int j = 0; j < static_cast<int>(mRoads.size()); ++j)
        {
            road->SetNeighbor(mRoads[j]);
        }
    }
}