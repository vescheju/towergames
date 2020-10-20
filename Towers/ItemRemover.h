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

class CItemRemover :
    public CItemVisitor
{
public:
    virtual void VisitBalloonRed(CBalloonRed* balloon) override;

    /**
    * getter fot mRemovedItems
    *
    * \return the items that need to be removed
    */
    std::vector<CItem*>& GetRemovedItems() { return mRemovedItems; }
private:
    std::vector<CItem*> mRemovedItems; //< holds the items that need to be removed
};
