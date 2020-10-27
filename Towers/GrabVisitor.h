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

/* Is the grabbed item a tower */
class CGrabVisitor :
    public CItemVisitor
{
public:

    virtual void VisitBombTower(CBombTower* bomb) override;

    virtual void VisitTowerEight(CTowerEight* tower) override;

    virtual void VisitRingTower(CRingTower* tower) override;

    /* Getter returns mTowers memmber
    * \return vector of towers colleceted
    */
    std::vector<CTower*> GetTowers() const { return mTowers; }

private:

    std::vector<CTower*> mTowers;          ///< Boolean value represents if visited CItem is a CTower
};


