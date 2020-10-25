/**
 * \file GoVisitor.h
 *
 * \author Zach Arnold
 *
 * Visitor that initializes bomb detonation times
 * once Go button is pressed
 */

#pragma once

#include "ItemVisitor.h"
#include<vector>

class CTower;


 /**
  * Sets bomb detonation times
  */
class CGoVisitor :
    public CItemVisitor
{
public:

    virtual void VisitBombTower(CBombTower* bomb) override;

    virtual void VisitTowerEight(CTowerEight* bomb) override;

    virtual void VisitRingTower(CRingTower* bomb) override;

    std::vector<CTower*> GetTowers() const { return mTowers; }

private:

    double mDetonateTime = 3;           ///< Time until detonate for bomb visited

    std::vector<CTower*> mTowers;

};

