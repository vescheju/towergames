/**
 * \file VisibilityUpdater.h
 *
 * \author Ian Masterson
 *
 * updates the visibility if the red balloons in the level
 */

#pragma once
#include<vector>
#include "ItemVisitor.h"


/**
 * Class updates red balloon visibility
 */
class CVisibilityUpdater :
    public CItemVisitor
{
public:
    virtual void VisitBalloonRed(CBalloonRed* balloon) override;
    virtual void VisitBalloonBoss(CBalloonBoss* balloon) override;
    virtual void VisitFog(CItemFog* fog) override;

    void UpdateVisibility();

private:
    /// collection of red balloons in the level
    std::vector<CBalloonRed*> mBalloons;

    /// pointer to the fog (nullptr if it doesnt exist)
    CItemFog* mFog = nullptr;

};

