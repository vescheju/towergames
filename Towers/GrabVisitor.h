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

/* Is the grabbed item a tower */
class CGrabVisitor :
    public CItemVisitor
{
public:

    virtual void VisitBombTower(CBombTower* bomb) override;

    virtual void VisitTowerEight(CTowerEight* tower) override;

    virtual void VisitRingTower(CRingTower* tower) override;

    /* Getter returns mIsTower memmber
    * \return boolean of whether or not we've visited tower
    */
    bool IsTower() const { return mIsTower; }

private:

    bool mIsTower = false;          ///< Boolean value represents if visited CItem is a CTower
};


