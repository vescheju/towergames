/**
 * \file ItemRemover.h
 *
 * \author Ian Masterson
 *
 * removes items from a list that meet a certain criteria
 */

#pragma once
#include "ItemVisitor.h"
#include "Item.h"
#include<vector>


/**
 * A class that removes items
 */
class CItemRemover :
    public CItemVisitor
{
public:
    virtual void VisitBalloonRed(CBalloonRed* balloon) override;

    virtual void VisitExplosion(CExplosion* explosion) override;

    virtual void VisitBombTower(CBombTower* bomb) override;

    virtual void VisitBalloonBoss(CBalloonBoss* balloon) override;

    virtual void VisitTowerEight(CTowerEight* tower) override;

    virtual void VisitRingTower(CRingTower* tower) override;

    virtual void VisitFog(CItemFog* fog) override;
    /**
    * getter fot mRemovedItems
    *
    * \return the items that need to be removed
    */
    std::vector<CItem*>& GetRemovedItems() { return mRemovedItems; }

    /**
    * Returns the change of score
    *
    * \return the score change
    */
	int GetScoreChange() { return mScoreChange; };

private:
    std::vector<CItem*> mRemovedItems; ///< holds the items that need to be removed

    /// the net change in the score
	int mScoreChange = 0;
};

