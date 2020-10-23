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
    /**
    * getter fot mRemovedItems
    *
    * \return the items that need to be removed
    */
    std::vector<CItem*>& GetRemovedItems() { return mRemovedItems; }

	int GetScoreChange() { return mScoreChange; };

private:
    std::vector<CItem*> mRemovedItems; ///< holds the items that need to be removed
	int mScoreChange = 0;
};

