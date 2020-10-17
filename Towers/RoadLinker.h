/**
 * \file RoadLinker.h
 *
 * \author Ian Masterson
 *
 * Class collects the roads present in the game into a vector
 */

#pragma once

#include <vector>
#include<memory>
#include "ItemVisitor.h"
#include "ItemRoad.h"

 /**
  * visitor class to collect the roads in the game
  */
class CRoadLinker :
    public CItemVisitor
{
private:
    /// vector containing all of the collected roads
    std::vector<CItemRoad*> mRoads;

public:
    
    virtual void VisitRoad(CItemRoad* road) override;

    void LinkRoads();

    /**
    * returns the roads collected
    * \return A reference to the vector of collected roads
    */
    std::vector<CItemRoad* >& GetRoads() { return mRoads; }
};

