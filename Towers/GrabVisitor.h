/**
 * \file GrabVisitor.h
 *
 * \author Zach Arnold
 *
 * Visitor that is used to set mGrabbedItem to CTower object
 */

#pragma once
#include "ItemVisitor.h"
#include "Tower.h"

#include <vector>


/**
 * Is the grabbed item a tower
 */
class CGrabVisitor :
    public CItemVisitor
{
public:

    virtual void VisitRedBombTower(CRedBombTower* bomb) override;

    virtual void VisitPumpkinTower(CPumpkinTower* bomb) override;

    virtual void VisitTowerEight(CTowerEight* tower) override;

    virtual void VisitRingTower(CRingTower* tower) override;

    /** Getter returns mTowers memmber
    * \return vector of towers colleceted
    */
    std::vector<CTower*> GetTowers() const { return mTowers; }

private:

    std::vector<CTower*> mTowers;          ///< Vector of towers collected

};


